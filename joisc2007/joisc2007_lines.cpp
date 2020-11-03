//
//#pragma GCC target("avx")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

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

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
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

struct Rational {
    ll num, deno;


    Rational() : num(0), deno(1) {}

    Rational(ll num) : num(num), deno(1) {}

    Rational(ll num, ll deno) : num(num), deno(deno) {}

    Rational normalize() const {

        if (num == 0) return Rational(0);
        if (num == INF) return Rational(INF);
        if (num == -INF) return Rational(INF);

        if (deno < 0) return Rational(-num, -deno).normalize();

        if (num < 0) {
            Rational tmp = Rational(-num, deno).normalize();
            return Rational(-tmp.num, tmp.deno);
        }
        ll g = __gcd(num, deno);
        return Rational(num / g, deno / g);

    }

    bool is_norm() const {
        Rational nom = normalize();
        return nom.num == num && nom.deno == deno;
    }

    bool is_inf() const {
        return num == INF;
    }

    bool is_minf() const {
        return num == -INF;
    }

    bool is_xinf() const {
        return is_inf() || is_minf();
    }

    bool is_zero() const {
        return num == 0;
    }

    friend std::istream &operator>>(std::istream &in, Rational &r) {
        in >> r.num;
        r.deno = 1;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, Rational &r) {
//        out << '[' << r.num << '/' << r.deno << ']' << '(' << (double(r.num) / double(r.deno)) << ')';
        out << (double(r.num) / double(r.deno));
        return out;
    }


    friend bool operator==(const Rational r1, const Rational r2) {
        assert(r1.is_norm());
        assert(r2.is_norm());
        return r1.deno == r2.deno && r1.num == r2.num;
    }

    friend bool operator!=(const Rational r1, const Rational r2) {
        assert(r1.is_norm());
        assert(r2.is_norm());
        return !(r1 == r2);
    }

    friend Rational operator+(const Rational r1, const Rational r2) {
        assert(r1.is_norm());
        assert(r2.is_norm());

        assert(!r1.is_inf());
        assert(!r2.is_inf());

        ll deno = r1.deno * r2.deno;
        ll l = r1.num * r2.deno;
        ll r = r2.num * r1.deno;
        ll num = l + r;
        Rational rat = {num, deno};
        Rational norm = rat.normalize();
        return norm;
    }


    friend Rational operator-(const Rational r1, const Rational r2) {
        assert(r1.is_norm());
        assert(r2.is_norm());

        ll deno = r1.deno * r2.deno;
        ll l = r1.num * r2.deno;
        ll r = r2.num * r1.deno;
        ll num = l - r;
        Rational rat = {num, deno};
        Rational norm = rat.normalize();
        return norm;
    }

    friend Rational operator/(const Rational r1, const Rational r2) {
        assert(r1.is_norm());
        assert(r2.is_norm());

        assert(!r1.is_xinf());
        assert(!r2.is_xinf());
        assert(!r2.is_zero());

        ll num = r1.num * r2.deno;
        ll deno = r1.deno * r2.num;
        Rational rat(num, deno);
        Rational norm = rat.normalize();
        return norm;
    };

    friend Rational operator*(const Rational r1, const Rational r2) {
        assert(r1.is_norm());
        assert(r2.is_norm());

        assert(!r1.is_xinf());
        assert(!r2.is_xinf());
        ll num = r1.num * r2.num;
        ll deno = r1.deno * r2.deno;
        Rational rat(num, deno);
        Rational norm = rat.normalize();
        return norm;
    }

    friend bool operator<(const Rational r1, const Rational r2) {
        assert(r1.is_norm());
        assert(r2.is_norm());

        assert(!r1.is_xinf());
        assert(!r2.is_xinf());

        ll l = r1.num * r2.deno;
        ll r = r2.num * r1.deno;
        return l < r;
    }

};

struct Point {
    Rational x, y;

    friend std::istream &operator>>(std::istream &in, Point &p) {
        cin >> p.x >> p.y;
        return in;
    }

    friend bool operator==(Point p1, Point p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }

    friend bool operator<(Point p1, Point p2) {
        if (p1.x != p2.x) {
            return p1.x < p2.x;
        }
        return p1.y < p2.y;
    }

    friend std::ostream &operator<<(std::ostream &out, Point &p) {
        cout << p.x << '-' << p.y;
        return out;
    }
};

struct Line {
    Point s, g;

    friend std::istream &operator>>(std::istream &in, Line &l) {
        cin >> l.s >> l.g;
        return in;
    }

    Rational slope() const {
        assert(!is_x());
        assert(!is_y());
        Rational y = g.y - s.y;
        Rational x = g.x - s.x;
        return Rational(y / x).normalize();
//return Rational(10);
    }

    Point assign_x(const Rational &x) const {
        Rational y = slope() * x + intercept();
        return Point{x, y};
    }

    Point assign_y(const Rational &y) const {
        Rational x = (y - intercept()) / slope();
        return Point{x, y};
    }

    bool is_x() const {
        return (s.x == g.x);
    }

    bool is_y() const {
        return (s.y == g.y);
    }

    Rational intercept() const {

        assert(!is_x());
        assert(!is_y());


        Rational y1 = s.y;
        Rational y2 = g.y;
        Rational x1 = s.x;
        Rational x2 = g.x;


        return Rational(y1 - ((y2 - y1) / (x2 - x1)) * x1).normalize();
    }

};


bool is_intersection(const Line &l1, const Line &l2) {
    if (l1.is_x() && l2.is_x()) return false;
    if (l1.is_y() && l2.is_y()) return false;

    if (l1.is_x() || l2.is_x()) return true;
    if (l1.is_y() || l2.is_y()) return true;


    return l1.slope() != l2.slope();
}

Point calc_intersection_point(Line l1, Line l2) {
    if (l2.is_x()) swap(l1, l2);
    if (l1.is_x()) {
        if (l2.is_y()) return Point{l1.s.x, l2.s.y};
        return l2.assign_x(l1.s.x);
    }
    if (l2.is_y()) swap(l1, l2);
    if (l1.is_y()) return l2.assign_y(l1.s.y);

    // https://qiita.com/uyuutosa/items/8de1f7602cb14c29606f

    Rational a = l1.slope();
    Rational b = l1.intercept();

    Rational c = l2.slope();
    Rational d = l2.intercept();

    assert((a - c) != Rational(0));

    Rational x = (d - b) / (a - c);
    Rational y = (a * d - b * c) / (a - c);

    return Point{x, y};

}

int main2() {
    Rational tmp(Rational(1, 5) + Rational(4, 2));
    cout << tmp << endl;
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
//    cout << endl;

    vector<vector<Point>> intersections(n);
//    ll ans = 0;
    rep(i, n) {
//        cout << i + 1 << ' ';
        rep(j, n) {
            if (i == j) continue;
//            ans += lines[i].s.x.num + lines[j].g.y.deno;
            if (!is_intersection(lines[i], lines[j])) continue;
//            Point p = calc_intersection_point(lines[i], lines[j]);
//            intersections[i].push_back(p);

//            cout << ' ' << p;

        }
//        cout << endl;
    }

//    cout << ans << endl;
    set<Point> unique_intersections;
    rep(i, n) for (Point p : intersections[i]) unique_intersections.insert(p);

    int v = unique_intersections.size() + 2 * n + 4;
    int e = 2 * n + 4;
    rep(i, n) {
        e += intersections[i].size() + 1;
    }

    cout << 1 - v + e << endl;
//    cout << "suichoku suihei" << endl;

}
