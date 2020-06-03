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

template<typename G>
struct StronglyConnectedComponents {
    const G &g;
    UnWeightedGraph gg, rg;
    vector<int> comp, order, used;

    StronglyConnectedComponents(G &g) : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
        for (int i = 0; i < g.size(); i++) {
            for (auto e : g[i]) {
                gg[i].emplace_back((int) e);
                rg[(int) e].emplace_back(i);
            }
        }
    }

    int operator[](int k) {
        return comp[k];
    }

    void dfs(int idx) {
        if (used[idx]) return;
        used[idx] = true;
        for (int to : gg[idx]) dfs(to);
        order.push_back(idx);
    }

    void rdfs(int idx, int cnt) {
        if (comp[idx] != -1) return;
        comp[idx] = cnt;
        for (int to : rg[idx]) rdfs(to, cnt);
    }

    void build(UnWeightedGraph &t) {
        for (int i = 0; i < gg.size(); i++) dfs(i);
        reverse(begin(order), end(order));
        int ptr = 0;
        for (int i : order) if (comp[i] == -1) rdfs(i, ptr), ptr++;

        t.resize(ptr);
        for (int i = 0; i < g.size(); i++) {
            for (auto &to : g[i]) {
                int x = comp[i], y = comp[to];
                if (x == y) continue;
                t[x].push_back(y);
            }
        }
    }
};

char solve(int i, vector<vector<int>> &edge, vector<char> &use, set<int> &parents) {
    if (use[i] != '-') return use[i];
    if (parents.find(i) != parents.end()) return use[i] = 'x';

    parents.insert(i);
    for (int j : edge[i]) {
        char now = solve(j, edge, use, parents);
        if (now == 'x') return use[i] = 'x';
    }
    parents.erase(i);
    return use[i] = 'o';
}

int main() {
    int n;
    cin >> n;

    int a;
    cin >> a;
    vector<P> ac(a);
    for (P &p : ac) cin >> p.first >> p.second;
    for (P &p : ac) p.first--, p.second--;

    int b;
    cin >> b;
    vector<P> bc(b);
    for (P &p : bc) cin >> p.first >> p.second;
    for (P &p : bc) p.first--, p.second--;

    int ans = 0;
    rep(i, 1 << b) {

        vector<vector<int>> edges(n);
        vector<char> use(n, '-');
        set<int> parents;

        for (P p : ac) edges[p.second].push_back(p.first);
        rep(j, b) {
            P p = bc[j];
            if ((i >> j) & 1) {
                edges[p.first].push_back(p.second);
            } else {
                use[p.first] = 'x';
            }
        }


        // 塗れる・塗れない・まだわからない
        // 自分のおやがすべて塗れるなら塗れる
        // 自分のおやがxもしくは、自分か親が強連結成分の中身なら塗れない

        rep(j, n) use[j] = solve(j, edges, use, parents);
        int now = count(use.begin(), use.end(), 'o');
        cmax(ans, now);
    }
    cout << ans << endl;
}
