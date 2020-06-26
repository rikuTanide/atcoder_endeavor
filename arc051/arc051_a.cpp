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


int main() {
    int cx, cy, r;
    int x2, y2, x3, y3;
    cin >> cx >> cy >> r >> x2 >> y2 >> x3 >> y3;

    // circle = red , rect = blue
    bool b1 = [&] {
        // 四角が完全に円を内包しないか？

        if (!(y2 <= cy && cy <= y3)) {
            return true;
        }

        if (!(x2 <= cx && cx <= x3)) {
            return true;
        }

        if (
                abs(x2 - cx) >= r &&
                abs(x3 - cx) >= r &&
                abs(y2 - cy) >= r &&
                abs(y3 - cy) >= r) {
            return false;
        }

        return true;

    }();


    auto in = [&](double x, double y) -> bool {
        double w = x - cx;
        double h = y - cy;
        double ww = w * w;
        double hh = h * h;

        double d = sqrt(ww + hh);
        return d + EPS < r;
    };

    bool b2 = [&] {
        // 円が完全に四角を内包しないか？
        if (in(x2, y2) && in(x2, y3) && in(x3, y2) && in(x3, y3)) {
            return false;
        }
        return true;
    }();

    cout << (b1 ? "YES" : "NO") << endl;
    cout << (b2 ? "YES" : "NO") << endl;

}
