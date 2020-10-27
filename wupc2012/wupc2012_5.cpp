#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

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

typedef vector<ll> V; // { cost, town, 4 || 7}

class Dijkstra {
    ll vector_count;

    vector<vector<ll>> distances4;
    vector<vector<ll>> distances7;
    vector<vector<Edge>> edges;

public:
    Dijkstra(ll n) {
        vector_count = n;
        distances4.resize(4, vector<ll>(n, INF));
        distances7.resize(7, vector<ll>(n, INF));
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
        distances4[0][k] = 0;  // 始点sへの最短距離は0
        distances7[0][k] = 0;  // 始点sへの最短距離は0

        priority_queue<V, vector<V>, greater<V>> que;  // 距離が小さい順に取り出せるようgreater<P>を指定
        que.push({0, k, 4});
        que.push({0, k, 7});

        while (!que.empty()) {
            V p = que.top();
            que.pop();
            int v = p[1];  // 更新した頂点の中で距離が最小の頂点v

            int prev = p[2] == 4 ? distances4[p[0] % 4][v] : distances7[p[0] % 7][v];
            if (prev < p[0]) {
                continue;
            }
            for (auto e : edges[v]) {
                ll next_cost = prev + e.cost;
                if (distances4[next_cost % 4][e.to] > next_cost) {
                    distances4[next_cost % 4][e.to] = next_cost;
                    que.push(vector<ll>{next_cost, e.to, 4});
                }
            }

            for (auto e : edges[v]) {
                ll next_cost = prev + e.cost;
                if (distances7[next_cost % 7][e.to] > next_cost) {
                    distances7[next_cost % 7][e.to] = next_cost;
                    que.push(vector<ll>{next_cost, e.to, 7});
                }
            }

        }
    }

    ll distance(ll to) {
        return min(distances4[0][to], distances7[0][to]);
    }

};

int main() {
    int n, m;
    cin >> n >> m;
    Dijkstra dijkstra(n);
    rep(_, m) {
        int a, b;
        ll cost;
        cin >> a >> b >> cost;

        if (a > b) swap(a, b);

        if (b != n - 1)dijkstra.insertTowWay(a, b, cost);
        else dijkstra.insert(a, b, cost);
    }
    dijkstra.dijkstra(0);
    cout << dijkstra.distance(n - 1) << endl;
}
