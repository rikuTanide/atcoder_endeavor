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

int min_cycle(int start, int n, vector<vector<int>> &edges) {
    vector<int> costs(n, INT_MAX);
    queue<P> q;
    q.push(P(start, 0));
    while (!q.empty()) {
        P now = q.front();
        q.pop();

        for (int next : edges[now.first]) {
            if (costs[next] != INT_MAX)continue;

            costs[next] = now.second + 1;
            q.push(P(next, now.second + 1));

        }

    }
    return costs[start];
}

bool dfs(int goal, vector<vector<int>> &edges, vector<int> &route, int now, int depth) {
    if (now == goal && route.size() == depth) {
        return true;
    }
    if (depth == route.size()) {
        return false;
    }
    route.push_back(now);
    for (int next : edges[now]) {
        bool b = dfs(goal, edges, route, next, depth);
        if (b) return true;
    }

    route.pop_back();
    return false;

}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n);
    rep(_, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
    }

    P mic(INT_MAX, 0);
    rep(i, n) cmin(mic, P(min_cycle(i, n, edges), i));
    if (mic.first == INT_MAX) {
        cout << -1 << endl;
        ret();
    }

    vector<int> route;
    bool b = dfs(mic.second, edges, route, mic.second, mic.first);
    assert(b);
    assert(route.size() == mic.first);
    cout << mic.first << endl;
    for (int i : route) cout << i + 1 << endl;

}
