#include <bits/stdc++.h>
//#include "atcoder/all"
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


// https://qiita.com/ta-ka/items/a023a11efe17ab097433
struct Edge {
    ll to, cost;
};


class Dijkstra {
    ll vector_count;

    vector<ll> distances;
    vector<vector<Edge>> edges;

public:
    Dijkstra(ll n) {
        vector_count = n;
        distances.resize(n, INF);
        edges.resize(n);
    }

    void insertTowWay(ll from, ll to, ll cost) {
        edges[from].push_back({to, cost});
        edges[to].push_back({from, cost});
    }

    void insert(ll from, ll to, ll cost) {
        edges[from].push_back({to, cost});
    }

    void dijkstra(ll k) {
        distances[k] = 0;  // 始点sへの最短距離は0

        priority_queue<P, vector<P>, greater<P>> que;  // 距離が小さい順に取り出せるようgreater<P>を指定
        que.push(P(0, k));
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;  // 更新した頂点の中で距離が最小の頂点v
            if (distances[v] < p.first) {
                continue;
            }
            for (auto e : edges[v]) {  // 頂点vから出る辺eを走査
                if (distances[e.to] > distances[v] + e.cost) {
                    distances[e.to] = distances[v] + e.cost;
                    que.push(P(distances[e.to], e.to));
                }
            }
        }
    }

    ll distance(ll to) {
        return distances[to];
    }

};


struct Route {
    int p, q, cost;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<P> points(n);
    for (P &p:points)cin >> p.first >> p.second;

    vector<Route> routes(m);
    for (Route &r:routes)cin >> r.p >> r.q >> r.cost, r.p--, r.q--;

    auto can_pass = [&](int prev, int now, int next) -> bool {

        P v = points[now];
        P e1 = points[prev];
        P e2 = points[next];

        e1.first -= v.first;
        e1.second -= v.second;
        e2.first -= v.first;
        e2.second -= v.second;

        double tan1 = atan2(e1.second, e1.first);
        double tan2 = atan2(e2.second, e2.first);

        if (tan1 < 0) tan1 += PI * 2;
        if (tan2 < 0) tan2 += PI * 2;

        double tan = abs(tan1 - tan2);
        tan = min(tan, PI * 2 - tan);
        return tan >= PI / 2 - EPS;

    };

    vector<vector<ll>> costs(n, vector<ll>(n, -1));
    for (Route r : routes) costs[r.p][r.q] = r.cost;
    for (Route r : routes) costs[r.q][r.p] = r.cost;

    auto has_road = [&](int a, int b) -> bool {
        return costs[a][b] >= 0;
    };

    auto get_cost = [&](int a, int b) -> ll {
        return costs[a][b];
    };

    Dijkstra dijkstra(n * n + 2);
    auto add = [&](int prev, int now, int next, ll cost) {
        int from = now * n + prev;
        int to = next * n + now;

        dijkstra.insert(from, to, cost);
    };

    rep(prev, n) {
        rep(now, n) {
            rep(next, n) {
                if (prev == now) continue;
                if (now == next) continue;
                if (prev == next) continue;

                if (!can_pass(prev, now, next))continue;
                if (!has_road(now, next)) continue;
                if (!has_road(prev, now)) continue;

                int cost = get_cost(now, next);

                add(prev, now, next, cost);
            }
        }
    }

    rep(i, n) {
        if (i != 0) {
            if (costs[0][i] != -1) {
                dijkstra.insert(0, n * i, costs[0][i]);
            }
        }
    }

    rep(i, n) dijkstra.insert(n * n, i, 0);
    rep(i, n) dijkstra.insert(1 * n + i, n * n + 1, 0);

    dijkstra.dijkstra(n * n);

    ll k = dijkstra.distance(n * n + 1);
    ll ans = k >= INF ? -1 : k;
    cout << ans << endl;


}