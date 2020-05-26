#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

ll gcd(ll x, ll y) {
    if (x > y) swap(x, y);
    ll m = 1;
    while (m != 0) {
        m = y % x;
        y = x;
        x = m;
    }
    return y;
}

template<class T, class F>
struct SegmentTree {
    F f;
    T ti;
    vector<T> dat;
    int sz;

    SegmentTree(const F &f, const T &ti) : f(f), ti(ti) {}

    void build(const vector<T> &v) {
        assert(v.size());
        sz = 1;
        while (sz < v.size())sz <<= 1;
        dat.resize(sz << 1, ti);
        for (int i = 0; i < v.size(); i++)dat[sz - 1 + i] = v[i];
        for (int i = sz - 2; i >= 0; i--)dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
    }

    inline void update(int k, T x) {
        k += sz - 1;
        dat[k] = x;
        while (k) {
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    inline void add(int k, int x) {
        k += sz - 1;
        dat[k] = f(dat[k], x);
        while (k) {
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    inline T query(int a, int b) {
        return query(a, b, 0, 0, sz);
    }

    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)return ti;
        if (a <= l && r <= b)return dat[k];
        return f(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};


int main() {

    int n;
    cin >> n;

    vector<ll> machines(n);
    rep(i, n) cin >> machines[i];


    auto fgcd = [](ll i, ll j) {
        if (i == -1) return j;
        if (j == -1) return i;
        if (i == 0) return j;
        if (j == 0) return i;
        return gcd(abs(i), abs(j));
    };
    SegmentTree<ll, decltype(fgcd)> segmentTreeDeltaGcd(fgcd, -1);
    vector<ll> delta(n - 1);
    rep(i, n - 1) delta[i] = machines[i] - machines[i + 1];
    segmentTreeDeltaGcd.build(delta);

    auto print = [&] {
        rep(i, n) printf(" %3lld", machines[i]);
        cout << endl;
        rep(i, n - 1) printf(" %3lld", segmentTreeDeltaGcd.query(i, i + 1));
        cout << endl;
    };

//    print();
    int m;
    cin >> m;
    rep(_, m) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        r--;

//        cout << t << ' ' << l << ' ' << r << endl;

        if (t == 0) {

            if (l == r) {
                cout << machines[l] << endl;
                continue;
            }
            ll qg = segmentTreeDeltaGcd.query(l, r + 1);
            if (qg == 0) {
                cout << machines[l] << endl;
                continue;
            }

            int g = gcd(machines[l], abs(qg));
            cout << g << endl;
        } else {
            segmentTreeDeltaGcd.update(l - 1, segmentTreeDeltaGcd.query(l - 1, l) - t);
            segmentTreeDeltaGcd.update(r, segmentTreeDeltaGcd.query(r, r + 1) + t);

            for (int i = l; i <= r; i++) {
                machines[i] += t;
            }

//            print();
        }
    }

}