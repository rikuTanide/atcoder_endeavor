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
public:
    MatrixSum(ll x, ll y) {
        sum = vector<vector<ll>>(x, vector<ll>(y));
    }

    void add(ll x, ll y, ll value) {
        sum[x][y] += value;
    }

    ll get(ll x, ll y) {
        if (x == -1 || y == -1) {
            return 0;
        }
        if (x == sum.size() || y == sum[x].size()) {
            return 0;
        }
        return sum[x][y];
    }

    void setUp() {
        for (ll x = 0; x < sum.size(); x++) {
            for (ll y = 0; y < sum[x].size(); y++) {
                sum[x][y] += get(x - 1, y) + get(x, y - 1) - get(x - 1, y - 1);
            }
        }
    }

    ll getSum(ll xs, ll ys, ll xe, ll ye) {
        return get(xe, ye) - get(xs - 1, ye) - get(xe, ys - 1) + get(xs - 1, ys - 1);
    }

};

struct Point {
    int x1, y1, x2, y2;

};

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
                ll hi = conv_y.revert(y + 1) - conv_x.revert(y);
                ll now = wi * hi;
                b += now;
            }
        }
    }
    return P(a, b);
}

int main() {
    int n;
    int w, h;
    cin >> n >> w >> h;

    vector<Point> points(n);
    for (Point &p: points)cin >> p.x1 >> p.y1 >> p.x2 >> p.y2;
    for (Point &p: points) p.x1--;
    for (Point &p: points) p.y1--;
    for (Point &p: points) p.x2--;
    for (Point &p: points) p.y2--;

    Conv conv_x, conv_y;
    for (Point p : points) for (int i = -1; i <= 1; i++) conv_x.cache(p.x1 + i);
    for (Point p : points) for (int i = -1; i <= 1; i++) conv_x.cache(p.x2 + i);
    for (Point p : points) for (int i = -1; i <= 1; i++) conv_y.cache(p.y1 + i);
    for (Point p : points) for (int i = -1; i <= 1; i++) conv_y.cache(p.y2 + i);
    conv_x.build();
    conv_y.build();

    for (Point &p : points) p.x1 = conv_x.convert(p.x1);
    for (Point &p : points) p.x2 = conv_x.convert(p.x2);
    for (Point &p : points) p.y1 = conv_y.convert(p.y1);
    for (Point &p : points) p.y2 = conv_y.convert(p.y2);

    P ans = solve(conv_x.next(), conv_y.next(), conv_x, conv_y, points);

    printf("%d\n%d\n", ans.first, ans.second);
}
