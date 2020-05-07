#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

typedef pair<ll, ll> P;

struct Edge {
    ll to, cost;
};

bool bellman_ford(int n, int s, vector<vector<Edge> > &graph, vector<ll> &dist) { // nは頂点数、sは開始頂点

    dist[s] = 0; // 開始点の距離は0
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            for (int k = 0; k < graph[v].size(); k++) {
                Edge e = graph[v][k];
                if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
//                    if (i == n - 1) return true; // n回目にも更新があるなら負の閉路が存在
                }
            }
        }
    }
    return false;
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);

    rep(i, m) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        c = -c;
        graph[a].push_back({b, c});
    }

    vector<ll> dist(n, INF);
    bellman_ford(n, 0, graph, dist);
    ll mi1 = dist[n - 1];
    bellman_ford(n, 0, graph, dist);
    ll mi2 = dist[n - 1];

    if (mi1 != mi2) {
        cout << "inf" << endl;
        ret();
    }
    ll mi = dist[n - 1];
    cout << -mi << endl;

}
