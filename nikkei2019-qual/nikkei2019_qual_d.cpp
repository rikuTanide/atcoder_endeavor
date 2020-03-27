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

//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

void dfs(int from, int depth, vector<int> &depth_list, vector<vector<int>> &tos) {
    cmax(depth_list[from], depth);
    for (int to : tos[from]) {
        dfs(to, depth + 1, depth_list, tos);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int o = n + m;
    int p = o - 1;
    vector<P> edges(p);
    rep(i, p) cin >> edges[i].first >> edges[i].second;
    rep(i, p) edges[i].first--;
    rep(i, p) edges[i].second--;

    int root = -1;
    vector<bool> has_parent(n, false);
    rep(i, p) has_parent[edges[i].second] = true;
    rep(i, n) if (!has_parent[i]) root = i;


    vector<vector<int>> tos(n);

    for (P q : edges) {
        tos[q.first].push_back(q.second);
    }

    vector<int> depth_list(n, INT_MIN);
    depth_list[root] = 0;
    dfs(root, 0, depth_list, tos);

    vector<int> parents(n, -1);

    for (P q : edges) {
        if (depth_list[q.first] + 1 != depth_list[q.second]) continue;
        assert(parents[q.second] == -1);
        parents[q.second] = q.first;
    }

    for (int parent : parents) cout << parent + 1 << endl;
}
