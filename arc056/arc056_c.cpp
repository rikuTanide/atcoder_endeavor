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
    ll k;
    cin >> n >> k;

    vector<vector<ll>> w(n, vector<ll>(n));
    rep(y, n) rep (x, n) cin >> w[y][x];

    vector<ll> sum_w(1 << n);
    for (int y = 1; y < (1 << n); y++) {
        int i = __builtin_ctz(y);
        int x = y ^(1 << i);
        sum_w[y] = sum_w[x];
        rep(j, n) {
            if (x & (1 << j)) {
                sum_w[y] += w[i][j];
            }
        }
    }

    ll ans = 0;
    vector<ll> dp = sum_w;
    cmax(ans, k);

    for (int i = 2; i < n; i++) {
        for (int y = (1 << n) - 1; y >= 0; y--) {
            ll acc = 0;
            for (int x = y; x; x = (x - 1) & y) {
                if ((y ^ x) && x && __builtin_popcount(y ^ x) >= i - 1) {
                    cmax(acc, dp[y ^ x] + sum_w[x]);
                }
            }
            dp[y] = acc;
        }
        cmax(ans, i * k + dp.back() - sum_w.back());
    }
    cmax(ans, n * k - sum_w.back());
    cout << ans << endl;

}