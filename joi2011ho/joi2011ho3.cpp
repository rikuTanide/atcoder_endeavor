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

public:
    vector<vector<Edge>> edges;

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
    int n, m, k;
    cin >> n >> m >> k;

    Dijkstra dijkstra(n + 1);

    rep(_, m) {
        int a, b;
        ll cost;
        cin >> a >> b >> cost;
        a--;
        b--;
        dijkstra.insertTowWay(a, b, cost);
    }

    rep(_, k) {
        int s;
        cin >> s;
        s--;
        dijkstra.insertTowWay(s, n, 0);
    }

    dijkstra.dijkstra(n);

    ll ans = 0;
    rep(i, n) cmax(ans, dijkstra.distance(i));

    rep(a, n) {
        for (Edge e : dijkstra.edges[a]) {
            int b = e.to;
            ll la = max(dijkstra.distance(a), dijkstra.distance(b));
            ll sm = min(dijkstra.distance(a), dijkstra.distance(b));
            ll diff = la - sm;
            assert(!(diff > e.cost));
            ll cost = (e.cost - diff + 1) / 2 + la;
            cmax(ans, cost);
        }
    }

    cout << ans << endl;

}