#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

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


double combf(ll l, ll r, vector<double> &facts) {
    double la = facts[l];
    double lr = facts[l - r];
    double d = facts[r];

    return la - lr - d;

}

const double e = 2.7182818284590452;

int main() {
    int n;
    cin >> n;

    vector<P> checkpoints(n);
    rep(i, n) cin >> checkpoints[i].first >> checkpoints[i].second;

    vector<double> facts(pow(10, 7));
    facts[0] = 0;
    facts[1] = 0;
    rep(i, pow(10, 7)) {
        if (i <= 1) continue;
        facts[i] = facts[i - 1] + log(i);
    }


    auto af = [&](int i) -> double {
        ll h = abs(checkpoints[i].first - checkpoints[i + 1].first);
        ll w = abs(checkpoints[i].second - checkpoints[i + 1].second);
        if (h == 0 || w == 0) return 0.0;
        return combf(h + w, w, facts);
    };

    auto f = [](double i, double j) { return i + j; };
    SegmentTree<double, decltype(f)> segmentTree(f, 0.0);
    vector<double> imos;
    rep(i, n - 1) {
        imos.push_back(af(i));
    }

    segmentTree.build(imos);

    int q;
    cin >> q;
    rep(_, q) {
        int t;
        cin >> t;

        if (t == 1) {
            int k, a, b;
            cin >> k >> a >> b;
            k--;
            checkpoints[k] = P(a, b);

            for (int i = max(k - 1, 0); i < min(k + 1, n - 1); i++) {
                segmentTree.update(i, af(i));
            }

        } else {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;

            l1--;
            r1--;
            l2--;
            r2--;


            ll a = segmentTree.query(l1, r1);
            ll b = segmentTree.query(l2, r2);

            string ans = a > b ? "FIRST" : "SECOND";
            cout << ans << endl;
        }

    }

}
