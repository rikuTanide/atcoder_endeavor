#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
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

vector<vector<int>> dynamic_programing(int n, int t, vector<P> menu) {
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, -1));
    dp[0][0] = 0;

    auto get = [&](int i, int j) {
        return dp[i][j];
    };

    auto set = [&](int i, int j, int v) {
        if (i > n + 1) return;
        if (j > t + 1)return;
        int value = get(i, j);
        dp[i][j] = max(value, v);
    };

    for (int i = 0; i < n; i++) {
        P p = menu[i];
        for (int j = 0; j <= t; j++) {
            int prev = get(i, j);
            if (prev == -1) continue;
            set(i + 1, j + p.first, prev + p.second);
            set(i + 1, j, prev);
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            if (dp[i][j] == -1) {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp;

}

int main() {
    int n, t;
    cin >> n >> t;

    vector<P> menu(n);
    rep(i, n) cin >> menu[i].first >> menu[i].second;

    vector<vector<int>> dp1 = dynamic_programing(n, t - 1, menu);
    reverse(menu.begin(), menu.end());
    vector<vector<int>> dp2 = dynamic_programing(n, t - 1, menu);
    reverse(menu.begin(), menu.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        assert(i < dp1.size());
        assert(i < dp2.size());
        // i を最後にとっておいた場合の
        for (int bj = 0; bj <= t - 1; bj++) {
            int aj = t - bj - 1;
            assert(bj < dp1[i].size());
            assert(aj < dp2[i].size());
            int bh = dp1[i][bj];
            int ah = dp2[n - i - 1][aj];
            int lh = menu[i].second;
            int now = bh + ah + lh;
            cmax(ans, now);
        }
    }

    cout << ans << endl;

}