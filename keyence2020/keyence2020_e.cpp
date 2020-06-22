#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
    ll a;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;



vector<vector<int>> create_edges(int n, vector<P> &edges) {
    vector<vector<int>> g(n);
    for (P p : edges) {
        int a = p.first;
        int b = p.second;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    return g;
}

int get_pi(int i, vector<vector<int>> &g, vector<ll> &ds) {

    ll mi = INT_MAX;
    for (int j : g[i]) {
        cmin(mi, ds[j]);
    }
    for (int j : g[i]) {
        if (ds[j] == mi) return j;
    }
    __throw_runtime_error("konaide");
}

P cp(int i, int j) {
    return {min(i, j), max(i, j)};
}


vector<vector<int>> create_g2(int n, vector<int> &ps) {
    set<P> es;

    rep(i, n) {
        es.insert(cp(i, ps[i]));
    }

    vector<P> eds;

    for (P p : es) eds.push_back(p);

    return create_edges(n, eds);
}


void dfs(int i, char c, vector<char> &colors, vector<vector<int>> &edges) {
    if (colors[i] != ' ') return;

    colors[i] = c;

    for (int j : edges[i]) {
        dfs(j, c == 'W' ? 'B' : 'W', colors, edges);
    }

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> ds(n);
    rep(i, n) cin >> ds[i];

    vector<P> g_edges(m);
    for (P &p: g_edges) cin >> p.first >> p.second, p.first--, p.second--;

    vector<vector<int>> g = create_edges(n, g_edges);


    rep(i, n) {

        bool ok = [&] {
            for (int j : g[i]) {
                if (ds[i] >= ds[j]) return true;
            }
            return false;
        }();

        if (!ok) {
            cout << -1 << endl;
            ret();
        }

    }

    vector<int> ps(n, -1);
    rep(i, n) ps[i] = get_pi(i, g, ds);

    vector<vector<int>> g2 = create_g2(n, ps);

    vector<char> colors(n, ' ');
    rep(i, n) dfs(i, 'W', colors, g2);

    for (char c : colors) cout << c;
    cout << endl;

    map<P, ll> ans;

    rep(i, n) ans[cp(i, ps[i])] = ds[i];

    for (P p : g_edges) {
        P index = cp(p.first, p.second);
        if (ans.find(index) == ans.end()) ans[index] = INF;
    }

    for (P p : g_edges) {
        P index = cp(p.first, p.second);
        cout << ans[index] << endl;
    }


}