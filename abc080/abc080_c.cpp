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
    int n;
    cin >> n;

    vector<vector<bool>> shops(n, vector<bool>(10));

    rep(i, n) {
        rep(j, 10) {
            char c;
            cin >> c;

            shops[i][j] = c == '1';
        }
    }

    vector<vector<ll>> benefit(n, vector<ll>(11));
    rep(i, n) rep(j, 11) cin >> benefit[i][j];
    ll ans = -INF;
    rep(i, 1 << 10) {
        if (i == 0) continue;
        vector<bool> open(10, false);
        rep(j, 10) open[j] = (i >> j) & 1;

        ll now = 0;
        rep(j, n) {
            int c = 0;
            rep(k, 10) if (open[k] && shops[j][k]) c++;
            now += benefit[j][c];
        }
        cmax(ans, now);
    }
    cout << ans << endl;
}
