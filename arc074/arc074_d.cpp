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

#define RESIDUE(s, t) (capacity[s][t]-flow[s][t])

Weight maximumFlow(const Graph &g, int s, int t) {
    int n = g.size();
    Matrix flow(n, Array(n)), capacity(n, Array(n));
    rep(u, n) for (auto e : g[u]) capacity[e.src][e.dst] += e.weight;

    Weight total = 0;
    while (1) {
        queue<int> Q;
        Q.push(s);
        vector<int> prev(n, -1);
        prev[s] = s;
        while (!Q.empty() && prev[t] < 0) {
            int u = Q.front();
            Q.pop();
            for (auto e : g[u])
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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> grid[y][x];


    Graph graph(h + w + 2);

    int si = h + w;
    int gi = h + w + 1;

    auto get = [&](char c) -> P {
        rep(y, h) rep(x, w) if (grid[y][x] == c) return P(y, x);
        __throw_runtime_error("konai");
    };

    P s = get('S'), g = get('T');

    vector<P> v = [&] {
        vector<P> all;
        rep(y, h) rep(x, w) if (grid[y][x] == 'o') all.emplace_back(y, x);
        return all;
    }();

    auto push = [&](int i, int j, ll cost) {
        graph[i].push_back(Edge(i, j, cost));
        graph[j].push_back(Edge(j, i, cost));
    };

    auto vertical = [&](int i) {
        return i;
    };

    auto horizontal = [&](int i) {
        return h + i;
    };

    push(si, vertical(s.first), INF);
    push(si, horizontal(s.second), INF);

    push(gi, vertical(g.first), INF);
    push(gi, horizontal(g.second), INF);

    for (P p: v) {
        push(vertical(p.first), horizontal(p.second), 1);
    }

    ll ans = maximumFlow(graph, si, gi);
    cout << (ans >= INF ? -1 : ans) << endl;

}
