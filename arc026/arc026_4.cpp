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


typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


class UnionFind {
public:
    // 親の番号を格納する。親だった場合-size
    vector<int> parents;

    UnionFind(int n) {
        parents = vector<int>(n, -1);
    }

    // aがどのグループに属しているか
    int root(int a) {
        if (parents[a] < 0) {
            return a;
        }
        return parents[a] = root(parents[a]);
    }

    int size(int a) {
        return -parents[root(a)];
    }

    // aとbをくっつける
    bool connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra == rb) {
            return false;
        }
        // 大きいほうにA
        if (size(ra) < size(rb)) {
            swap(ra, rb);
        }
        parents[ra] += parents[rb];
        parents[rb] = ra;
        return true;
    }

    bool is_union(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        return ra == rb;
    }
};

struct Road {
    int from, to;
    double cost, time;
};

std::istream &operator>>(std::istream &in, Road &o) {
    cin >> o.from >> o.to >> o.cost >> o.time;
    return in;
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

template<typename T>
T kruskal(Edges<T> &edges, int V) {
    sort(begin(edges), end(edges), [](const edge<T> &a, const edge<T> &b) {
        return (a.cost < b.cost);
    });
    UnionFind tree(V);
    T ret = 0;
    for (auto &e : edges) {
        if (tree.connect(e.src, e.to)) ret += e.cost;
    }
    return (ret);
}

bool check(int n, int m, vector<Road> &roads, double wage) {

    Edges<double> edges;

    double profits = 0;

    rep(i, m) {
        Road road = roads[i];
        double profit = road.time * wage - road.cost;

        if (profit >= 0) {
            edge<double> e1(road.from, road.to, 0);
            edge<double> e2(road.to, road.from, 0);

            edges.push_back(e1);
            edges.push_back(e2);

            profits += profit;
        } else {
            edge<double> e1(road.from, road.to, -profit);
            edge<double> e2(road.to, road.from, -profit);

            edges.push_back(e1);
            edges.push_back(e2);
        }

    }

    double costs = kruskal(edges, n);

    return profits >= costs;

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Road> roads(m);
    rep(i, m) cin >> roads[i];

    double floor = 0, ceil = INF;

    while (ceil - floor > 0.00001) {
        double mid = (ceil + floor) / 2;
        bool b = check(n, m, roads, mid);
        if (b) ceil = mid;
        else floor = mid;
    }
    printf("%.20f\n", (ceil + floor) / 2);
}

