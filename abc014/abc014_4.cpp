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


// https://ei1333.github.io/luzhiled/snippets/tree/doubling-lowest-common-ancestor.html

struct DoublingLowestCommonAncestor {
    const int LOG;
    vector<int> dep;
    const vector<vector<int>> &g;
    vector<vector<int> > table;

    DoublingLowestCommonAncestor(const vector<vector<int>> &g) : g(g), dep(g.size()),
                                                                 LOG(32 - __builtin_clz(g.size())) {
        table.assign(LOG, vector<int>(g.size(), -1));
    }

    void dfs(int idx, int par, int d) {
        table[0][idx] = par;
        dep[idx] = d;
        for (auto &to : g[idx]) {
            if (to != par) dfs(to, idx, d + 1);
        }
    }

    void build() {
        dfs(0, -1, 0);
        for (int k = 0; k + 1 < LOG; k++) {
            for (int i = 0; i < table[k].size(); i++) {
                if (table[k][i] == -1) table[k + 1][i] = -1;
                else table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    // これは共通の祖先のIDを返す。
    // vector<int> dep;が0からの距離
    int query(int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        for (int i = LOG - 1; i >= 0; i--) {
            if (((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; i--) {
            if (table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }
};

int main() {
    int n;
    cin >> n;

    vector<P> v(n - 1);
    for (P &p:v) cin >> p.first >> p.second, p.first--, p.second--;

    vector<vector<int>> g(n);
    for (P p : v) g[p.first].push_back(p.second);
    for (P p : v) g[p.second].push_back(p.first);

    DoublingLowestCommonAncestor lca(g);
    lca.build();
    int q;
    cin >> q;
    rep(i, q) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;
        int l = lca.query(a, b);

        int ra = lca.dep[a];
        int rb = lca.dep[b];
        int rl = lca.dep[l] * 2;

        int now = ra + rb - rl + 1;
        cout << now << endl;

    }

}
