#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
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

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

struct UnionFind {
    vector<int> data;

    UnionFind(int sz) {
        data.assign(sz, -1);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return (false);
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    int find(int k) {
        if (data[k] < 0) return (k);
        return (data[k] = find(data[k]));
    }

    int size(int k) {
        return (-data[find(k)]);
    }
};

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


template<typename T>
T kruskal(Edges<T> &edges, int V) {
    sort(begin(edges), end(edges), [](const edge<T> &a, const edge<T> &b) {
        return (a.cost < b.cost);
    });
    UnionFind tree(V);
    T ret = 0;
    for (auto &e : edges) {
        if (tree.unite(e.src, e.to)) ret += e.cost;
    }
    return (ret);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    Edges<ll> edges;

    rep(i, n) {
        ll cost;
        cin >> cost;
        edge<ll> e1(n, i, cost);
        edge<ll> e2(i, n, cost);
        edges.push_back(e1);
        edges.push_back(e2);
    }

    rep(i, m) {
        int from, to;
        ll cost;
        cin >> from >> to >> cost;
        from--;
        to--;
        edge<ll> e1(from, to, cost);
        edge<ll> e2(to, from, cost);
        edges.push_back(e1);
        edges.push_back(e2);
    }


    ll ans = kruskal(edges, n + 1);
    cout << ans << endl;

}
