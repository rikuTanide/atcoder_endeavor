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

vector<vector<ll>> dynamic_programing(ll n, ll t, vector<P> menu) {
    vector<vector<ll>> dp(n + 1, vector<ll>(t + 1, -1));
    dp[0][0] = 0;

    auto get = [&](ll i, ll j) {
        return dp[i][j];
    };

    auto set = [&](ll i, ll j, ll v) {
        if (i > n) return;
        if (j > t) return;
        ll value = get(i, j);
        dp[i][j] = max(value, v);
    };

    for (ll i = 0; i < n; i++) {
        P p = menu[i];
        for (ll j = 0; j <= t; j++) {
            ll prev = get(i, j);
            if (prev == -1) continue;
            set(i + 1, j + p.first, prev + p.second);
            set(i + 1, j, prev);
        }
    }
    for (ll i = 0; i <= n; i++) {
        assert(dp[i][0] == 0);
        for (ll j = 1; j <= t; j++) {
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
    }
    return dp;
}

int main() {
    ll n, t;
    cin >> n >> t;

    vector<P> menu(n);
    rep(i, n) cin >> menu[i].first >> menu[i].second;

    vector<vector<ll>> dp1 = dynamic_programing(n, t - 1, menu);
    reverse(menu.begin(), menu.end());
    vector<vector<ll>> dp2 = dynamic_programing(n, t - 1, menu);
    reverse(menu.begin(), menu.end());

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        assert(i < dp1.size());
        ll i2 = n - i - 1;
        assert(i2 < dp2.size());
        assert(i + i2 == n - 1);
        // i を最後にとっておいた場合の
        for (ll bj = 0; bj <= t - 1; bj++) {
            ll aj = t - bj - 1;
            assert(bj < dp1[i].size());
            assert(aj < dp2[i].size());
            assert(aj + bj == t - 1);
            ll bh = dp1[i][bj];
            ll ah = dp2[i2][aj];
            assert(bh >= 0);
            assert(ah >= 0);
            ll lh = menu[i].second;
            ll now = bh + ah + lh;
            cmax(ans, now);
        }
    }

    cout << ans << endl;

}