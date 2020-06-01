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


vector<ll> bubble_sort(vector<ll> v) {
    int n = v.size();

    auto f = [](ll i, ll j) { return i + j; };
    SegmentTree<ll, decltype(f)> segmentTree(f, 0);
    vector<ll> u(n);
    segmentTree.build(u);

    vector<ll> inv(n);
    for (int i = n - 1; i >= 0; i--) {
        inv[v[i]] = segmentTree.query(0, v[i]);
        segmentTree.add(v[i], 1);
    }
    return inv;
}

vector<ll> bubble_sort2(vector<ll> v, int tts) {
    int n = v.size();
    for (int i = 0; i < (n - 1) && tts > 0; i++) {
        for (int j = n - 1; j > i; j--) {
            if (v[j] < v[j - 1]) {
                swap(v[j], v[j - 1]);
                tts--;
                if (tts == 0) break;
            }
        }
    }
    return v;
}

int main() {
    int n;
    cin >> n;

    assert(n <= 3000);

    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];


    map<ll, ll> m, ba;

    rep(i, n) m[a[i]] = i;
    rep(i, n) ba[i] = a[i];
    rep(i, n) a[i] = m[a[i]];
    rep(i, n) b[i] = m[b[i]];


    vector<ll> inv = bubble_sort(b);
    ll tts = accumulate(inv.begin(), inv.end(), 0ll);

    if (tts % 2 == 1) {
        cout << -1 << endl;
        ret();
    }

    vector<ll> ans = bubble_sort2(b, tts / 2);

    rep(i, n) ans[i] = ba[ans[i]];

    for (ll i : ans) cout << i << ' ';
    cout << endl;

}