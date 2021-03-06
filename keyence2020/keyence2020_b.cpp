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


struct Robot {
    ll x, l;

    ll left() {
        return x - l + 1;
    }

    ll right() {
        return x + l ;
    }

};

std::istream &operator>>(std::istream &in, Robot &o) {
    in >> o.x >> o.l;
    return in;
}


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

struct Range {
    int l, r;
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


int main() {


//    ifstream cin("C:\\Users\\riku\\Downloads\\05.txt");
    int n;
    cin >> n;

    vector<Robot> robots(n);
    rep(i, n) cin >> robots[i];

    Conv conv;
    for (Robot r : robots) conv.cache(r.left()), conv.cache(r.right());
    conv.build();

    vector<Range> ranges(n);
    rep(i, n) ranges[i].l = conv.convert(robots[i].left());
    rep(i, n) ranges[i].r = conv.convert(robots[i].right());

    sort(ranges.begin(), ranges.end(), [](Range r1, Range r2) {
        return r1.r < r2.r;
    });

    auto f = [](ll i, ll j) { return max(i, j); };
    SegmentTree<ll, decltype(f)> segmentTree(f, 0);
    segmentTree.build(vector<ll>(conv.next(), 0));

    auto get = [&](int i) -> int {
        if (i == -1) return 0;
        return segmentTree.query(0, i + 1);
    };

    rep(i, n) {
        Range range = ranges[i];

        ll add = get(range.l - 1) + 1;
        ll pass = segmentTree.query(range.r, range.r + 1);

        ll next = max(add, pass);
        segmentTree.update(range.r, next);
//        rep(j, conv.next()) cout << segmentTree.query(j, j + 1) << ' ';
//        cout << endl;
    }

    cout << segmentTree.query(0, conv.next()) << endl;

}

