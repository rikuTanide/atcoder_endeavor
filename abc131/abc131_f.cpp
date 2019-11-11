#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
const ll INF = 1001001001;

const int mod = 1000000007;

const int V = 100005;

vector<int> to[V * 2];
bool visited[V * 2];
vector<int> cnt;

void dfs(int v) {
    if (visited[v]) return;
    visited[v] = true;
    cnt[v / V]++;

    for (int u : to[v]) {
        dfs(u);
    }
}

int main() {
    int n;
    cin >> n;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        y += V;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    ll ans = 0;
    rep(i, V * 2) {
        if (visited[i])continue;
        cnt = vector<int>(2);
        dfs(i);
        ans += (ll) cnt[0] * cnt[1];
    }
    ans -= n;
    cout << ans << endl;

}