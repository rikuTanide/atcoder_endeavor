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

vector<vector<int>> get_graph(int n, vector<P> &edges) {
    vector<vector<int>> graph(n);
    for (P &p:edges) graph[p.first].push_back(p.second);
    return graph;
}

vector<double> solve(int n, vector<P> &edges) {
    auto g = get_graph(n, edges);

    vector<double> dp(n, 0);
    for (int i = n - 2; i >= 0; i--) {
        double now = 0;
        for (int to : g[i]) {
            now += dp[to];
        }
        now /= g[i].size();
        now += 1;
        dp[i] = now;
    }
    return dp;
}

int get_max_e(vector<int> &tos, vector<double> &dp) {
    if (tos.size() == 1) return -1;
    double ma = 0;
    for (int to : tos) cmax(ma, dp[to]);
    for (int to : tos) if (dp[to] == ma) return to;
    __throw_runtime_error("konaide");
}

vector<P> filter_edge(vector<P> edges, P p) {
    auto it = find(edges.begin(), edges.end(), p);
    assert(it != edges.end());
    edges.erase(it);
    return edges;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<P> edges(m);
    for (P &p:edges) cin >> p.first >> p.second, p.first--, p.second--;

    vector<vector<int>> graph = get_graph(n, edges);

    vector<double> plain = solve(n, edges);

    double ans = plain[0];

    rep(i, n - 2) {
        int max_e = get_max_e(graph[i], plain);
        if (max_e == -1) continue;
        vector<P> edge_ignore = filter_edge(edges, P(i, max_e));
        assert(edge_ignore.size() + 1 == edges.size());
        double now = solve(n, edge_ignore)[0];
        cmin(ans, now);
    }
    cout << setprecision(20) << ans << endl;

}