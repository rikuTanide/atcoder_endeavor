#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct Edge {
    int to, id;
};

bool dfs(int u, int v, vector<vector<Edge>> &edges, int parent, vector<int> &route) {
    if (u == v) {
        return true;
    }
    for (Edge w : edges[u]) {
        if (w.to == parent) continue;
        bool b = dfs(w.to, v, edges, u, route);
        if (b) {
            route.push_back(w.id);
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<vector<Edge>> edges(n);

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        edges[a].push_back({b, i});
        edges[b].push_back({a, i});
    }

    int m;
    cin >> m;

    vector<ll> routes(m);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        vector<int> route;
        dfs(u, v, edges, -1, route);

        ll route_bit = 0;
        for (int r : route) {
            route_bit |= (1ll << r);
        }
        routes[i] = route_bit;
    }

    ll ans = 0;
    rep(i, 1 << m) {
        ll j = 0;
        rep(k, m) {
            if ((i >> k) & 1) {
                j |= routes[k];
            }
        }
        int white = __builtin_popcountll(j);
        ll now = 1ll <<(n - 1 - white);
        if (__builtin_popcount(i) % 2 == 0) {
            ans += now;
        } else {
            ans -= now;
        }
    }

    cout << ans << endl;
}
