#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;

vector<int> to[1005];
int n;

vector<int> bfs(int sv) {
    vector<int> dist(n, INF), pre(n, -1);

    queue<int> q;
    dist[sv] = 0;
    q.push(sv);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : to[v]) {
            if (dist[u] != INF) continue;
            pre[u] = v;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }

    pair<int, int> best(INF, -1);

    rep(v, n) {
        if (v == sv) continue;
        for (int u : to[v]) {
            if (u == sv) {
                best = min(best, make_pair(dist[v], v));
            }
        }
    }

    if(best.first == INF) return vector<int>(n+1);

    int v = best.second;
    vector<int>res;
    while(v != -1) {
        res.push_back(v);
        v = pre[v];
    }
    return res;
}

int main() {

    int m;
    cin >> n >> m;

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        to[a].push_back(b);
    }

    vector<int> ans(n + 1);
    rep(s, n) {
        vector<int> now = bfs(s);
        if (now.size() < ans.size()) ans = now;
    }

    if (ans.size() == n + 1) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans.size() << endl;
    for (int v : ans) {
        cout << v + 1 << endl;
    }
}
