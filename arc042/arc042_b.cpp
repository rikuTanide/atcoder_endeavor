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
struct Point {
    double x;
    double y;
};

struct LineSegment {
    Point start;
    Point end;
};

/**
   @brief 線分と点の距離を計算する。
   @param line 線分
   @param point 点
   @return ユークリッド距離
 */
double calc_dist(const LineSegment &line, const Point &point) {
    double x0 = point.x, y0 = point.y;
    double x1 = line.start.x, y1 = line.start.y;
    double x2 = line.end.x, y2 = line.end.y;

    double a = x2 - x1;
    double b = y2 - y1;
    double a2 = a * a;
    double b2 = b * b;
    double r2 = a2 + b2;
    double tt = -(a * (x1 - x0) + b * (y1 - y0));

    if (tt < 0)
        return sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
    else if (tt > r2)
        return sqrt((x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0));

    double f1 = a * (y1 - y0) - b * (x1 - x0);
    return sqrt((f1 * f1) / r2);
}

int main() {
    Point p;
    cin >> p.x >> p.y;

    int n;
    cin >> n;
    vector<Point> points(n);
    rep(i, n) cin >> points[i].x >> points[i].y;

    vector<LineSegment> lines;
    rep(i, n) {
        Point p1 = points[i], p2 = points[(i + 1) % n];
        lines.push_back(LineSegment{p1, p2});
    }

    double ans = INF;
    for (LineSegment l : lines) {
        double now = calc_dist(l, p);
        cmin(ans, now);
    }

    printf("%.20f\n", ans);

}
