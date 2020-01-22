#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

// http://www.prefield.com/algorithm/graph/graph.html
#define RESIDUE(s, t) (capacity[s][t]-flow[s][t])
typedef int Weight;

struct Edge {
    int src, dst;
    Weight weight;

    Edge(int src, int dst, Weight weight) :
            src(src), dst(dst), weight(weight) {}
};

bool operator<(const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
           e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

Weight maximumFlow(const Graph &g, int s, int t) {
    int n = g.size();
    Matrix flow(n, Array(n)), capacity(n, Array(n));
    rep(u, n) for (auto e: g[u]) capacity[e.src][e.dst] += e.weight;

    Weight total = 0;
    while (true) {
        queue<int> Q;
        Q.push(s);
        vector<int> prev(n, -1);
        prev[s] = s;
        while (!Q.empty() && prev[t] < 0) {
            int u = Q.front();
            Q.pop();
            for (auto e: g[u])
                if (prev[e.dst] < 0 && RESIDUE(u, e.dst) > 0) {
                    prev[e.dst] = u;
                    Q.push(e.dst);
                }
        }
        if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
        Weight inc = INF;
        for (int j = t; prev[j] != j; j = prev[j])
            inc = min(inc, RESIDUE(prev[j], j));
        for (int j = t; prev[j] != j; j = prev[j])
            flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
        total += inc;
    }
}

int main() {
    int n, g, e;
    cin >> n >> g >> e;

    vector<int> bugs(g);
    rep(i, g) cin >> bugs[i];

    Graph graph(n + 1);
    rep(i, e) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(Edge(a, b, 1));
        graph[b].push_back(Edge(b, a, 1));
    }

    rep(i, g) {
        int bug = bugs[i];
        graph[bug].push_back(Edge(bug, n, 1));
        graph[n].push_back(Edge(n, bug, 1));
    }

    int ans = maximumFlow(graph, 0, n);
    cout << ans << endl;


}
