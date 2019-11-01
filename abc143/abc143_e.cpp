#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
int INF = INT_MAX / 3;

int main() {

    int n, m, l;
    cin >> n >> m >> l;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    rep(i, n) dist[i][i] = 0;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        dist[b][a] = dist[a][b] = c;
    }

    rep(k, n) rep(i, n) rep(j, n) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
    vector<vector<int>> dist2(n, vector<int>(n, INF));
    rep(i, n) dist[i][i] = 0;


    rep(i, n) rep(j, n) {
            if (dist[i][j] <= l) {
                dist2[i][j] = 1;
            }
        }
    rep(k, n) rep(i, n) rep(j, n) {
                dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
            }

    int q;
    cin >> q;

    rep(i, q) {
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        int dis = dist2[s][t] - 1;
        if (dist2[s][t] == INF) dis = -1;
        cout << dis << endl;

    }


}
