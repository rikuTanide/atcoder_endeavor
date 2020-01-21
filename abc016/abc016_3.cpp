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
const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

void warshall_floyd(int n, vector<vector<int>> &distances) {
    for (int k = 0; k < n; k++) {       // 経由する頂点
        for (int i = 0; i < n; i++) {    // 始点
            for (int j = 0; j < n; j++) {  // 終点
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int >> distances(n, vector<int>(n, INF));

    rep(i, n) {
        distances[i][i] = 0;
    }
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        distances[a][b] = 1;
        distances[b][a] = 1;
    }
    warshall_floyd(n, distances);

    rep(i, n) {
        int ans = 0;
        rep(j, n) {
            if (distances[i][j] == 2) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}