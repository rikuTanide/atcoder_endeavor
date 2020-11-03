//
//#pragma GCC target("avx")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#define NDEBUG

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
const ll INF = 1e18;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

bool equal(double a, double b) {
    return fabs(a - b) < EPS;
}

template<class T>
std::istream &operator>>(std::istream &in, set<T> &o) {
    T a;
    in >> a;
    o.insert(a);
    return in;
}

template<class T>
std::istream &operator>>(std::istream &in, queue<T> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Point {
    double x, y;

    friend std::istream &operator>>(std::istream &in, Point &p) {
        in >> p.x >> p.y;
        return in;
    }

    friend bool operator==(Point p1, Point p2) {
        return equal(p1.x, p2.x) && equal(p1.y, p2.y);
    }

    friend bool operator<(Point p1, Point p2) {
        if (!equal(p1.x, p2.x)) {
            return p1.x < p2.x;
        }
        return p1.y < p2.y;
    }

    friend std::ostream &operator<<(std::ostream &out, Point &p) {
        out << p.x << '-' << p.y;
        return out;
    }
};

struct Line {
    Point s, g;

    friend std::istream &operator>>(std::istream &in, Line &l) {
        cin >> l.s >> l.g;
        return in;
    }

    double slope() const {
        assert(!is_x());
        assert(!is_y());
        double y = g.y - s.y;
        double x = g.x - s.x;
        return y / x;
    }

    double slope_e() const {
        if (is_y()) return 0;
        if (is_x()) return INF;
        double y = g.y - s.y;
        double x = g.x - s.x;
        return y / x;
    }

    Point assign_x(double x) const {
        double y = slope() * x + intercept();
        return Point{x, y};
    }

    Point assign_y(double y) const {
        double x = (y - intercept()) / slope();
        return Point{x, y};
    }

    bool is_x() const {
        return equal(s.x, g.x);
    }

    bool is_y() const {
        return equal(s.y, g.y);
    }

    double intercept() const {

        assert(!is_x());
        assert(!is_y());


        double y1 = s.y;
        double y2 = g.y;
        double x1 = s.x;
        double x2 = g.x;

        return y1 - ((y2 - y1) / (x2 - x1)) * x1;
    }

    friend bool operator==(Line l1, Line l2) {
        if (l1.is_x() && l2.is_x()) {
            return l1.s.x == l2.s.x;
        }
        if (l1.is_y() && l2.is_y()) {
            return l1.s.y == l2.s.y;
        }
        if (!l1.is_x() && !l1.is_y() && !l2.is_x() && !l2.is_y()) {
            return equal(l1.slope(), l2.slope()) && equal(l1.intercept(), l2.intercept());
        }
        return false;
    }

    friend bool operator<(Line l1, Line l2) {
        return l1.slope_e() < l2.slope_e();
    }

};


bool is_intersection(const Line &l1, const Line &l2) {
    if (l1.is_x() && l2.is_x()) return false;
    if (l1.is_y() && l2.is_y()) return false;

    if (l1.is_x() || l2.is_x()) return true;
    if (l1.is_y() || l2.is_y()) return true;


    return !equal(l1.slope(), l2.slope());
}

Point calc_intersection_point(const Line &l1, const Line &l2) {
    if (l2.is_x()) return calc_intersection_point(l2, l1);
    if (l1.is_x()) {
        if (l2.is_y()) return Point{l1.s.x, l2.s.y};
        return l2.assign_x(l1.s.x);
    }
    if (l2.is_y()) return calc_intersection_point(l2, l1);
    if (l1.is_y()) return l2.assign_y(l1.s.y);

    // https://qiita.com/uyuutosa/items/8de1f7602cb14c29606f

    double a = l1.slope();
    double b = l1.intercept();

    double c = l2.slope();
    double d = l2.intercept();

    assert((a - c) != double(0));

    double x = (d - b) / (a - c);
    double y = (a * d - b * c) / (a - c);

    return Point{x, y};

}

int main2() {
    Line l1{Point{4, 11}, Point{2, 7}};
    Line l2{Point{3, 11}, Point{1, 1}};

    Point p = calc_intersection_point(l1, l2);
    cout << p << endl;

}

bool is_parallel(const Line &l1, const Line &l2) {
    if (l1.is_x() && l2.is_x()) return true;
    if (l1.is_y() && l2.is_y()) return true;

    if (l1.is_x() && !l2.is_x()) return false;
    if (l1.is_y() && !l2.is_y()) return false;

    if (!l1.is_x() && l2.is_x()) return false;
    if (!l1.is_y() && l2.is_y()) return false;

    double s1 = l1.slope();
    double s2 = l2.slope();

    return equal(s1, s2);
}

bool is_duplicate(const Line &l1, const Line &l2) {
    if (!is_parallel(l1, l2)) return false;

    if (l1.is_x() && !l2.is_x()) return false;
    if (l1.is_y() && !l2.is_y()) return false;

    if (!l1.is_x() && l2.is_x()) return false;
    if (!l1.is_y() && l2.is_y()) return false;

    if (l1.is_x() && l2.is_x()) {
        return equal(l1.s.x, l2.s.x);
    }

    if (l1.is_y() && l2.is_y()) {
        return equal(l1.s.y, l2.s.y);
    }

    double i1 = l1.intercept();
    double i2 = l2.intercept();

    return equal(i1, i2);

}

int main() {


    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    // 直線の傾きを計算する関数 分数 x軸と並行が0 y軸と並行がINF
    // ある直線がほかの直線と交差する座標一覧を作る

    int n;
    cin >> n;
    vector<Line> lines(n);
    rep(i, n) cin >> lines[i];
    sort(lines.begin(), lines.end());
    lines.erase(unique(lines.begin(), lines.end()), lines.end());
    n = lines.size();

//    sort(lines.begin(), lines.end(), [](Line l1, Line l2) {
//        return l1.slope_e() < l2.slope_e();
//    });
//
//    for (Line l : lines) {
//        cout << l.slope_e() << endl << "     " << l.s << ' ' << l.g << endl;
//    }
//
//    {
//        set<Line> lines;
//        rep(i, n) {
//            bool ok = [&] {
//                rep(j, tmp.size()) {
//                    if (is_duplicate(lines[i], tmp[j])) {
//                        return false;
//                    }
//                }
//                return true;
//            }();
//            if (ok) tmp.push_back(lines[i]);
//        }
//        lines = tmp;
//        n = lines.size();
//    }
//    cout << n << endl;
//    cout << endl;

    set<Point> unique_intersections;
    vector<int> intersection_count(n);
//    ll ans = 0;
    rep(i, n) {
//        cout << i + 1 << ' ';
        set<Point> st;
        rep(j, i) {
//            if (i == j) continue;
//            ans += lines[i].s.x.num + lines[j].g.y.deno;
            if (!is_intersection(lines[i], lines[j])) continue;
            Point p = calc_intersection_point(lines[i], lines[j]);
//            intersection_count[i]++;
            st.insert(p);
            unique_intersections.insert(p);
//            intersections[i].push_back(p);

//            cout << ' ' << p;

        }
        intersection_count[i] = st.size();
//        cout << endl;
    }

//    cout << ans << endl;

    int ans = 1;
    rep(i, n) {
        ans += intersection_count[i] + 1;
    }

    cout << ans << endl;
//    cout << "suichoku suihei" << endl;

}
