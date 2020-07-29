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

    int h, m, s, c1, c2;
    cin >> h >> m >> s >> c1 >> c2;
    int t = 3600 * h + 60 * m + 1 * s;
    c1 += (59 * t) / (60 * 60);
    c2 += (11 * t) / (12 * 3600);

    int mi = max((60 * 60 * c1) / 59, (12 * 3600 * c2) / 11) + 1;
    int ma = min((60 * 60 * (c1 + 1) - 1) / 59, (12 * 3600 * (c2 + 1) - 1) / 11);
    if (mi > ma) {
        cout << -1 << endl;
    } else {
        printf("%d %d\n", mi - t, ma - t);
    }

}
