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

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


struct Edge {
    int to, color;
    ll cost;
};


ll rec(vector<vector<Edge>> &g, int start, int now, int goal, int prev) {
    if (goal == now) return 0;

    for (Edge e : g[now]) {
        if (e.to == prev) continue;
        ll c = rec(g, start, e.to, goal, now);
        if (c == -1) continue;
        return c + e.cost;
    }
    return -1;
}

struct Query {
    int color;
    ll cost;
    int from, to;

    // <edge, cost>
    map<int, ll> costs;
    map<int, ll> counts;
};

std::istream &operator>>(std::istream &in, Query &o) {
    cin >> o.color >> o.cost >> o.from >> o.to;
    o.color--;
    o.from--;
    o.to--;
    return in;
}

void dfs1(vector<ll> &plain_costs, int now, vector<vector<Edge>> &edges) {
    for (Edge e : edges[now]) {
        int next = e.to;
        if (plain_costs[next] != -1) continue;
        plain_costs[next] = plain_costs[now] + e.cost;
        dfs1(plain_costs, next, edges);
    }
}

template<typename G>
struct DoublingLowestCommonAncestor {
    const int LOG;
    vector<int> dep;
    const G &g;
    vector<vector<int> > table;

    DoublingLowestCommonAncestor(const G &g) : g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size())) {
        table.assign(LOG, vector<int>(g.size(), -1));
    }

    void dfs(int idx, int par, int d) {
        table[0][idx] = par;
        dep[idx] = d;
        for (auto &to : g[idx]) {
            if (to != par) dfs(to, idx, d + 1);
        }
    }

    void build() {
        dfs(0, -1, 0);
        for (int k = 0; k + 1 < LOG; k++) {
            for (int i = 0; i < table[k].size(); i++) {
                if (table[k][i] == -1) table[k + 1][i] = -1;
                else table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    int query(int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        for (int i = LOG - 1; i >= 0; i--) {
            if (((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; i--) {
            if (table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }
};

void dfs2(vector<vector<Edge>> &edges,
          int now,
          int prev,
          vector<ll> &colors_costs,
          vector<int> &color_counts,
          vector<vector<int>> &query_indexes,
          vector<Query> &query) {

    for (int qi : query_indexes[now]) {
        Query &q = query[qi];
        q.costs[now] = colors_costs[q.color];
        q.counts[now] = color_counts[q.color];
    }

    for (Edge e : edges[now]) {
        if (e.to == prev) continue;
        colors_costs[e.color] += e.cost;
        color_counts[e.color]++;
        dfs2(edges, e.to, now, colors_costs, color_counts, query_indexes, query);
        colors_costs[e.color] -= e.cost;
        color_counts[e.color]--;

    }

}

template<typename T>
struct edge {
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x) {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template<typename T>
using Edges = vector<edge<T> >;
template<typename T>
using WeightedGraph = vector<Edges<T> >;
using UnWeightedGraph = vector<vector<int> >;
template<typename T>
using Matrix = vector<vector<T> >;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<Edge>> edges(n);

    UnWeightedGraph g(n);
    rep(i, n - 1) {
        int from, to, color;
        ll cost;
        cin >> from >> to >> color >> cost;
        from--;
        to--;
        color--;
        edges[from].push_back({to, color, cost});
        edges[to].push_back({from, color, cost});

        g[from].push_back(to);
        g[to].push_back(from);
    }

    DoublingLowestCommonAncestor<UnWeightedGraph> lca(g);
    lca.build();

    vector<ll> plain_costs(n, -1);
    plain_costs[0] = 0;
    dfs1(plain_costs, 0, edges);

    vector<Query> queries(q);
    rep(i, q) cin >> queries[i];

    vector<vector<int>> query_indexes(n);
    rep(i, q) {
        Query q = queries[i];
        query_indexes[q.from].push_back(i);
        query_indexes[q.to].push_back(i);
        int l = lca.query(q.from, q.to);
        query_indexes[l].push_back(i);
    }

    vector<ll> colors_costs(n, 0);
    vector<int> colors_count(n, 0);
    dfs2(edges, 0, -1, colors_costs, colors_count, query_indexes, queries);

    for (Query &q: queries) {
        int l = lca.query(q.from, q.to);
        ll plain = plain_costs[q.from] + plain_costs[q.to] - plain_costs[l] * 2;
        ll color_cost = q.costs[q.from] + q.costs[q.to] - q.costs[l] * 2;
        ll count = q.counts[q.from] + q.counts[q.to] - q.counts[l] * 2;
        ll add = count * q.cost;
        cout << plain - color_cost + add << endl;
    }
}
