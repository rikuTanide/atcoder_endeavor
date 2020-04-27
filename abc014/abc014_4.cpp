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

    vector<vector<int>> edges(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    DoublingLowestCommonAncestor lca(edges);
    lca.build();

    int q;
    cin >> q;

    rep(i, q) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int p = lca.query(a, b);
        int x = lca.dep[a] - lca.dep[p];
        int y = lca.dep[b] - lca.dep[p];

        cout << x + y + 1 << endl;

    }

}
