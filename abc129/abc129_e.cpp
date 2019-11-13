#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)
const int mod = 1000000007;
int dp[100005][2];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    dp[0][0] = 1;
    rep(i, n) {
        {
            if (s[i] == '0') {
                dp[i + 1][0] = dp[i][0];
                dp[i + 1][1] = dp[i][1];
            } else {
                dp[i + 1][1] = (dp[i][0] + dp[i][1]) % mod;
            }
        }
        {
            if (s[i] == '0') {
                (dp[i + 1][1] += dp[i][1] * 2 % mod) %= mod;
            } else {
                (dp[i + 1][0] += dp[i][0] * 2 % mod) %= mod;
                (dp[i + 1][1] += dp[i][1] * 2 % mod) %= mod;
            }
        }
    }
    int ans = (dp[n][0] + dp[n][1]) % mod;
    cout << ans << endl;
}

