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
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

// http://kirika-comp.hatenablog.com/entry/2018/01/29/020648

P add(P a, P b) {
    if (a.first != b.first) return min(a, b);
    return P(a.first, (a.second + b.second) % mod);
}

P mul(P a, P b) {
    return P(a.first + b.first, a.second * b.second % mod);
}

vector<P> calc(int n, int s, vector<vector<P>> &edges) {
    vector<P> dp(n, P(INF, 0));
    vector<bool> vis(n, false);
    priority_queue<P, vector<P>, greater<P> > que;
    dp[s] = P(0, 1);
    que.push(P(0, s));
    while (not que.empty()) {
        P vd = que.top();
        que.pop();
        int v = vd.second;
        if (vis[v]) continue;
        vis[v] = true;
        rep(i, edges[v].size()) {
            P wc = edges[v][i];
            int w = wc.first;
            ll c = wc.second;
            dp[w] = add(dp[w], mul(dp[v], P(c, 1)));
            que.push(P(dp[w].first, w));
        }
    }
    return dp;
}

int main() {
    int n;
    cin >> n;
    vector<vector<P>> edges(n);


    int a, b;
    cin >> a >> b;
    a--;
    b--;
    int m;
    cin >> m;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        edges[x].push_back(P(y, 1));
        edges[y].push_back(P(x, 1));

    }

    auto ans = calc(n, a, edges);

    cout << ans[b].second << endl;
}