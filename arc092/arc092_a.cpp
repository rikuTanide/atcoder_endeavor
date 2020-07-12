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

#define _GLIBCXX_DEBUG

#include <iostream>
#include <vector>

using namespace std;

#define REP(i, n) for(int i=0;i<(int)n;++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef int Weight;

struct Edge {
    int src, dst;
    Weight weight;

    Edge(int src, int dst) :
            src(src), dst(dst) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

bool augment(const Graph &g, int u,
             vector<int> &matchTo, vector<bool> &visited) {
    if (u < 0) return true;
    FOR(e, g[u]) if (!visited[e->dst]) {
            visited[e->dst] = true;
            if (augment(g, matchTo[e->dst], matchTo, visited)) {
                matchTo[e->src] = e->dst;
                matchTo[e->dst] = e->src;
                return true;
            }
        }
    return false;
}

int bipartiteMatching(const Graph &g, int L, Edges &matching) {
    const int n = g.size();
    vector<int> matchTo(n, -1);
    int match = 0;
    REP(u, L) {
        vector<bool> visited(n);
        if (augment(g, u, matchTo, visited)) ++match;
    }
    REP(u, L) if (matchTo[u] >= 0) // make explicit matching
            matching.push_back(Edge(u, matchTo[u]));
    return match;
}

int main() {
    int n;
    cin >> n;

    vector<P> reds(n), blues(n);
    rep(i, n) cin >> reds[i].first >> reds[i].second;
    rep(i, n) cin >> blues[i].first >> blues[i].second;

    Graph g(2 * n);

    rep(i, n) {
        rep(j, n) {
            P red = reds[i], blue = blues[j];
            if (red.first < blue.first && red.second < blue.second) {
                g[i].push_back(Edge(i, j + n));
                g[j + n].push_back(Edge(j + n, i));
            }
        }
    }
    Edges _;
    int ans = bipartiteMatching(g, n, _);
    cout << ans << endl;

}
