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

struct Triangle {
    double x, r, h;

    double cut(double a, double b) {
        if (b <= x) return 0;
        if (x + h <= a) return 0;
        if (a <= x && x + h <= b) return v();

//
//        double pr = r / h * p;
//        double sub = pr * pr * PI * p / 3;

        if (x <= a && b <= x + h) {
            double s = cut(b, INF);
            double t = cut(-INF, a);
            return v() - s - t;
        }

        if (a <= x) {
            double p = x + h - b;
            double sub = v() / pow(h, 3) * pow(p, 3);
            double ans = v() - sub;
            return ans;
        }


        double p = x + h - a;
        double sub = v() / pow(h, 3) * pow(p, 3);
        return sub;
    }

    double v() {
        return r * r * PI * h / 3;
    }

};

std::istream &operator>>(std::istream &in, Triangle &o) {
    in >> o.x >> o.r >> o.h;
    return in;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<Triangle> triangles(n);
    rep(i, n) cin >> triangles[i];

    rep(_, q) {
        double a, b;
        cin >> a >> b;

        double ans = 0;

        rep(i, n) ans += triangles[i].cut(a, b);

        cout << setprecision(20) << ans << endl;
    }

}
