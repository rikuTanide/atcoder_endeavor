#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
//const int mod = 1000000007;
const ll mod = INF / 1000;

bool checkDp(int n, int k, ll target, vector<ll> &as) {
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    dp[0][0] = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i + 1][j] = dp[i + 1][j] || dp[i][j];
            if (j >= as[i]) dp[i + 1][j] = dp[i + 1][j] || dp[i][j - as[i]];
        }
    }
    for (int i = max(0ll, k - target); i < k; i++) {
        if (dp[n][i]) return true;
    }
    return false;
}

bool check(int n, int k, int target_index, vector<ll> &as) {
    vector<ll> numbers(n - 1);
    for (int i = 0; i < n; i++) {
        if (i == target_index) continue;
        int j = i;
        if (i > target_index) j--;
        numbers[j] = as[i];
    }

    return checkDp(n - 1, k, as[target_index], numbers);

}

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];

    sort(numbers.rbegin(), numbers.rend());

    int ans = 0;
    for (int i = 0; i < n; i++) {

        if (check(n, k, i, numbers)) {
            ans++;
        }
    }

    cout << ans << endl;
}
