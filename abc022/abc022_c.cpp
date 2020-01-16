#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
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

// https://qiita.com/ta-ka/items/a023a11efe17ab097433
struct Edge {
    ll id, to, cost;
};

struct Shortness {
    ll value;
    set<ll> route;
};

class RouteDijkstra {
    ll vector_count;

    vector<Shortness> distances;
    vector<vector<Edge>> edges;

public:
    RouteDijkstra(ll n) {
        vector_count = n;
        distances.resize(n, Shortness{INF, set<ll>()});
        edges.resize(n);
    }

    void insertTowWay(ll id, ll from, ll to, ll cost) {
        edges[from].push_back({id, to, cost});
        edges[to].push_back({id, from, cost});
    }

    void dijkstra(ll k) {
        distances[k].value = 0;  // 始点sへの最短距離は0

        priority_queue<P, vector<P>, greater<P>> que;  // 距離が小さい順に取り出せるようgreater<P>を指定
        que.push(P(0, k));
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;  // 更新した頂点の中で距離が最小の頂点v
            if (distances[v].value < p.first) {
                continue;
            }
            for (auto e : edges[v]) {  // 頂点vから出る辺eを走査
                if (distances[e.to].value > distances[v].value + e.cost) {
                    distances[e.to].value = distances[v].value + e.cost;
                    distances[e.to].route = distances[v].route;
                    distances[e.to].route.insert(e.id);
                    que.push(P(distances[e.to].value, e.to));
                }
            }
        }
    }

    ll calcDistance(ll to) {
        return distances[to].value;
    }

    set<ll> calcRoute(ll to) {
        return distances[to].route;
    }

};

struct Route {
    ll id, u, v, l;
};

int main() {
    ll n, m;
    cin >> n >> m;

    RouteDijkstra routeDijkstra(n);

    vector<Route> routes(m);

    rep(i, m) {
        ll u, v, l;
        cin >> u >> v >> l;
        u--;
        v--;

        routes[i].id = i;
        routes[i].u = u;
        routes[i].v = v;
        routes[i].l = l;

        routeDijkstra.insertTowWay(i, u, v, l);
    }

    routeDijkstra.dijkstra(0);

    ll ans = INF;
    rep(k, n) {
        ll go = routeDijkstra.calcDistance(k);
        if (go == INF) continue;
        if (k == 0) continue;
        set<ll> used = routeDijkstra.calcRoute(k);

        RouteDijkstra dijkstra(n);
        rep(i, m) {
            if (used.find(i) != used.end())continue;
            Route route = routes[i];
            dijkstra.insertTowWay(route.id, route.u, route.v, route.l);
        }
        dijkstra.dijkstra(0);
        ll back = dijkstra.calcDistance(k);
        if (back == INF) continue;
        ll sum = back + go;
        cmin(ans, sum);

    }

    if (ans == INF) {
        cout << -1 << endl;
        return 0;
    }


    cout << ans << endl;
}
