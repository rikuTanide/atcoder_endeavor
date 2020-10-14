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

class MatrixSum {
    vector<vector<ll>> sum;
    bool build_end = false;
public:
    MatrixSum(ll h, ll w) {
        sum = vector<vector<ll>>(h, vector<ll>(w));
    }

    void add(ll y, ll x, ll value) {
        assert(!build_end);
        sum[y][x] += value;
    }

    ll get(ll y, ll x) {
        assert(build_end);
        if (x == -1 || y == -1) {
            return 0;
        }
        if (y == sum.size() || x == sum[y].size()) {
            return 0;
        }
        return sum[y][x];
    }

    void setUp() {
        assert(!build_end);
        build_end = true;
        for (ll y = 0; y < sum.size(); y++) {
            for (ll x = 0; x < sum[y].size(); x++) {
                sum[y][x] += get(y - 1, x) + get(y, x - 1) - get(y - 1, x - 1);
            }
        }
    }

    ll getSum(ll ys, ll xs, ll ye, ll xe) {
        assert(build_end);
        return get(ye, xe) - get(ys - 1, xe) - get(ye, xs - 1) + get(ys - 1, xs - 1);
    }

};

struct Point {
    ll x1, y1, x2, y2;

};

class Conv {
    ll cursor = 0;
    map<ll, ll> to_short; // <original, small >
    map<ll, ll> to_long; // <small, original>
    std::set<ll> tmp;

    bool build_end = false;

    void set(ll original) {
        if (to_short.find(original) != to_short.end()) {
            return;
        }
        to_long[cursor] = original;
        to_short[original] = cursor;
        cursor++;
    }

public:


    ll revert(ll after) {
        assert(build_end);
        assert(to_long.find(after) != to_long.end());
        return to_long[after];
    }

    ll convert(ll original) {
        assert(build_end);
        assert(to_short.find(original) != to_short.end());
        return to_short[original];
    }

    ll next() {
        return cursor;
    }

    // 前計算省略のため
    void cache(ll t) {
        assert(!build_end);
        tmp.insert(t);
    }

    void build() {
        assert(!build_end);
        for (ll t : tmp) {
            set(t);
        }
        build_end = true;
    }

};

P solve(ll w, ll h, Conv &conv_x, Conv &conv_y, vector<Point> &points) {
    MatrixSum ms(w + 1, h + 1);
    for (Point &p : points) {
        ms.add(p.x1, p.y1, 1);
        ms.add(p.x1, p.y2 + 1, -1);
        ms.add(p.x2 + 1, p.y1, -1);
        ms.add(p.x2 + 1, p.y2 + 1, 1);
    }
    ms.setUp();

    ll a = 0;
    rep(x, w) {
        rep(y, h) {
            cmax(a, ms.get(x, y));
        }
    }

    ll b = 0;
    rep(x, w) {
        rep(y, h) {
            if (ms.get(x, y) == a) {
                ll wi = conv_x.revert(x + 1) - conv_x.revert(x);
                ll hi = conv_y.revert(y + 1) - conv_y.revert(y);
                ll now = wi * hi;
                b += now;
            }
        }
    }
    return P(a, b);
}

int main() {
    int n;
    ll w, h;
    cin >> n >> w >> h;

    vector<Point> points(n);
    for (Point &p: points) cin >> p.x1 >> p.y1 >> p.x2 >> p.y2;

    Conv conv_x, conv_y;
//    for (Point p : points) for (int i = -1; i <= 1; i++) conv_x.cache(p.x1 + i);
//    for (Point p : points) for (int i = -1; i <= 1; i++) conv_x.cache(p.x2 + i);
//    for (Point p : points) for (int i = -1; i <= 1; i++) conv_y.cache(p.y1 + i);
//    for (Point p : points) for (int i = -1; i <= 1; i++) conv_y.cache(p.y2 + i);

    for (Point p : points) conv_x.cache(p.x1), conv_x.cache(p.x1 - 1);
    for (Point p : points) conv_x.cache(p.x2), conv_x.cache(p.x2 + 1);
    for (Point p : points) conv_y.cache(p.y1), conv_y.cache(p.y1 - 1);
    for (Point p : points) conv_y.cache(p.y2), conv_y.cache(p.y2 + 1);

    conv_x.build();
    conv_y.build();

    for (Point &p : points) p.x1 = conv_x.convert(p.x1);
    for (Point &p : points) p.x2 = conv_x.convert(p.x2);
    for (Point &p : points) p.y1 = conv_y.convert(p.y1);
    for (Point &p : points) p.y2 = conv_y.convert(p.y2);

    P ans = solve(conv_x.next(), conv_y.next(), conv_x, conv_y, points);

    printf("%lld\n%lld\n", ans.first, ans.second);
}
