#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<double, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
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

struct UnionFind {
    vector<int> data;

    UnionFind(int size) : data(size, -1) {}

    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }

    bool findSet(int x, int y) {
        return root(x) == root(y);
    }

    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    int size(int x) {
        return -data[root(x)];
    }
};

pair<Weight, Edges> minimumSpanningForest(const Graph &g) {
    int n = g.size();
    UnionFind uf(n);
    priority_queue<Edge> Q;
    REP(u, n) FOR(e, g[u]) if (u < e->dst) Q.push(*e);

    Weight total = 0;
    Edges F;
    while (F.size() < n - 1 && !Q.empty()) {
        Edge e = Q.top();
        Q.pop();
        if (uf.unionSet(e.src, e.dst)) {
            F.push_back(e);
            total += e.weight;
        }
    }
    return pair<Weight, Edges>(total, F);
}

struct Town {
    int id;
    ll x, y;
};

int main() {
    int n;
    cin >> n;

    vector<Town> v(n);
    rep(i, n) v[i].id = i;
    for (Town &p:v)cin >> p.x >> p.y;

    Graph g(n);

    sort(v.begin(), v.end(), [](Town t1, Town t2) {
        return t1.x < t2.x;
    });

    rep(i, n - 1) {
        Town a = v[i];
        Town b = v[i + 1];
        g[a.id].push_back(Edge(a.id, b.id, b.x - a.x));
        g[b.id].push_back(Edge(b.id, a.id, b.x - a.x));
    }

    sort(v.begin(), v.end(), [](Town t1, Town t2) {
        return t1.y < t2.y;
    });
    rep(i, n - 1) {
        Town a = v[i];
        Town b = v[i + 1];
        g[a.id].push_back(Edge(a.id, b.id, b.y - a.y));
        g[b.id].push_back(Edge(b.id, a.id, b.y - a.y));
    }

    auto ans = minimumSpanningForest(g);
    cout << ans.first << endl;

}