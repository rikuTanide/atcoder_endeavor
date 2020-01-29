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

struct Edge {
    int id, from, to;
};

void bfs(vector<vector<int>> &edges_each_from, map<int, map<int, int>> &colors) {
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int from = q.front();
        q.pop();
        int color = 0;
        int ng = -1;

        for (int to : edges_each_from[from]) {
            if (colors.find(from) != colors.end() && colors[from].find(to) != colors[from].end()) {
                ng = colors[from][to];
            }
        }

        for (int to : edges_each_from[from]) {
            if (colors.find(from) != colors.end() && colors[from].find(to) != colors[from].end()) {
                continue;
            } else {
                if (color == ng)color++;
                colors[from][to] = color;
                colors[to][from] = color;
                color++;
                q.push(to);
            }
        }
    }

}

int main() {
    int n;
    cin >> n;

    vector<Edge> edges(n - 1);

    map<int, map<int, int>> edge_ids;
    map<int, map<int, int>> colors;

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge_ids[a][b] = i;
        edge_ids[b][a] = i;

        edges[i].id = i;
        edges[i].from = a;
        edges[i].to = b;

    }

    vector<vector<int>> edges_each_from(n);

    for (Edge &edge : edges) {
        edges_each_from[edge.from].push_back(edge.to);
        edges_each_from[edge.to].push_back(edge.from);
    }

    bfs(edges_each_from, colors);

    vector<int> ans(n - 1);
    for (int i = 0; i < n - 1; i++) {
        Edge edge = edges[i];
        ans[i] = colors[edge.from][edge.to] + 1;
    }

    int m = *max_element(ans.begin(), ans.end());
    cout << m << endl;
    for (int i : ans) {
        cout << i << endl;
    }

}