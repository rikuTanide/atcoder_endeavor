#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;

int dp[5005][5005];

int main() {

    int n;
    string s;
    cin >> n >> s;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] != s[j]) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
        }
    }
    int ans = 0;
    rep(i, n) {
        rep(j, n) {
            if (i >= j) continue;
            int now = min(dp[i][j], j - i);
            ans = max(ans, now);
        }
    }
    cout << ans << endl;

}
