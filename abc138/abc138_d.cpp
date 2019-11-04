#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const int INF = 1001001001;

vector<int> tos[200005];
vector<int> ans;

void dfs(int v, int p = -1) {
    for (int u : tos[v]) {
        if (u == p)continue;
        ans[u] += ans[v];
        dfs(u, v);
    }
}

int main() {

    int n, q;
    cin >> n >> q;

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tos[a].push_back(b);
        tos[b].push_back(a);
    }
    ans.resize(n);
    rep(i, q) {
        int p, x;
        cin >> p >> x;
        p--;
        ans[p] += x;
    }

    dfs(0);
    rep(i, n) {
        cout << ans[i] << ' ';
    }
}
