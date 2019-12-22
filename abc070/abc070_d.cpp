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

struct Edge {
    ll to, cost;
};

vector<ll> distances;
ll vector_count;
vector<vector<Edge>> edges;

void dijkstra(int k) {
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

int main() {
    cin >> vector_count;
    edges.resize(vector_count);
    distances.resize(vector_count, INF);

    rep(i, vector_count - 1) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[b].push_back({a, c});
        edges[a].push_back({b, c});
    }

    ll q, k;
    cin >> q >> k;
    k--;

    dijkstra(k);

    rep(i, q) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << distances[x] + distances[y] << endl;
    }

}