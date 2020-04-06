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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

vector<int> dfs_start_goal(int now, int goal, int prev, vector<vector<int>> &edges) {
    if (now == goal) return vector<int>{now};
    for (int next : edges[now]) {
        if (next == prev) continue;
        vector<int> r = dfs_start_goal(next, goal, now, edges);
        if (r.empty()) continue;
        r.push_back(now);
        return r;
    }
    return vector<int>{};
}

int dfs_depth_max(int now, int prev, vector<vector<int>> &edges, int depth) {
    int res = depth;
    for (int next : edges[now]) {
        if (next == prev) continue;
        int nd = dfs_depth_max(next, now, edges, depth + 1);
        cmax(res, nd);
    }
    return res;
}

int main() {
    int n, u, v;
    cin >> n >> u >> v;
    u--;
    v--;
    vector<vector<int>> edges(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> r = dfs_start_goal(u, v, -1, edges);
    reverse(r.begin(), r.end());
    int center = r[r.size() / 2 - 1];
    int center_next = r[r.size() / 2];
    int max_depth = dfs_depth_max(center, center_next, edges, 0);
    int as = (r.size() + 1) / 2;
    cout << as + max_depth - 1 << endl;
}