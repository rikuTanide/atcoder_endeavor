#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

typedef pair<ll, ll> P;


struct Town {
    ll x, y;
    int town_id;
};

std::istream &operator>>(std::istream &in, Town &o) {
    cin >> o.x >> o.y;
    return in;
}

template<typename T>
struct edge {
    int src, to;
    T cost;

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
    int n;
    cin >> n;

    vector<Town> towns(n);
    rep(i, n) cin >> towns[i], towns[i].town_id = i;

    Edges<ll> edges;

    sort(towns.begin(), towns.end(), [](Town e1, Town e2) { return e1.x < e2.x; });
    rep(i, n - 1) {
        Town t1 = towns[i];
        Town t2 = towns[i + 1];

        ll cost = t2.x - t1.x;
        edges.push_back(edge<ll>(t1.town_id, t2.town_id, cost));
        edges.push_back(edge<ll>(t2.town_id, t1.town_id, cost));
    }

    sort(towns.begin(), towns.end(), [](Town e1, Town e2) { return e1.y < e2.y; });
    rep(i, n - 1) {
        Town t1 = towns[i];
        Town t2 = towns[i + 1];

        ll cost = t2.y - t1.y;
        edges.push_back(edge<ll>(t1.town_id, t2.town_id, cost));
        edges.push_back(edge<ll>(t2.town_id, t1.town_id, cost));
    }
    ll now = kruskal<ll>(edges, n);

    cout << now << endl;
}
