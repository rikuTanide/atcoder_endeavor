#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> ng(3);
    rep(i, 3) cin >> ng[i];
    vector<vector<bool>> dp(n + 10, vector<bool>(100 + 10, false));

    if (find(ng.begin(), ng.end(), n) != ng.end()) {
        cout << "NO" << endl;
        return 0;
    }

    auto ok = [&](int i, int j) {
        if (find(ng.begin(), ng.end(), i) != ng.end()) {
            return;
        }
        dp[i][j] = true;
    };

    dp[0][0] = true;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 100; j++) {
            if (!dp[i][j]) continue;

            ok(i + 1, j + 1);
            ok(i + 2, j + 1);
            ok(i + 3, j + 1);

        }
    }

    for (int i = 0; i <= 100; i++) {
        if (dp[n][i]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

}

// dp[iマス目に][j回で]行けるか