#include <bits/stdc++.h>
#include <cmath>


#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

// https://www.hiramine.com/programming/graphics/NhVector2.h

template<class T>
class TNhVector2 {
public:
    T x, y;

    // コンストラクタ
    // デフォルト
    TNhVector2() : x(0), y(0) {}

    // 初期化
    TNhVector2(const T a, const T b) : x(a), y(b) {}

    // 配列アクセス
    // 読み取り用
    const T &operator[](const long i) const {
        return *((&x) + i);
    }

    // 書き込み用
    T &operator[](const long i) {
        return *((&x) + i);
    }

    // 代入
    TNhVector2 &operator=(const TNhVector2 &b) {
        x = b.x;
        y = b.y;
        return *this;
    }

    // 正負反転
    const TNhVector2 operator-() const {
        return TNhVector2(-x, -y);
    }

    // 和差積商
    // 和
    const TNhVector2 operator+(const TNhVector2 &b) const {
        return TNhVector2(x + b.x, y + b.y);
    }

    // 差
    const TNhVector2 operator-(const TNhVector2 &b) const {
        return TNhVector2(x - b.x, y - b.y);
    }

    // ベクトル x 数値
    const TNhVector2 operator*(const T t) const {
        return TNhVector2(x * t, y * t);
    }

    //  数値 x ベクトル
    friend inline const TNhVector2 operator*(const T t, const TNhVector2 &b) {
        return b * t;
    }

    // 商
    const TNhVector2 operator/(const T t) const {
        if (0.0 == t) {    // ゼロ割は、非常に小さい数で割りたいと解釈して、適当にFLT_EPSILONで割り算を実施
            assert(!"ゼロ割");    // アサートになるケースは、呼び出し側で本呼び出し『前』に対処する方針で。
            return TNhVector2(x / FLT_EPSILON, y / FLT_EPSILON);
        }
        return TNhVector2(x / t, y / t);
    }

    // 自身に対する和差積商
    // 和
    TNhVector2 &operator+=(const TNhVector2 &b) {
        x += b.x;
        y += b.y;
        return *this;
    }

    // 差
    TNhVector2 &operator-=(const TNhVector2 &b) {
        x -= b.x;
        y -= b.y;
        return *this;
    }

    // 積
    TNhVector2 &operator*=(const T t) {
        x *= t;
        y *= t;
        return *this;
    }

    // 商
    TNhVector2 &operator/=(const T t) {
        if (0.0 == t) {    // ゼロ割は、非常に小さい数で割りたいと解釈して、適当にFLT_EPSILONで割り算を実施
            assert(!"ゼロ割");    // アサートになるケースは、呼び出し側で本呼び出し『前』に対処する方針で。
            x /= FLT_EPSILON;
            y /= FLT_EPSILON;
            return *this;
        }
        x /= t;
        y /= t;
        return *this;
    }

    // 内積
    const T CalcInnerProduct(const TNhVector2 &b) const {
        return x * b.x + y * b.y;
    }

    // 外積
    const T CalcOuterProduct(const TNhVector2 &b) const {
        return x * b.y - y * b.x;
    }

    // 長さ
    const T CalcLengthSquared() const {
        return this->CalcInnerProduct(*this);
    }

    const T CalcLength() const {
        return (T) sqrt(this->CalcLengthSquared());
    }

    // 単位ベクトルの取得
    const TNhVector2 CalcNormal() const {
        assert(0 != this->CalcLength());
        return (*this) / this->CalcLength();
    }

    // 単位ベクトル化
    TNhVector2 &Normalize() {
        assert(0 != this->CalcLength());
        (*this) /= this->CalcLength();
        return *this;
    }

    // 比較
    // 同じか
    bool operator==(const TNhVector2 &b) const {
        return (b.x == x && b.y == y);
    }

    // 異なるか
    bool operator!=(const TNhVector2 &b) const {
        return !(b == *this);
    }

    // 小さいか（注：yに関しては大きい方が、小さいとみなす）
    bool operator<(const TNhVector2 &b) const {
        if (y > b.y) { return true; }
        else if (y < b.y) { return false; }
        else {    // Ｙが等しいときはＸで比較
            if (x < b.x) { return true; }
            else if (x > b.x) { return false; }
            else { return false; }// Ｘ、Ｙが等しいときは、FALSE
        }
    }

    // 大きいか（注：yに関しては大きい方が、小さいとみなす）
    bool operator>(const TNhVector2 &b) const {
        if (y < b.y) { return true; }
        else if (y > b.y) { return false; }
        else {    // Ｙが等しいときはＸで比較
            if (x > b.x) { return true; }
            else if (x < b.x) { return false; }
            else { return false; }// Ｘ、Ｙが等しいときは、FALSE
        }
    }

};

typedef TNhVector2<double> CNhVector2d;
typedef CNhVector2d CNhPoint2d;

// https://www.hiramine.com/programming/graphics/2d_segmentintersection.html
bool calcIntersectionPoint(const CNhPoint2d &pointA,
                           const CNhPoint2d &pointB,
                           const CNhPoint2d &pointC,
                           const CNhPoint2d &pointD,
                           CNhPoint2d &pointIntersection
) {
    double dBunbo = (pointB.x - pointA.x)
                    * (pointD.y - pointC.y)
                    - (pointB.y - pointA.y)
                      * (pointD.x - pointC.x);
    if (0 == dBunbo) {    // 平行
        return false;
    }

    CNhVector2d vectorAC = pointC - pointA;

    double dR = ((pointD.y - pointC.y) * vectorAC.x
                 - (pointD.x - pointC.x) * vectorAC.y) / dBunbo;
    double dS = ((pointB.y - pointA.y) * vectorAC.x
                 - (pointB.x - pointA.x) * vectorAC.y) / dBunbo;

    if (dR < 0 || 1 < dR) return false;
    if (dS < 0 || 1 < dS) return false;

    pointIntersection = pointA + dR * (pointB - pointA);

    return true;
}

