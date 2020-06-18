#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
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

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


struct Dot {
    double x, y;
    char d;
};

std::istream &operator>>(std::istream &in, Dot &o) {
    cin >> o.x >> o.y >> o.d;
    return in;
}

struct MinMax {
    double mi, ma;

    bool enable() {
        return mi <= ma;
    }
};

MinMax get_y_mm(vector<Dot> &dots, vector<char> target) {

    MinMax mm = {INF, -INF};
    for (char c : target) {
        for (Dot dot : dots) {
            if (dot.d == c) cmin(mm.mi, dot.y);
            if (dot.d == c) cmax(mm.ma, dot.y);
        }
    }

    return mm;

}

MinMax get_x_mm(vector<Dot> &dots, vector<char> target) {

    MinMax mm = {INF, -INF};
    for (char c : target) {
        for (Dot dot : dots) {
            if (dot.d == c) cmin(mm.mi, dot.x);
            if (dot.d == c) cmax(mm.ma, dot.x);
        }
    }

    return mm;

}

vector<double> check_intersection(MinMax m1, MinMax m2, double d) {
    if (!m1.enable()) return {};
    if (!m2.enable()) return {};

    vector<double> ans;
    ans.push_back(abs(m1.mi - m2.mi) / d);
    ans.push_back(abs(m1.mi - m2.ma) / d);
    ans.push_back(abs(m1.ma - m2.mi) / d);
    ans.push_back(abs(m1.ma - m2.ma) / d);

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<Dot> dots(n);
    rep(i, n) cin >> dots[i];

    MinMax u_mm = get_y_mm(dots, {'U'});
    MinMax y_mm = get_y_mm(dots, {'L', 'R'});
    MinMax d_mm = get_y_mm(dots, {'D'});

    MinMax l_mm = get_x_mm(dots, {'L'});
    MinMax x_mm = get_x_mm(dots, {'U', 'D'});
    MinMax r_mm = get_x_mm(dots, {'R'});

    vector<double> intersection;
    intersection.push_back(0);
    intersection.push_back(1 << 30);

    auto lx = check_intersection(l_mm, x_mm, 1);
    auto rx = check_intersection(r_mm, x_mm, 1);
    auto lr = check_intersection(l_mm, r_mm, 2);
    auto uy = check_intersection(u_mm, y_mm, 1);
    auto dy = check_intersection(d_mm, y_mm, 1);
    auto ud = check_intersection(u_mm, d_mm, 2);

    intersection.insert(intersection.end(), lx.begin(), lx.end());
    intersection.insert(intersection.end(), rx.begin(), rx.end());
    intersection.insert(intersection.end(), lr.begin(), lr.end());
    intersection.insert(intersection.end(), uy.begin(), uy.end());
    intersection.insert(intersection.end(), dy.begin(), dy.end());
    intersection.insert(intersection.end(), ud.begin(), ud.end());

    double ans = INF;

    for (double i : intersection) {
        double l = INF, r = -INF, u = -INF, d = INF;

        if (l_mm.enable()) cmin(l, l_mm.mi - i), cmax(r, l_mm.ma - i);
        if (r_mm.enable()) cmin(l, r_mm.mi + i), cmax(r, r_mm.ma + i);
        if (x_mm.enable()) cmin(l, x_mm.mi + 0), cmax(r, x_mm.ma + 0);
        if (u_mm.enable()) cmin(d, u_mm.mi + i), cmax(u, u_mm.ma + i);
        if (d_mm.enable()) cmin(d, d_mm.mi - i), cmax(u, d_mm.ma - i);
        if (y_mm.enable()) cmin(d, y_mm.mi + 0), cmax(u, y_mm.ma + 0);
        cmin(ans, (r - l) * (u - d));
    }

    printf("%.20f\n", ans);


}
