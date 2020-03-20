#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

struct BipartiteMatching {
    vector<vector<int> > graph;
    vector<int> match, alive, used;
    int timestamp;

    BipartiteMatching(int n) : graph(n), alive(n, 1), used(n, 0), match(n, -1), timestamp(0) {}

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool dfs(int idx) {
        used[idx] = timestamp;
        for (auto &to : graph[idx]) {
            int to_match = match[to];
            if (alive[to] == 0) continue;
            if (to_match == -1 || (used[to_match] != timestamp && dfs(to_match))) {
                match[idx] = to;
                match[to] = idx;
                return true;
            }
        }
        return false;
    }

    int bipartite_matching() {
        int ret = 0;
        for (int i = 0; i < graph.size(); i++) {
            if (alive[i] == 0) continue;
            if (match[i] == -1) {
                ++timestamp;
                ret += dfs(i);
            }
        }
        return ret;
    }

    void output() {
        for (int i = 0; i < graph.size(); i++) {
            if (i < match[i]) {
                cout << i << "-" << match[i] << endl;
            }
        }
    }
};

int main() {
    struct Ball {
        int i, x, y;
    };

    int n;
    cin >> n;
    vector<Ball> blues(n), reds(n);
    rep(i, n) cin >> reds[i].x >> reds[i].y;
    rep(i, n) reds[i].i = i;
    rep(i, n) cin >> blues[i].x >> blues[i].y;
    rep(i, n) blues[i].i = i;


    BipartiteMatching bm(2 * n);

    for (Ball blue: blues) {
        for (Ball red : reds) {
            if (red.x < blue.x && red.y < blue.y) {
                bm.add_edge(red.i, n + blue.i);
            }
        }
    }
    cout << bm.bipartite_matching() << endl;


}


