#include <bits/stdc++.h>
#include <cmath>


#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;
typedef vector<vector<int>> Graph;

struct Edge {
    int from;
    int to;
    ll cost;
};

// https://qiita.com/ta-ka/items/a023a11efe17ab097433
ll dijkstra(int start, int end, int vertex_count, vector<vector<Edge>> &edges, vector<ll> &distances) {
    distances[start] = 0;  // 始点sへの最短距離は0

    priority_queue<P, vector<P>, greater<P>> que;  // 距離が小さい順に取り出せるようgreater<P>を指定
    que.push(P(0, start));

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
    return distances[end];
}

int main() {

    int n;
    cin >> n;
    vector<Edge> shortness;

    rep(a, n)rep(b, n) {
            ll d;
            cin >> d;
            shortness.push_back({a, b, d});
        }

    sort(shortness.begin(), shortness.end(), [&](Edge e, Edge f) {
        return e.cost < f.cost;
    });

    vector<vector<Edge>> edges(n);
    vector<vector<ll>> distances(n, vector<ll>(n, INF));


    for (Edge e : shortness) {
        ll length = dijkstra(e.from, e.to, n, edges, distances[e.from]);
        if (length > e.cost) {
            edges[e.from].push_back(e);
        } else if (length == e.cost) {

        } else {
            cout << -1 << endl;
            return 0;
        }
    }


    ll ans = 0;
    for (auto es : edges) {
        for (auto e : es) {
            ans += e.cost;
        }
    }

    cout << (ans / 2) << endl;

}
