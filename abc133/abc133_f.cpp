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


struct Edge {
    int from, to, color;
    ll cost;
};


std::istream &operator>>(std::istream &in, Edge &o) {
    cin >> o.from >> o.to >> o.color >> o.cost;
    o.from--;
    o.to--;
    o.color--;
    return in;
}


ll rec(vector<vector<Edge>> &g, int start, int now, int goal, int prev) {
    if (goal == now) return 0;

    for (Edge e : g[now]) {
        if (e.to == prev) continue;
        ll c = rec(g, start, e.to, goal, now);
        if (c == -1) continue;
        return c + e.cost;
    }
    return -1;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<Edge> edges(n);
    rep(i, n - 1) cin >> edges[i];

    rep(_, q) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;

        x--;
        u--;
        v--;

        vector<vector<Edge>> g(n);
        for (Edge e : edges) {
            ll cost = (e.color == x) ? y : e.cost;
            g[e.from].push_back({e.from, e.to, e.color, cost});
            g[e.to].push_back({e.to, e.from, e.color, cost});
        }


        ll now = rec(g, u, u, v, -1);
        cout << now << endl;

    }

}
