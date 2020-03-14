#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef long long ll;
typedef long long ll;
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
const double PI = 3.14159265358979323846;

typedef pair<char, char> P;


int main() {
    int n, a;
    cin >> n >> a;

    vector<int> cards(n);
    rep(i, n)cin >> cards[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(50 * n + 1, -1)); // dp[i枚で][にする方法は] = 通り
    dp[0][0] = 1;

    auto set = [&](int i, int j, ll v) {
        assert(i <= n);
        if (j > 50 * n) return;
        if (dp[i][j] == -1) {
            dp[i][j] = v;
        } else {
            dp[i][j] += v;
        }
    };

    rep(i, n) {
        for (int j = n - 1; j >= 0; j--) {
            rep(k, 50 * n + 1) {
                if (dp[j][k] == -1) continue;
                set(j + 1, k + cards[i], dp[j][k]);
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i][a * i] == -1)continue;
        ans += dp[i][a * i];
    }
    cout << ans << endl;

}

