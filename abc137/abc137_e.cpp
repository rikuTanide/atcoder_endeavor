#include <bits/stdc++.h>
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

struct Edge {
    ll to, cost;
};


// 特定のルートまでに閉路があるか調べたいならこう
// https://atcoder.jp/contests/abc061/submissions/12926139
// https://atcoder.jp/contests/abc137/submissions/13373201
vector<ll> bellman_ford(int n, int s, vector<vector<Edge> > &graph) { // nは頂点数、sは開始頂点
    vector<ll> dist(n, INF);
    dist[s] = 0; // 開始点の距離は0
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            for (int k = 0; k < graph[v].size(); k++) {
                Edge e = graph[v][k];
                if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            for (int k = 0; k < graph[v].size(); k++) {
                Edge e = graph[v][k];
                if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = -INF;
                }
            }
        }
    }

    return dist;
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<vector<Edge>> g(n);

    rep(_, m) {
        int a, b, c;
        cin >> a >> b >> c;

        a--;
        b--;
        c -= p;

        g[a].push_back(Edge{b, -c});

    }

    vector<ll> costs = bellman_ford(n, 0, g);
    ll ans = costs[n - 1] <= -INF ? -1 : max<ll>(-costs[n - 1], 0);
    cout << ans << endl;
}
