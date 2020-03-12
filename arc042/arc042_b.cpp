#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<int, int> P;
const ll INF = 1e15;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;


#define EPS 1e-7

bool equal(double f1, double f2) {
    return abs(f1 - f2) < EPS;
}

struct Vec {

    double x, y;

    double size() {
        return sqrt(x * x + y * y);
    }

    double inner_product(Vec v2) {
        return x * v2.x + y * v2.y;
    }

    Vec product(double rate) {
        Vec v2;
        v2.x = x * rate;
        v2.y = y * rate;
        return v2;
    }
};


struct Point {
    double x, y;

    Point plus(Vec vec) {
        Point p;
        p.x = x + vec.x;
        p.y = y + vec.y;
        return p;
    }

    Point minus(Point sub) {
        Point p;
        p.x = x - sub.x;
        p.y = y - sub.y;
        return p;
    }


    friend istream &operator>>(istream &is, Point &f) {
        cin >> f.x >> f.y;
        return is;
    }

    friend ostream &operator<<(std::ostream &os, Point const &f) {
        printf("%.20f %.20f\n", f.x, f.y);
        return os;
    }
};

struct Line {
    Point start, end;

    Vec to_vec() {
        Vec vec;
        vec.x = end.x - start.x;
        vec.y = end.y - start.y;
        return vec;
    }

    friend istream &operator>>(istream &is, Line &f) {
        cin >> f.start >> f.end;
        return is;
    }

    Line normalize() {
        Line l;
        l.start = {0, 0};
        l.end = end.minus(start);
        return l;
    }

    double atan2() {
        Line l = normalize();
        return std::atan2(l.end.y, l.end.x);
    }

    double rad(Line line) {
        double f1 = atan2(),
                f2 = line.atan2();

        double diff = f1 - f2;
        if (equal(diff, -PI)) {
            return PI;
        }
        if (equal(diff, PI)) {
            return PI;
        }
        if (diff < -PI) {
            diff += (PI * 2);
        }
        if (diff > PI) {
            diff -= (PI * 2);
        }

        return diff;
    }

    void clock_wise(Line line) {

        double diff = rad(line);

        if (equal(line.to_vec().size(), 0)) {
            cout << "ON_SEGMENT" << endl;
            return;
        }

        if (equal(diff, 0)) {
            double s1 = to_vec().size();
            double s2 = line.to_vec().size();

            if (s1 > s2 || equal(s1, s2)) {
                cout << "ON_SEGMENT" << endl;
            } else {
                cout << "ONLINE_FRONT" << endl;
            }
        } else if (equal(abs(diff), PI)) {
            cout << "ONLINE_BACK" << endl;
        } else if (diff < 0) {
            cout << "COUNTER_CLOCKWISE" << endl;
        } else {
            cout << "CLOCKWISE" << endl;
        }
    }

    static const int COUNTER_CLOCKWISE = 1;
    static const int CLOCKWISE = -1;
    static const int ONLINE_BACK = 2;   // p2->p0->p1
    static const int ONLINE_FRONT = -2; // p0->p1->p2
    static const int ON_SEGMENT = 0;    // p0->p2->p1

    double dot(Point a, Point b) {
        return a.x * b.x + a.y * b.y;
    }

    double cross(Point a, Point b) {
        return a.x * b.y - a.y * b.x;
    }

    double norm(Point a) {
        return a.x * a.x + a.y * a.y;
    }

    int ccw(Point p0, Point p1, Point p2) {
        Point a = p1.minus(p0);
        Point b = p2.minus(p0);
        if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
        if (cross(a, b) < -EPS) return CLOCKWISE;
        if (dot(a, b) < -EPS) return ONLINE_BACK;
        if (norm(a) < norm(b)) return ONLINE_FRONT;
        return ON_SEGMENT;
    }

    bool intersect(Point p1, Point p2, Point p3, Point p4) {
        return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
                ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
    }

    bool intersect(Line s1) {
        return intersect(start, end, s1.start, s1.end);
    }

    /*
     * function min_d2(x0, y0, x1, y1, x2, y2) {
  var a = x2 - x1;
  var b = y2 - y1;
  var a2 = a * a;
  var b2 = b * b;
  var r2 = a2 + b2;
  var tt = -(a*(x1-x0)+b*(y1-y0));
  if( tt < 0 ) {
    return (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0);
  }
  if( tt > r2 ) {
    return (x2-x0)*(x2-x0) + (y2-y0)*(y2-y0);
  }
  var f1 = a*(y1-y0)-b*(x1-x0);
  return (f1*f1)/r2;
}
     */

    double distance(double x0, double y0) {
        double x1 = start.x;
        double y1 = start.y;
        double x2 = end.x;
        double y2 = end.y;

        double a = x2 - x1;
        double b = y2 - y1;
        double a2 = a * a;
        double b2 = b * b;
        double r2 = a2 + b2;
        double tt = -(a * (x1 - x0) + b * (y1 - y0));
        if (tt < 0) {
            return (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
        }
        if (tt > r2) {
            return (x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0);
        }
        double f1 = a * (y1 - y0) - b * (x1 - x0);
        double d = (f1 * f1) / r2;
        return sqrt(d);
    }

};

int main() {
    double x, y;
    int n;
    cin >> x >> y >> n;
    vector<Point> points(n);
    rep(i, n) cin >> points[i];


    vector<Line> lines(n);
    rep(i, n) lines[i].start = points[i];
    rep(i, n) lines[i].end = points[(i + 1) % n];


    double ans = 10e10;
    for (Line l : lines) {
        double d = l.distance(x, y);
        cmin(ans, d);
    }
    printf("%.20f\n", ans);

}
