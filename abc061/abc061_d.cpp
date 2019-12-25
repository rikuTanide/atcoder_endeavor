#include <bits/stdc++.h>
#include <cmath>

#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

// https://qiita.com/wakimiko/items/69b86627bea0e8fe29d5
struct Edge {
    ll from; //出発点
    ll to;   //到達点
    ll cost; //移動コスト
};

ll bellmanFord(ll v, ll s, ll g, vector<Edge> &routes) {

    vector<ll> costs(v, INF);
    vector<bool> hasLoop(v, false);
    costs[s] = 0;

    for (ll i = 0; i < v - 1; i++) {
        for (ll j = 0; j < (ll) routes.size(); j++) {
            Edge e = routes[j];
            if (costs[e.to] > costs[e.from] + e.cost) {  //移動した後のコストが小さいと、頂点のコストを更新
                costs[e.to] = costs[e.from] + e.cost;
            }
        }
    }
    for (ll j = 0; j < v; j++) {
        for (ll i = 0; i < (ll) routes.size(); i++) {
            ll f = routes[i].from;
            ll t = routes[i].to;
            ll c = routes[i].cost;
            if (costs[f] == INF) continue;
            if (costs[f] + c < costs[t]) hasLoop[t] = true;
            if (hasLoop[f])hasLoop[t] = true;
        }
    }
    if (hasLoop[g] == true) return MINF;
    return costs[g];
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<Edge> routes(m);

    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c = -c;
        Edge edge = {a, b, c};
        routes[i] = edge;
    }

    ll ans = bellmanFord(n, 0, n - 1, routes);

    if (ans == MINF) {
        cout << "inf" << endl;
        return 0;
    }

    cout << -ans << endl;
}

