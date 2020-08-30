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


class Conv {
    ll cursor = 0;
    map<ll, ll> to_short; // <original, small >
    map<ll, ll> to_long; // <small, original>
    std::set<ll> tmp;


public:
    void set(ll original) {
        if (to_short.find(original) != to_short.end()) {
            return;
        }
        to_long[cursor] = original;
        to_short[original] = cursor;
        cursor++;
    }

    ll revert(ll after) {
        assert(to_long.find(after) != to_long.end());
        return to_long[after];
    }

    ll convert(ll original) {
        assert(to_short.find(original) != to_short.end());
        return to_short[original];
    }

    ll next() {
        return cursor;
    }

    // 前計算省略のため
    void cache(ll t) {
        tmp.insert(t);
    }

    void build() {
        for (ll t : tmp) {
            set(t);
        }
    }

};


// 座標圧縮する
// 各高さの一番左にあるxを求める
// 各高さの伸張したときの長さを求める
// 各高さ以上の山の数を求める
// 掛け算する

vector<int> convert(Conv &conv, int n, vector<ll> &v) {
    vector<int> u(n);
    for (ll l : v) conv.cache(l);
    conv.build();
    rep(i, n) u[i] = conv.convert(v[i]);
    return u;
}

vector<ll> make_c_len(Conv &conv) {
    vector<ll> ans(conv.next());
    for (int i = 1; i < conv.next(); i++) {
        ans[i] = conv.revert(i) - conv.revert(i - 1);
    }
    return ans;
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


vector<ll> make_height_count(vector<int> &u, int n, int ma) {
    vector<vector<int>> t(ma);
    rep(i, n) t[u[i]].push_back(i);

    auto f = [](ll i, ll j) { return i + j; };
    SegmentTree<ll, decltype(f)> segmentTree(f, 0);
    segmentTree.build(vector<ll>(n, 0));

    vector<ll> ans(ma);

    for (int i = ma - 1; i >= 0; i--) {
        for (int j : t[i]) segmentTree.update(j, 1);
        int count = segmentTree.query(0, n);
        ans[i] = count;
    }

    return ans;

}

vector<ll> make_min_mountain(vector<int> &u, int n, int ma) {
    vector<vector<int>> t(ma);
    rep(i, n) t[u[i]].push_back(i);

    auto f = [](ll i, ll j) { return min(i, j); };
    SegmentTree<ll, decltype(f)> segmentTree(f, INF);
    segmentTree.build(vector<ll>(n, INF));

    vector<ll> ans(ma);

    for (int i = ma - 1; i >= 0; i--) {
        for (int j : t[i]) segmentTree.update(j, j);
        int count = segmentTree.query(0, n);
        ans[i] = count;
    }

    return ans;

}

vector<ll> make_ans(int n, int ma, vector<ll> &h_count, vector<ll> &c_len, vector<ll> &mi_mountain) {
    vector<ll> ans(n);
    for (int i = 1; i < ma; i++) {
        ll now = h_count[i] * c_len[i];
        int index = mi_mountain[i];
        ans[index] += now;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    Conv conv;
    conv.cache(0);
    vector<int> u = convert(conv, n, v);
    vector<ll> c_len = make_c_len(conv);

    vector<ll> h_count = make_height_count(u, n, conv.next());
    vector<ll> mi_mountain = make_min_mountain(u, n, conv.next());

    vector<ll> ans = make_ans(n, conv.next(), h_count, c_len, mi_mountain);

    for (ll l : ans) cout << l << endl;

}
