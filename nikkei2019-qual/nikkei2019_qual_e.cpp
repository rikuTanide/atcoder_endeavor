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


int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    vector<Edge> edges(m);

    for (Edge &p: edges) cin >> p;

    int ans = INT_MAX;
    rep(i, 1 << m) {
        bool ok = [&] {
            vector<Edge> use_edges;
            rep(j, m) if ((i >> j) & 1) use_edges.push_back(edges[j]);
            
            UnionFind uf(n);
            for (Edge e : use_edges) uf.connect(e.to, e.from);

            map<int, ll> w;

            ll now = 0;
            rep(x, n) w[uf.root(x)] += v[x];

            for (Edge e :use_edges) if (w[uf.root(e.from)] < e.weight) return false;
            return true;
        }();

        if (ok) cmin(ans, m - __builtin_popcount(i));

    }
    cout << ans << endl;

}
