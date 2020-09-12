#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

bool dfs(vector<vector<int>> &g, int now, int goal, int prev, vector<int> &route) {
    route.push_back(now);
    if (now == goal) return true;

    for (int to : g[now]) {
        if (to == prev) continue;
        bool ok = dfs(g, to, goal, now, route);
        if (ok) return true;
    }

    route.pop_back();
    return false;
}

P make_edge(int a, int b) {
    if (a < b) return P(a, b);
    return P(b, a);
}

ll calc(int m, vector<vector<P>> &use_edges_p, int i) {
    vector<P> use_edges;
//    set<P> use_edges;
    rep(j, m) {
        bool use = (i >> j) & 1;
        if (!use) continue;

        for (P p : use_edges_p[j]) {
            use_edges.push_back(p);
        }
    }
    sort(use_edges.begin(), use_edges.end());
    use_edges.erase(unique(use_edges.begin(), use_edges.end()), use_edges.end());
    return use_edges.size();
}

int main() {
    int n;
    cin >> n;

    vector<P> v(n - 1);
    for (P &p : v) cin >> p.first >> p.second, p.first--, p.second--;

    for (P p : v) if (p.first > p.second) swap(p.first, p.second);

    vector<vector<int>> g(n);
    for (P p : v) g[p.first].push_back(p.second);
    for (P p : v) g[p.second].push_back(p.first);

    int m;
    cin >> m;
    vector<P> u(m);
    for (P &p : u) cin >> p.first >> p.second, p.first--, p.second--;


    vector<vector<int>> use_edges(m);
    rep(i, m) dfs(g, u[i].first, u[i].second, -1, use_edges[i]);

    vector<vector<P>> use_edges_p(m);
    rep(i, m) {
        rep(j, use_edges[i].size() - 1) {
            use_edges_p[i].push_back(make_edge(use_edges[i][j], use_edges[i][j + 1]));
        }
    }

    ll ans = 0;
    rep(i, 1 << m) {
        int method = __builtin_popcount(i) % 2;
        if (method == 0) {
            // またはを引く
            ll k = calc(m, use_edges_p, i);
            ll now = ((1ll << k) - 1) * (1ll << (n - 1 - k));
            ans -= now;
        } else {
            // またはを足す
            ll k = calc(m, use_edges_p, i);
            ll now = ((1ll << k) - 1) * (1ll << (n - 1 - k));
            ans += now;
        }
    }
    cout << ans << endl;

}