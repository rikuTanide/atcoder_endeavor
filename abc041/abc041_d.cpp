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
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;


bool bitIn(int i, int j) {
    return i & (1 << j);
}

ll bitNot(ll i, ll j) {
    return i & ~(1 << j);
}

int main() {

    ll n, m;
    cin >> n >> m;

    vector<vector<bool>> graph(n, vector<bool>(n, true));

    rep(i, m) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[y][x] = false;
    }
    vector<ll> dp(1 << n, 0);
    dp[0] = 1;

    for (ll i = 0; i < (1 << n); i++) {
        for (ll j = 0; j < n; j++) {
            if (!bitIn(i, j)) continue;
            ll now = bitNot(i, j);

            bool b = [&] {
                for (ll k = 0; k < n; k++) {
                    if (!bitIn(now, k)) continue;
                    if (graph[k][j] == false) {
                        return false;
                    }
                }
                return true;
            }();
            if (b) {
                dp[i] += dp[now];
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;

}