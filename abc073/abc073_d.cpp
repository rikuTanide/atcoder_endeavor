#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

vector<vector<ll>> dp;

// https://kamino.hatenablog.com/entry/cpp-permutation-combination
void foreach_permutation(int n, std::function<void(int *)> f) {
    int indexes[n];
    for (int i = 0; i < n; i++) indexes[i] = i;
    do {
        f(indexes);
    } while (std::next_permutation(indexes, indexes + n));
}

// https://qiita.com/okaryo/items/8e6cd73f8a676b7a5d75
void warshall_floyd(int n) {
    for (int k = 0; k < n; k++) {       // 経由する頂点
        for (int i = 0; i < n; i++) {    // 始点
            for (int j = 0; j < n; j++) {  // 終点
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main() {

    ll n, m, r;
    cin >> n >> m >> r;

    vector<ll> targets(r);
    rep(i, r) {
        ll t;
        cin >> t;
        t--;
        targets[i] = t;
    }

    dp = vector<vector<ll>>(n, vector<ll>(n, INF));
    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        dp[a][b] = c;
        dp[b][a] = c;
    }
    warshall_floyd(n);


    ll ans = INF;
    foreach_permutation(r, [&](int *indexes) {
        ll now = 0;
        for (ll k = 0; k < r - 1; k++) {
            ll from = targets[indexes[k]];
            ll to = targets[indexes[k + 1]];

            now += dp[from][to];
        }
        cmin(ans, now);
    });
    cout << ans << endl;

}