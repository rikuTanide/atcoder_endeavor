#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

// https://atcoder.jp/contests/abc022/submissions/8900202
const double eps = 1e-9;

struct Point {
    double x, y;

    Point &operator-=(const Point &v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Point operator-(const Point &v) const { return Point(*this) -= v; }

    double cross(const Point &v) const { return x * v.y - v.x * y; }      /* 外積 */

};

int ccw(Point p0, Point p1, Point p2) {
    Point v1 = p1 - p0;
    Point v2 = p2 - p0;
    if (v1.cross(v2) > eps) return 1;
    if (v1.cross(v2) < -eps) return -1;
    return 0;
}

vector<Point> convex_hull(vector<Point> ps) {
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end(),
         [](const Point &a, const Point &b) { return a.y != b.y ? a.y < b.y : a.x < b.x; }
    );
    vector<Point> ch(2 * n);
    for (int i = 0; i < n; ch[k++] = ps[i++]) {  // lower-hull
        while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
    }
    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) { // upper-hull
        while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
    }
    ch.resize(k - 1);

    ch.push_back(ch[0]);

    return ch;
}

double calc_outer(vector<Point> &cosmos) {
    double ans = 0;

    rep(i, cosmos.size() - 1) {
        Point p = cosmos[i];
        Point q = cosmos[i + 1];

        ll x = p.x - q.x;
        ll y = p.y - q.y;

        ll xx = x * x;
        ll yy = y * y;
        ans += sqrt(xx + yy);
    }
    return ans;
}


int main() {
    int n;
    cin >> n;

    vector<Point> cosmos(n);
    rep(i, n) {
        cin >> cosmos[i].x;
        cin >> cosmos[i].y;
    }
    vector<Point> i_g = convex_hull(cosmos);

    vector<Point> cosmos2(n);
    rep(i, n) {
        cin >> cosmos2[i].x;
        cin >> cosmos2[i].y;
    }
    vector<Point> s_g = convex_hull(cosmos2);


    double i_o = calc_outer(i_g);
    double s_o = calc_outer(s_g);


    printf("%.20f\n", s_o / i_o);


}
