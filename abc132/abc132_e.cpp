#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;

int dist[1000005][3];

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
    }
    int sv, tv;
    cin >> sv >> tv;
    sv--;
    tv--;

    rep(i, n)rep(j, 3) dist[i][j] = INF;

    queue<P> q;
    q.push(P(sv, 0));
    dist[sv][0] = 0;

    while (!q.empty()) {
        int v = q.front().first;
        int l = q.front().second;
        q.pop();
        for (int u : to[v]) {
            int nl = (l + 1) % 3;
            if (dist[u][nl] != INF)continue;
            dist[u][nl] = dist[v][l] + 1;
            q.push(P(u, nl));
        }
    }
    int ans = dist[tv][0];
    if (ans == INF) ans = -1;
    else ans /= 3;
    cout << ans << endl;
}