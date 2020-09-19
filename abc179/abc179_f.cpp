#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Query {
    ll orient, x;
};

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

ll solve(ll n, vector<Query> &queries) {

    auto f = [](ll i, ll j) { return min(i, j); };
    SegmentTree<ll, decltype(f)> segmentTree(f, INF);
    segmentTree.build(vector<ll>(n + 10, INF));

    vector<ll> lefts(n + 10, -1);

    rep(i, queries.size()) {
        Query q = queries[i];
        if (q.orient == 2) continue;
        ll first = segmentTree.query(0, q.x);
        if (first == INF) {
            segmentTree.update(q.x, i);
            lefts[q.x] = i;
        } else {
            segmentTree.update(q.x, first);
            lefts[q.x] = first;
        }
    }


    ll mi = n - 1;

    vector<ll> ups(n + 10, n - 1);
    ups[0] = n - 1;

    rep(i, queries.size()) {
        Query q = queries[i];
        if (q.orient == 1) continue;

        cmin(mi, q.x);
        ups[i] = mi;
    }
    rep(i, queries.size()) {
        if (i == 0) continue;
        if (ups[i] == -1) {
            ups[i] = ups[i - 1];
        }
    }

    ll sum = 0;
    rep(i, queries.size()) {
        Query q = queries[i];
        if (q.orient == 2) continue;

        int h = ups[lefts[q.x]] - 1;
        sum += h;
    }
    return sum;

}

int main() {
    ll n, q;
    cin >> n >> q;

    vector<Query> queries(q);
    for (Query &query:queries) cin >> query.orient >> query.x, query.x--;
    ll ans = (n - 2) * (n - 2);
    ll v = solve(n, queries);
    ans -= v;

    for (Query &q: queries) if (q.orient == 1) q.orient = 2; else q.orient = 1;
    ll h = solve(n, queries);
    ans -= h;

    cout << ans << endl;

}
