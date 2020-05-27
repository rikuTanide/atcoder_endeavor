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


typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

struct Point {
    double l, r;
};

double dig(double y, double x) {
    double now = atan2(y, x) / 2 / PI * 360;
    if (now < 0) now += 360;
    return now;
}

std::istream &operator>>(std::istream &in, Point &o) {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double l = dig(y1, x1);
    double r = dig(y2, x2);

    if (!(l > r)) swap(l, r);
    if (l - r > 180) {
        r += 360;
        swap(l, r);
    }

    o.l = l;
    o.r = r;

    return in;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    rep(i, n) cin >> points[i];


    sort(points.begin(), points.end(), [](Point p1, Point p2) {
        return p1.l < p2.l;
    });

    int ans = INT_MAX;

    rep(start, n) {
        vector<Point> v;
        rep(i, n) v.push_back(points[(i + start) % n]);
        rep(i, n) {
            if (i == 0) continue;
            if (v[i].l < points[start].l) {
                v[i].l += 360;
                v[i].r += 360;
            }
        }

        int now = 0;
        double l = v[0].r - 0.1, r = l - 0.1;

        for (Point p : v) {
            if (l >= p.r && r <= p.l) {
                cmin(l, p.l);
                cmax(r, p.r);
            } else {
                now++;
                l = p.l;
                r = p.r;
            }
        }

        cmin(ans, now);

    }

    cout << ans << endl;
}

