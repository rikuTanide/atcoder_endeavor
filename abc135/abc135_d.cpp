#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;
static const ll MOD = 1000000007;
const int n = 13;
ll dp[100005][n];

int main() {
    string s;
    cin >> s;
    dp[0][0] = 1;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '?') {
            for (int k = 0; k < 10; k++) {
                for (int j = 0; j < n; j++) {
                    dp[i + 1][(j * 10 + k) % n] += dp[i][j];
//                    dp[i + 1][(j * 10 + k) % n] %= MOD;
                }
            }
        } else {
            int k = c - '0';
            for (int j = 0; j < n; j++) {
                dp[i + 1][(j * 10 + k) % n] += dp[i][j];
//                dp[i + 1][(j * 10 + k) % n] %= MOD;
            }
        }
    }

    cout << dp[s.length()][5] << endl;

}
