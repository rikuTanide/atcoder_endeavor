#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;


#define RESIDUE(s, t) (capacity[s][t]-flow[s][t])
#define REP(i, n) for(int i=0;i<(int)n;++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef ll Weight;

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

    vector<int> targets(g);
    rep(i, g) cin >> targets[i];
//    rep(i, g) targets[i]--;

    vector<P> edges(e);
    rep(i, e) cin >> edges[i].first >> edges[i].second;
//    rep(i, e) edges[i].first--;
//    rep(i, e) edges[i].second--;


    Graph graph(n + 1);


    for (P p : edges) {
        graph[p.second].push_back(Edge(p.second, p.first, 1));
        graph[p.first].push_back(Edge(p.first, p.second, 1));
    }

    for (int i : targets) graph[i].push_back(Edge(i, n, 1));
    for (int i : targets) graph[n].push_back(Edge(n, i, 1));
    ll ans = maximumFlow(graph, 0, n);
    cout << ans << endl;
}