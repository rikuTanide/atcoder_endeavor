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

struct Edge {
    int from, to;
    ll weight;
};


std::istream &operator>>(std::istream &in, Edge &o) {
    cin >> o.from >> o.to >> o.weight;
    o.from--;
    o.to--;
    return in;
}


class UnionFind {
public:
    // 親の番号を格納する。親だった場合-size
    vector<int> parents;
    vector<ll> weights;

    UnionFind(int n) {
        parents = vector<int>(n, -1);
    }


    // aがどのグループに属しているか
    int root(int a) {
        if (parents[a] < 0) {
            return a;
        }
        int p = root(parents[a]);
        int aw = weights[a];
        weights[a] = 0;
        weights[p] += aw;

        return parents[a] = p;
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
        weights[ra] += weights[rb];
        weights[rb] = 0;

        parents[ra] += parents[rb];
        parents[rb] = ra;
        return true;
    }

    bool is_union(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        return ra == rb;
    }

    ll weight(int a) {
        return weights[root(a)];
    }
};

void dfs(vector<bool> &use, int i, ll w_max, vector<Edge> &edges, vector<vector<int>> &directions) {
    if (use[i]) return;
    use[i] = true;

    for (int j: directions[edges[i].from]) {
        Edge e = edges[j];
        if (e.weight > w_max) continue;
        dfs(use, j, w_max, edges, directions);
    }
    for (int j: directions[edges[i].to]) {
        Edge e = edges[j];
        if (e.weight > w_max) continue;
        dfs(use, j, w_max, edges, directions);
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    vector<Edge> edges(m);
    for (Edge &p: edges) cin >> p;

    sort(edges.begin(), edges.end(), [](Edge e1, Edge e2) {
        return e1.weight < e2.weight;
    });

    UnionFind uf(n);
    vector<bool> candidate(m, false);

    uf.weights = v;
    rep(i, m) {
        Edge e = edges[i];
        uf.connect(e.from, e.to);
        ll w = uf.weight(e.from);
        candidate[i] = w >= e.weight;
    }

    vector<bool> use(m, false);

    vector<vector<int>> directions(n);
    rep(i, m) directions[edges[i].from].push_back(i);
    rep(i, m) directions[edges[i].to].push_back(i);

    for (int i = m - 1; i >= 0; i--) {
        if (use[i]) continue;
        if (candidate[i]) dfs(use, i, edges[i].weight, edges, directions);
    }

    int ans = count(use.begin(), use.end(), false);
    cout << ans << endl;

}

