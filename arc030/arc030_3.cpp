#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

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

string min_k(string s, int k) {
    vector<string> dp(k + 1, "");
    int n = s.size();
    rep(i, n) {
        vector<string> next(k + 1, "");

        rep(j, k) {
            if (dp[j].size() != j) continue;
            string nx = dp[j] + s[i];
            string mi = dp[j + 1].empty() ? nx : min(dp[j + 1], nx);
            next[j + 1] = mi;
        }

        dp = next;
    }
    return dp[k];

}

string dfs(int now, vector<vector<int>> &edges, map<int, string> &comp_str, string current, int k) {
    current += comp_str[now];
    string ans = "";
    if (edges[now].empty()) {
        return min_k(current, k);
    }
    for (int to : edges[now]) {
        string now = dfs(to, edges, comp_str, current, k);
        if (now.empty())continue;
        if (ans.empty()) ans = now;
        cmin(ans, now);
    }
    return ans;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<char> vc(n);
    rep(i, n) cin >> vc[i];

    n++;
    vc.push_back('~');


    UnWeightedGraph g(n), buff;

    rep(_, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        g[a].push_back(b);
    }

    rep(i, n - 1) {
        g[n - 1].push_back(i);
    }

    StronglyConnectedComponents<UnWeightedGraph> scc(g);
    scc.build(buff);

    map<int, string> comp_str;

    rep(i, n) {
        int r = scc[i];
        comp_str[r] += vc[i];
    }

    for (auto &e: comp_str) {
        sort(e.second.begin(), e.second.end());
    }

    set<P> vs;

    rep(from, n) {
        for (int to : g[from]) {
            int fr = scc[from];
            int tr = scc[to];
            if (fr == tr) continue;
            vs.emplace(fr, tr);
        }
    }

    vector<vector<int>> edges(n);
    for (P p : vs) {
        edges[p.first].push_back(p.second);
    }

    string ans = dfs(scc[n - 1], edges, comp_str, "", k);

    if (ans.empty() || ans.front() == '~') {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }


}
