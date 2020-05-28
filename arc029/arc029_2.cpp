#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);


typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

bool check(double a, double b, double c, double d) {
    double floor = PI / 2, ceil = 0;

    while (floor - ceil > (EPS / 10)) {
        double mid = (floor + ceil) / 2;
        double h = a * cos(mid) + b * sin(mid);

        bool ok = h <= c;
        if (ok) ceil = mid;
        else floor = mid;
    }
    double mid = (floor + ceil) / 2;
    double w = a * sin(mid) + b * cos(mid);
    double h = a * cos(mid) + b * sin(mid);

    return w <= (d + EPS) && h <= (c + EPS);

}

int main() {

    double a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    rep(_, n) {
        double c, d;
        cin >> c >> d;

        if (!(c <= d)) swap(c, d);

        bool ok = check(a, b, c, d) || check(b, a, c, d) || check(a, b, d, c) || check(b, a, d, c);
        string ans = ok ? "YES" : "NO";
        cout << ans << endl;

    }
}

