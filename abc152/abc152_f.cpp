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
    int to, id;
};

bool dfs(int now, int to, int prev, vector<int> &routes, vector<vector<Edge>> &edges) {
    if (now == to) {
        return true;
    }
    for (Edge &next : edges[now]) {
        if (next.to == prev) continue;
        bool b = dfs(next.to, to, now, routes, edges);
        if (!b) continue;
        routes.push_back(next.id);
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<vector<Edge>> edges(n);

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        edges[a].push_back(Edge{b, i});
        edges[b].push_back(Edge{a, i});
    }

    int m;
    cin >> m;
    vector<ll> rs(m);

    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        vector<int> routes;
        dfs(u, v, -1, routes, edges);

        ll route_bit = 0;
        for (int j : routes) route_bit |= (1ll << j);
        rs[i] = route_bit;
    }

    ll ans = 0;
    rep(i, 1 << m) {
        ll k = 0;
        rep (j, m) if ((i >> j) & 1) {
                k |= rs[j];
            }
        int white = __builtin_popcountll(k);
        ll now = 1ll << (n - 1 - white);
        if (__builtin_popcount(i) % 2 == 0) {
            ans += now;
        } else {
            ans -= now;
        }
    }
    cout << ans << endl;
}
