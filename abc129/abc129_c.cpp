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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> broken(n + 1, 0);
    rep(i, m) {
        int a;
        cin >> a;
        broken[a] = 1;
    }
    const int mod = 1000000007;

    vector<int> dp(n + 2);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--) {
        if (broken[i]) {
            dp[i] = 0;
            continue;
        }
        dp[i] = (dp[i + 1] + dp[i + 2]) % mod;
    }

    cout << dp[0] << endl;


}

