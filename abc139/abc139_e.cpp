#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
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

std::istream &operator>>(std::istream &in, set<int> &o) {
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &edges, vector<int> &longest, vector<bool> &visited, vector<bool> &calculated, int to) {
    if (visited[to]) {
        if (!calculated[to]) return -1;
        return longest[to];
    }
    visited[to] = true;
    longest[to] = 0;
    for (int next : edges[to]) {
        int r = dfs(edges, longest, visited, calculated, next);
        if (r == -1) return -1;
        cmax(longest[to], r + 1);
    }
    calculated[to] = true;
    return longest[to];
}

int solve(vector<vector<int>> &edge) {
    int ans = -1;
    vector<int> longest(edge.size(), 0);
    vector<bool> visited(edge.size(), false);
    vector<bool> calculated(edge.size(), false);
    rep(i, edge.size()) {
        int t = dfs(edge, longest, visited, calculated, i);
        if (t == -1) return -1;
        cmax(ans, t);
    }
    return ans + 1;
}

int main() {

//    std::ifstream f("C:\\Users\\riku\\Downloads\\b08");

    int n;
    cin >> n;
    vector<vector<int>> match(n, vector<int>(n - 1));
    rep(i, n) rep(j, n - 1) cin >> match[i][j];
    rep(i, n) rep(j, n - 1) match[i][j]--;

    vector<vector<int>> id_table(n, vector<int>(n, -1));
    {
        vector<P> m;
        rep(i, n) {
            rep (j, n) {
                if (j <= i) continue;
                m.emplace_back(i, j);
            }
        }
        rep(i, m.size()) {
            P p = m[i];
            id_table[p.first][p.second] = i;
            id_table[p.second][p.first] = i;
        }
    }

    auto to_id = [&](int i, int j) {
        return id_table[i][j];
    };

    vector<vector<int>> edge(n * (n - 1) / 2);

    auto add = [&](int a, int b1, int b2) {
        int m1 = to_id(a, b1);
        int m2 = to_id(a, b2);
        edge[m1].push_back(m2);
    };

    rep(i, n) {
        rep(j, n - 2) {
            add(i, match[i][j], match[i][j + 1]);
        }
    }

    cout << solve(edge) << endl;
}
