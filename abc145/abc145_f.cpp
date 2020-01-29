#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    int m = n - k;

    vector<int> h(n);
    rep(i, n) cin >> h[i];
    h.insert(h.begin(), 0);

    vector<vector<ll>> dp(305, vector<ll>(305, 0));
    rep(i, n + 1)rep(j, m + 1)dp[i][j] = INF;
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        rep(j, m) {
            ll now = INF;
            rep(ki, i) {
                cmin(now, dp[ki][j] + max(0, h[i] - h[ki]));
            }
            dp[i][j + 1] = now;
        }
    }

    ll ans = INF;
    rep(i, n + 1)cmin(ans, dp[i][m]);
    cout << ans << endl;
}