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

struct Cone {
    double x, r, h;

    //  |>

    double top() {
        return x + h;
    }

    double size() {
        return r * r * PI * h / 3;
    }

    Cone cut(double nh) {
        double rate = nh / h;
        double nr = r * rate;
        double nx = top() - nh;
        return {nx, nr, nh};
    }

};

int main() {
    int n, q;
    cin >> n >> q;

    vector<Cone> cones(n);
    rep(i, n) cin >> cones[i].x >> cones[i].r >> cones[i].h;

    auto is_left_over = [&](int i, double a, double b) {
        Cone c = cones[i];
        return c.top() <= a;
    };

    auto is_left_in = [&](int i, double a, double b) {
        Cone c = cones[i];
        return c.x <= a && a <= c.top() && c.top() <= b;
    };

    auto cut_left = [&](int i, double a, double b) {
        Cone c = cones[i];
        Cone r = c.cut(c.top() - a);
        return r.size();
    };

    auto is_in = [&](int i, double a, double b) {
        Cone c = cones[i];
        return a <= c.x && c.top() <= b;
    };

    auto all = [&](int i, double a, double b) {
        Cone c = cones[i];
        return c.size();
    };

    auto is_right_in = [&](int i, double a, double b) {
        Cone c = cones[i];
        return a <= c.x && c.x <= b && b <= c.top();
    };

    auto cut_right = [&](int i, double a, double b) {
        Cone c = cones[i];
        Cone r = c.cut(c.top() - b);
        return c.size() - r.size();
    };

    auto is_right_over = [&](int i, double a, double b) {
        Cone c = cones[i];
        return b <= c.x;
    };

    auto is_cover = [&](int i, double a, double b) {
        Cone c = cones[i];
        return c.x <= a && b <= b;
    };

    auto cut_center = [&](int i, double a, double b) {
        Cone c = cones[i];
        Cone m2 = c.cut(c.top() - a);
        Cone m1 = c.cut(c.top() - b);
        return m2.size() - m1.size();
    };

    rep(f, q) {
        double a, b;
        cin >> a >> b;

        double ans = 0;
        rep(i, n) {
            if (is_left_over(i, a, b)) {
                continue;
            } else if (is_left_in(i, a, b)) {
                ans += cut_left(i, a, b);
            } else if (is_in(i, a, b)) {
                ans += all(i, a, b);
            } else if (is_right_in(i, a, b)) {
                ans += cut_right(i, a, b);
            } else if (is_right_over(i, a, b)) {
                continue;
            } else if (is_cover(i, a, b)) {
                ans += cut_center(i, a, b);
            } else {
                __throw_runtime_error("konai");
            }
        }
        printf("%.20f\n", ans);
    }

}
