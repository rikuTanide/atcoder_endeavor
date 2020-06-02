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

class MatrixSum {
    vector<vector<ll>> sum;
public:
    MatrixSum(ll x, ll y) {
        sum = vector<vector<ll>>(x, vector<ll>(y));
    }

    void set(ll x, ll y, ll v) {
        sum[x][y] = v;
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
    int sx, ex, sy, ey;
};

int main() {

    int h, w;
    cin >> h >> w;

    MatrixSum ms(h, w);

    rep(y, h) rep(x, w) {
            ll v;
            cin >> v;
            ms.set(y, x, v);
        }
    ms.setUp();


    vector<Point> points;
    for (int sx = 0; sx < w; sx++) {
        for (int ex = sx; ex < w; ex++) {
            for (int sy = 0; sy < h; sy++) {
                for (int ey = sy; ey < h; ey++) {
                    Point p{sx, ex, sy, ey};
                    points.push_back(p);
                }
            }
        }
    }


    ll ans = -INF;
    for (Point p1 : points) {
        for (Point p2 : points) {

            int sx = max(p1.sx, p2.sx);
            int ex = min(p1.ex, p2.ex);
            int sy = max(p1.sy, p2.sy);
            int ey = min(p1.ey, p2.ey);

            if (sx <= ex && sy <= ey) continue;

            ll now1 = ms.getSum(p1.sy, p1.sx, p1.ey, p1.ex);
            ll now2 = ms.getSum(p2.sy, p2.sx, p2.ey, p2.ex);
            ll now = now1 + now2;
            cmax(ans, now);
        }
    }
    cout << ans << endl;
}