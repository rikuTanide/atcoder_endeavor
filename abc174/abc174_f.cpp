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
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    rep(i, n) cin >> v[i], v[i]--;

    vector<vector<int>> positions(n);
    rep(i, n) {
        positions[v[i]].push_back(i);
    }


    auto f = [](ll i, ll j) { return i + j; };
    SegmentTree<ll, decltype(f)> segmentTree(f, 0);
    {
        vector<ll> imos(n + 10, 0);
        rep(i, n) {
            if (positions[i].empty()) continue;
            imos[positions[i].front()]++;
        }
        segmentTree.build(imos);
    }

    ll cursor = 0;

    vector<P> queries(q);
    for (P &p: queries) cin >> p.first >> p.second, p.first--, p.second--;

    vector<P> queries_asc = queries;
    sort(queries_asc.begin(), queries_asc.end());

    map<P, int> tmp;

    for (P p : queries_asc) {
        for (; cursor < p.first; cursor++) {
            int color = v[cursor];
            auto it = lower_bound(positions[color].begin(), positions[color].end(), p.first);
            if (it == positions[color].end()) continue;
            int t = *it;
            segmentTree.update(t, 1);
        }

        int now = segmentTree.query(p.first, p.second + 1);
        tmp[p] = now;
    }

    for (P p : queries) {
        cout << tmp[p] << endl;
    }


}
