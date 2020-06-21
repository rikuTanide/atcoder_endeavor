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

void print(vector<vector<ll>> &dp) {
    for (auto &l : dp) {
        for (ll a : l) cout << a << ' ';
        cout << endl;
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> g(n);
    rep(i, n) cin >> g[i];

    vector<vector<ll>> dp(n, vector<ll>(n, -1));

    rep(i, n) {
        rep(j, n) {
            // ｊをi番目として採用
            if (j == 0) {
                dp[i][j] = g[i];
            } else {
                rep(l, i) {
                    // lをj-1番目として使う
                    ll prev = dp[l][j - 1];
                    if (prev == -1) continue;
                    ll now = prev + max(g[i] - g[l], 0ll);
                    if (dp[i][j] == -1) dp[i][j] = now;
                    else
                        cmin(dp[i][j], now);
                }
            }
        }
    }

//    print(dp);

    int ai = n - k - 1;
    ll ans = INF;
    rep(i, n) {
        for (int ki = ai; ki < n; ki++) {
            if (dp[i][ki] == -1) continue;
            cmin(ans, dp[i][ki]);
        }
    }

    cout << ans << endl;

}
