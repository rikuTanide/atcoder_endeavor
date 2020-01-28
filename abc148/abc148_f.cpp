#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

bool dfs(int from, int to, int prev, vector<vector<int>> &tos, vector<int> &route) {

    if (from == to) {
        route.push_back(from);
        return true;
    }
    for (int i : tos[from]) {
        if (i == prev) continue;
        bool b = dfs(i, to, from, tos, route);
        if (b) {
            route.push_back(from);
            return true;
        }
    }
    return false;
}

int dfs2(int from, int prev, vector<vector<int>> &tos, int depth) {

    int ma = depth;
    for (int i : tos[from]) {
        if (i == prev) continue;
        int d = dfs2(i, from, tos, depth + 1);
        cmax(ma, d);
    }
    return ma;
}

int main() {

    int n, u, v;
    cin >> n >> u >> v;
    u--;
    v--;
    vector<vector<int>> tos(n);

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tos[a].push_back(b);
        tos[b].push_back(a);
    }
    vector<int> route;
    dfs(v, u, -1, tos, route);

    int border = route.size() / 2 - 1;
    int root = route[border];
    int prev = route[border + 1];
    int depth = dfs2(root, prev, tos, 0);
    int oe = route.size() % 2 == 0 ? 0 : 1;
    cout << depth + border + oe << endl;

}