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

bool find_loop_dfs(
        int now,
        vector<vector<int>> &edges,
        vector<bool> &visited,
        vector<bool> &clear_edges
) {
    if (clear_edges[now]) return false;
    if (visited[now]) return true;

    visited[now] = true;
    for (int next : edges[now]) {
        bool b = find_loop_dfs(next, edges, visited, clear_edges);
        if (b) return true;
    }
    visited[now] = false;
    clear_edges[now] = true;
    return false;
}

int find_loop(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<bool> visited(n, false);
    vector<bool> clear_edges(n, false);


    rep(i, n) if (find_loop_dfs(i, edges, visited, clear_edges)) return true;
    return false;
}

vector<vector<int>> create_edges(vector<vector<int>> &table) {
    int n = table.size();
    vector<vector<int>> m(n, vector<int>(n));

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            m[i][j] = k;
            k++;
        }
    }

    vector<vector<int>> edges(k);

    auto to_id = [&](int i, int j) -> int {
        if (i > j) swap(i, j);
        return m[i][j];
    };

    rep(i, n) {
        rep(j, table[i].size() - 1) {
            int from = to_id(i, table[i][j]);
            int to = to_id(i, table[i][j + 1]);
            edges[from].push_back(to);
        }
    }

    return edges;
}

int dfs(int now, vector<vector<int>> &edges, vector<int> &memo) {
    if (memo[now] != -1) return memo[now];

    int ans = 0;
    for (int next : edges[now]) {
        cmax(ans, dfs(next, edges, memo) + 1);
    }

    memo[now] = ans;
    return ans;
}

int solve(vector<vector<int>> &edges) {
    int ans = 0;
    int n = edges.size();
    vector<int> memo(n, -1);
    rep(i, n) cmax(ans, dfs(i, edges, memo));
    return ans + 1;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> table(n, vector<int>(n - 1));
    rep(i, n)rep(j, n - 1)cin >> table[i][j], table[i][j]--;

    vector<vector<int>> edges = create_edges(table);

    bool l = find_loop(edges);
    if (l) {
        cout << -1 << endl;
        ret();
    }

    int ans = solve(edges);

    cout << ans << endl;


}