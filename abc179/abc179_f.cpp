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

// 自分の前に縦が入ったらそれ以降の横は関係がない
// 自分の前に入った縦の中で、一番最初に入った縦を求める
// 自分の前に縦が入る前に一番高いところに入った横の高さが答え
ll solve(int n, int q, vector<P> v) {

    // segment tree

    auto f = [](ll i, ll j) { return min(i, j); };
    SegmentTree<ll, decltype(f)> vertical_index_segment_tree(f, INF);
    vertical_index_segment_tree.build(vector<ll>(n, INF));

    map<int, int> before_vertical_indexes; // [i] = i
    rep(i, q) {
        if (v[i].first == 2) continue;
        ll before_vertical_index = vertical_index_segment_tree.query(0, v[i].second);
        if (before_vertical_index == INF) {
            before_vertical_index = i;
        }

        before_vertical_indexes[i] = before_vertical_index;
        vertical_index_segment_tree.update(v[i].second, i);
    }


    // segment tree
    map<int, int> before_horizontal_height;// [i] = height
    {
        ll ma = n - 1;
        rep(i, q) {
            P p = v[i];
            if (p.first == 2) {
                cmin(ma, p.second);
            } else {
                before_horizontal_height[i] = ma;
            }
        }
    }

    ll sum = 0;
    rep(i, q) {
        P p = v[i];
        if (p.first == 2) continue;
        ll h = before_horizontal_height[before_vertical_indexes[i]];
        ll now = h - 1;
        sum += now;
    }

    return sum;
}

int main() {
    ll n, q;
    cin >> n >> q;

    vector<P> v(q);
    for (P &p:v) cin >> p.first >> p.second, p.first, p.second--;

    ll a = solve(n, q, v);
    for (P &p: v) p.first = p.first == 1 ? 2 : 1;
    ll b = solve(n, q, v);
    ll ans = (n - 2) * (n - 2) - (a + b);
    cout << ans << endl;

}
