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
    if (a <= c && b <= d) return true;

    if (!(b >= d)) return false;

    return c >= (2.0 * a * b * d + (b * b - a * a) * sqrt(a * a + b * b - d * d)) / (a * a + b * b);

}

int main() {

    double a, b;
    cin >> a >> b;

    a -= 0.005;
    b -= 0.005;

    int n;
    cin >> n;

    rep(_, n) {
        double c, d;
        cin >> c >> d;

        c += 0.005;
        d += 0.005;

        bool ok = check(a, b, c, d) || check(a, b, d, c) || check(b, a, c, d) || check(b, a, d, c);
        string ans = ok ? "YES" : "NO";
        cout << ans << endl;

    }
}

