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

void warshall_floyd(ll n, vector<vector<ll>> &distances) {
    for (ll k = 0; k < n; k++) {       // 経由する頂点
        for (ll i = 0; i < n; i++) {    // 始点
            for (ll j = 0; j < n; j++) {  // 終点
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> distances(n, vector<ll>(n, INF));
    rep(i, n) distances[i][i] = 0;
    rep(i, m) {
        int a, b, t;
        cin >> a >> b >> t;
        a--;
        b--;
        distances[a][b] = t;
        distances[b][a] = t;
    }
    warshall_floyd(n, distances);

    ll ans = INF;
    for (ll i = 0; i < n; i++) {
        ll now = 0;
        for (ll j = 0; j < n; j++) {
            ll t = distances[i][j];
            cmax(now, t);
        }
        cmin(ans, now);
    }
    cout << ans << endl;

}