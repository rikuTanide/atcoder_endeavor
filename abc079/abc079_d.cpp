#include <bits/stdc++.h>
#include <cmath>

using namespace std;
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

vector<vector<int>> dp(13, vector<int>(13, -1));

int dfs(int from, set<int> &route, int max_cost, int current_cost) {
    int ans = min(max_cost, current_cost + dp[from][1]);
    for (int i = 0; i <= 9; i++) {
        if (i == 1) continue;
        if (i == from)continue;
        if (route.find(i) != route.end()) continue;
        int next_cost = dp[from][i];
        if (current_cost + next_cost >= max_cost) continue;

        route.insert(i);
        int now = dfs(i, route, max_cost, current_cost + dp[from][i]);
        cmin(ans, now);
        route.erase(i);
    }
    return ans;
}

int main() {
    int h, w;
    cin >> h >> w;

    for (int y = 0; y <= 9; y++) {
        for (int x = 0; x <= 9; x++) {
            cin >> dp[y][x];
        }
    }
    set<int> route;

    vector<int> costs(10);
    for (int i = 2; i <= 9; i++) {
        route.insert(i);
        int now = dfs(i, route, dp[i][1], 0);
        route.erase(i);
        costs[i] = now;
    }

    int ans = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int i;
            cin >> i;
            if(i == -1 || i == 1)continue;
            ans += costs[i];
        }
    }
    cout << ans << endl;
}