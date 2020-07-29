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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> grid[y][x];

    int mt = 0;
    rep(y, h) rep(x, w) if (grid[y][x] == '.') mt++;

    BipartiteMatching bm(h * w);

    int t = -1;
    map<P, int> mp;

    auto to_id = [&](int y, int x) -> int {
        P p(y, x);
        if (mp.find(p) == mp.end()) {
            t++;
            mp[p] = t;
            return t;
        }

        return mp[p];

    };

    rep(y, h) rep(x, w) {
            if (y + 1 < h && grid[y][x] == '.' && grid[y + 1][x] == '.') {
                bm.add_edge(to_id(y, x), to_id(y + 1, x));
            }
            if (x + 1 < w && grid[y][x] == '.' && grid[y][x + 1] == '.') {
                bm.add_edge(to_id(y, x), to_id(y, x + 1));
            }
        }

    int a = bm.bipartite_matching();
    cout << mt - a << endl;

}
