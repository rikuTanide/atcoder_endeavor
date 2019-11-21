#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
//const int INF = INT_MAX  ;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000009;

typedef tuple<ll, int, int, int> PC;

int dp[101][4][4][4];

int main() {
    int n;
    cin >> n;

    dp[0][3][3][3] = 1;

    rep(len, n) {
        rep(c1, 4) {
            rep(c2, 4) {
                rep(c3, 4) {
                    if (dp[len][c1][c2][c3] == 0) {
                        continue;
                    }

                    for (int a = 0; a < 4; a++) {
                        if (a == 2 && c1 == 1 && c2 == 0) continue;
                        if (a == 2 && c1 == 0 && c2 == 1) continue;
                        if (a == 1 && c1 == 2 && c2 == 0) continue;
                        if (a == 2 && c1 == 1 && c3 == 0) continue;
                        if (a == 2 && c2 == 1 && c3 == 0) continue;

                        dp[len + 1][a][c1][c2] += dp[len][c1][c2][c3];
                        dp[len + 1][a][c1][c2] %= mod;
                    }

                }
            }
        }
    }

    int ans = 0;
    rep(c1, 4) {
        rep(c2, 4) {
            rep(c3, 4) {
                ans += dp[n][c1][c2][c3];
                ans %= mod;
            }
        }
    }
    cout << ans << endl;
}

