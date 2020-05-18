#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Edge {
    ll to, cost;
};


// 特定のルートまでに閉路があるか調べたいならこう
// https://atcoder.jp/contests/abc061/submissions/12926139
bool bellman_ford(int n, int s, vector<vector<Edge> > &graph, vector<ll> &dist) { // nは頂点数、sは開始頂点

    dist[s] = 0; // 開始点の距離は0
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            for (int k = 0; k < graph[v].size(); k++) {
                Edge e = graph[v][k];
                if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    if (i == n - 1) return true; // n回目にも更新があるなら負の閉路が存在
                }
            }
        }
    }
    return false;
}


int main() {

    ll n, m, p;
    cin >> n >> m >> p;

    vector<vector<Edge>> edges(n);

    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[a].push_back(Edge{b, -(c - p)});
    }

    vector<ll> dist(n, INF);
    bellman_ford(n, 0, edges, dist);
    ll ans = dist[n - 1];

    bellman_ford(n, 0, edges, dist);

    if (dist[n - 1] != ans || dist[0] < 0) {
        cout << -1 << endl;
    } else {
        cout << max(0ll, -ans) << endl;
    }


}
