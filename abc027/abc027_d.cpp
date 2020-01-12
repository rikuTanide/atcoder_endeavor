#include <bits/stdc++.h>
#include <cmath>

using namespace std;
//typedef long long ll;
typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll INF = 1e15;
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
    string s;
    cin >> s;
    int n = s.size();

    assert(n <= 1000);
    vector<map<int, int>> dp(n + 1, map<int, int>());
    dp[0][0] = 0;

    auto mcmax = [&](int i, int j, int value) {
        if (dp[i].find(j) == dp[i].end()) {
            dp[i][j] = value;
        } else {
            cmax(dp[i][j], value);
        }
    };

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'M') {
            for (auto p : dp[i]) {
                mcmax(i + 1, p.first + 1, dp[i][p.first]);
            }
            for (auto p : dp[i]) {
                mcmax(i + 1, p.first - 1, dp[i][p.first]);
            }
        } else if (c == '+') {
            for (auto p : dp[i]) {
                dp[i + 1][p.first] = dp[i][p.first] + p.first;
            }
        } else if (c == '-') {
            for (auto p : dp[i]) {
                dp[i + 1][p.first] = dp[i][p.first] - p.first;
            }
        }
    }

    cout << dp[s.size()][0] << endl;

}
