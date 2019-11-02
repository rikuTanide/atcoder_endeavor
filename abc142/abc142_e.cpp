#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;

int main() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> keys;

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        int s = 0;
        rep(j, b) {
            int c;
            cin >> c;
            c --;
            s |= 1 << c;
        }
        keys.emplace_back(s, a);
    }

    vector<int> dp(1 << n, INF);
    dp[0] = 0;

    rep(s, 1 << n) {
        rep(i, m) {
            int t = s | keys[i].first;
            int cost = dp[s] + keys[i].second;
            dp[t] = min(dp[t], cost);
        }
    }
    int ans = dp.back();
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << endl;

}
