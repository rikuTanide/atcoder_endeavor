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

struct Train {
    int u, v, silver;
    ll time;
};

struct Exchange {
    ll silver, time;
};
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

int main() {
    int n, m;
    ll s;
    cin >> n >> m >> s;

    vector<Train> trains(m);
    for (Train &train: trains) cin >> train.u >> train.v >> train.silver >> train.time;
    for (Train &train: trains) train.u--, train.v--;
    vector<Exchange> exchanges(n);

    for (Exchange &exchange : exchanges)cin >> exchange.silver >> exchange.time;

    int ma = 5000;
//    int ma = 5;

    Dijkstra dijkstra(n * (ma + 1));

    auto to_id = [&](int si, int id) {
        return id * (ma + 1) + si;
    };

    auto add = [&](int from, int to, int silver, ll time) {
        for (int si = 0; si <= ma; si++) {
            int to_si = si + silver;
            if (to_si < 0) continue;
            if (to_si > ma) continue;

            dijkstra.insert(to_id(si, from), to_id(to_si, to), time);
        }
    };

    for (Train t : trains) {
        add(t.u, t.v, -t.silver, t.time);
        add(t.v, t.u, -t.silver, t.time);
    }

    rep(i, n) {
        Exchange e = exchanges[i];
        add(i, i, e.silver, e.time);
    }


    rep(si_from, ma) {
        if (si_from > s) continue;
        dijkstra.insertTowWay(0, si_from, 0);
    }


    dijkstra.dijkstra(0);
    rep(i, n) {
        if (i == 0) continue;
        ll ans = INF;
        rep(si, ma) cmin(ans, dijkstra.distance(to_id(si, i)));
        cout << ans << endl;
    }

}