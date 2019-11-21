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

const int mod = 1000000007;

int dp[101][4][4][4];

int main() {

    int n, m, c;
    cin >> n >> m >> c;

    vector<int> bs(m);

    rep(i, m) {
        int b;
        cin >> b;
        bs[i] = b;
    }

    vector<vector<int>> as(n, vector<int>(m));
    rep(i, n) {
        rep(j, m) {
            int a;
            cin >> a;
            as[i][j] = a;
        }
    }

    int count = 0;
    rep(i, n) {
        int now = 0;
        rep(j, m) {
            now += as[i][j] * bs[j];
        }
        now += c;
        if (now > 0) {
            count++;
        }
    }

    cout << count << endl;

}

