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
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

bool equal(double a, double b) {
//    return fabs(a - b) < DBL_EPSILON;
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
// https://kimiyuki.net/writeup/algo/etc/utpc-2012-d/
int main() {
    int n; scanf("%d", &n);
    vector<double> x1(n), y1(n); rep (i, n) scanf("%lf%lf", &x1[i], &y1[i]);
    vector<double> x2(n), y2(n); rep (i, n) scanf("%lf%lf", &x2[i], &y2[i]);
    // solve
    complex<double> z10(x1[0], y1[0]);
    complex<double> z11(x1[1], y1[1]);
    complex<double> z20(x2[0], y2[0]);
    complex<double> z21(x2[1], y2[1]);
    auto f = [&](complex<double> z) {
        double scale = 0.5;
        double angle = arg(z21 - z20) - arg(z11 - z10);
        return (z - z10) * polar<double>(scale, angle) + z20;
    };
    complex<double> z = z10;
    rep (_, 10000) z = f(z);
    // output
    printf("%.8lf %.8lf\n", real(z), imag(z));

}
