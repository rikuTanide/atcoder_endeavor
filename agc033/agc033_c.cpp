#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
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

struct Query {
    char c, d;
};

std::istream &operator>>(std::istream &in, Query &o) {
    cin >> o.c >> o.d;
    return in;
}


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
typedef pair<Weight, int> Result;

Result visit(int p, int v, const Graph &g) {
    Result r(0, v);
    FOR(e, g[v]) if (e->dst != p) {
            Result t = visit(v, e->dst, g);
            t.first += e->weight;
            if (r.first < t.first) r = t;
        }
    return r;
}

Weight diameter(const Graph &g) {
    Result r = visit(-1, 0, g);
    Result t = visit(-1, r.second, g);
    return t.first; // (r.second, t.second) is farthest pair
}

int main() {
    int n;
    cin >> n;

    Graph graph(n);

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(Edge(a, b, 1));
        graph[b].push_back(Edge(b, a, 1));
    }

    int p = diameter(graph);

    string ans = p % 3 == 1 ? "Second" : "First";
    cout << ans << endl;
}