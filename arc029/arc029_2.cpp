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
    assert(b >= a);
    assert(d >= c);
    if (a <= c && b <= d) return true;


    double aa = a * a;
    double bb = b * b;
    double cc = c * c;
    double dd = d * d;

    bool bd = b > d;

    bool f = c + EPS >= (2.0 * a * b * d + (bb - aa) * sqrt(aa + bb - dd)) / (aa + bb);

    return bd && f;

}

int main() {

    double a, b;
    cin >> a >> b;

    if (!(a < b)) swap(a, b);


    int n;
    cin >> n;

    rep(_, n) {
        double c, d;
        cin >> c >> d;

        if (!(c < d))swap(c, d);

        bool ok = check(a, b, c, d);
        string ans = ok ? "YES" : "NO";
        cout << ans << endl;

    }
}