/*
 *     CNhPoint2d a1(0, 1);
    CNhPoint2d a2(2, 1);
    CNhPoint2d b1(1, 0);
    CNhPoint2d b2(1, 2);

    CNhPoint2d intersection;

    double d1, d2;

    calcIntersectionPoint(a1, a2, b1, b2, intersection, d1, d2);

 */

struct Line {
    double start_x, start_y, end_x, end_y;
};

struct Point {
    double x, y;
};

const double INFD = 50000.0;

bool isCross(Line l1, Line l2, Point &point) {
    CNhPoint2d s1(l1.start_x, l1.start_y);
    CNhPoint2d s2(l1.end_x, l1.end_y);
    CNhPoint2d e1(l2.start_x, l2.start_y);
    CNhPoint2d e2(l2.end_x, l2.end_y);

    CNhPoint2d res;

    if (calcIntersectionPoint(s1, s2, e1, e2, res)) {
//        Point p = {round(res.x * 10000) / 10000, round(res.y * 10000) / 10000};
        Point p = {res.x, res.y};
        point = p;
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<Line> over_lines;

    {
        vector<double> ts(n);
        vector<double> vs(n);
        rep(i, n) {
            cin >> ts[i];
        }
        rep(i, n) {
            cin >> vs[i];
        }
        double now = 0;
        for (int i = 0; i < n; i++) {
            Line line = {now, vs[i], now + ts[i], vs[i]};
            over_lines.push_back(line);
            now += ts[i];
        }

    }
    vector<Line> up_lines;
    {
        vector<Point> up_point;
        Point sp = {0.0, 0.0};
        up_point.push_back(sp);
        rep(i, n - 1) {
            if (over_lines[i].end_y < over_lines[i + 1].start_y) {
                Point p = {over_lines[i].end_x, over_lines[i].end_y};
                up_point.push_back(p);
            }
        }

        for (Point p : up_point) {
            [&] {
                Line line = {p.x, p.y, p.x + INFD, p.y + INFD};
                Point intersection;
                for (Line l : over_lines) {
                    if (l.end_x <= p.x) continue;
                    if (isCross(line, l, intersection)) {
                        Line up_line = {p.x, p.y, intersection.x, intersection.y};
                        up_lines.push_back(up_line);
                        return;
                    }
                }
                Line up_line = {p.x, p.y, p.x + INFD, p.y + INFD};
                up_lines.push_back(up_line);

            }();
        }

    }
    vector<Line> down_lines;
    {
        vector<Point> down_point;
        rep(i, n - 1) {
            if (over_lines[i].end_y > over_lines[i + 1].start_y) {
                Point p = {over_lines[i].end_x, over_lines[i + 1].start_y};
                down_point.push_back(p);
            }
        }
        Point ep = {over_lines.back().end_x, 0.0};
        down_point.push_back(ep);

        for (Point p : down_point) {
            [&] {
                Line line = {p.x, p.y, p.x - INFD, p.y + INFD};
                Point intersection;
                for (Line l : over_lines) {
                    if (l.start_x >= p.x) continue;
                    if (isCross(line, l, intersection)) {
                        Line down_line = {p.x, p.y, intersection.x, intersection.y};
                        down_lines.push_back(down_line);
                        return;
                    }
                }
                Line down_line = {p.x, p.y, p.x - INFD, p.y + INFD};
                down_lines.push_back(down_line);

            }();
        }
    }

    for (int i = 0; i < up_lines.size(); i++) {
        for (int j = 0; j < down_lines.size(); j++) {
            Point intersection;
            if (isCross(up_lines[i], down_lines[j], intersection)) {
                up_lines[i].end_x = intersection.x;
                up_lines[i].end_y = intersection.y;
                down_lines[j].end_x = intersection.x;
                down_lines[j].end_y = intersection.y;
            }
        }
    }

    vector<Point> pass_points;
    for (Line l : up_lines) {
        if (l.end_x > over_lines.back().end_x) continue;

        Point s = {l.start_x, l.start_y};
        Point e = {l.end_x, l.end_y};
        pass_points.push_back(s);
        pass_points.push_back(e);
    }
    for (Line l : down_lines) {
        if (l.end_x < 0) continue;
        Point s = {l.start_x, l.start_y};
        Point e = {l.end_x, l.end_y};
        pass_points.push_back(s);
        pass_points.push_back(e);
    }

    sort(pass_points.begin(), pass_points.end(), [](Point a, Point b) {
        return a.x < b.x;
    });

    double ans = 0.0;

    for (int i = 0; i < pass_points.size() - 1; i++) {
        Point start = pass_points[i];
        Point end = pass_points[i + 1];

        double with = end.x - start.x;
        if(with == 0.0) continue;
        double b = min(start.y, end.y);
        double rect = with * b;
        double height = max(start.y , end.y) - b;
        double tri= height * with / 2;

        ans += rect + tri;

    }


    cout << ans << endl;


}
