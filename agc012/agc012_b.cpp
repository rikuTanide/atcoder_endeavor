#include <bits/stdc++.h>

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
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

void dfs(int now, int prev, int hop, int color, vector<int> &colors, vector<vector<int>> &edges) {
    if (colors[now] == -1) colors[now] = color;

    if (hop == 0) return;

    for (int next : edges[now]) {
        if (next == prev) continue;
        dfs(next, now, hop - 1, color, colors, edges);
    }

}

struct Splat {
    int u, size, color;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> checked(n, vector<bool>(10, false));

    vector<int> colors(n, -1);
    vector<vector<int>> edges(n);

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int q;
    cin >> q;

    vector<Splat> splats(q);
    for (Splat &s:splats) cin >> s.u >> s.size >> s.color, s.u--;
    reverse(splats.begin(), splats.end());
    for (Splat &s: splats) dfs(s.u, -1, s.size, s.color, colors, edges);

    for (int &c : colors) if (c == -1) c = 0;
    for (int c : colors) cout << c << endl;

}
