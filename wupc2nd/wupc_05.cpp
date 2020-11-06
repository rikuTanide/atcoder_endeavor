#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

bool equal(double a, double b) {
//    return fabs(a - b) < DBL_EPSILON;
    return fabs(a - b) < EPS;
}

template<class T>
std::istream &operator>>(std::istream &in, set<T> &o) {
    T a;
    in >> a;
    o.insert(a);
    return in;
}

template<class T>
std::istream &operator>>(std::istream &in, queue<T> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

class UnionFind {
public:
    // 親の番号を格納する。親だった場合-size
    vector<int> parents;

    UnionFind(int n) {
        parents = vector<int>(n, -1);
    }

    // aがどのグループに属しているか
    int root(int a) {
        if (parents[a] < 0) {
            return a;
        }
        return parents[a] = root(parents[a]);
    }

    int size(int a) {
        return -parents[root(a)];
    }

    // aとbをくっつける
    bool connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra == rb) {
            return false;
        }
        // 大きいほうにA
        if (size(ra) < size(rb)) {
            swap(ra, rb);
        }
        parents[ra] += parents[rb];
        parents[rb] = ra;
        return true;
    }

    bool is_union(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        return ra == rb;
    }
};

struct Road {
    int from, to;
    ll cost;

    friend bool operator==(const Road &r1, const Road &r2) {
        return r1.tov() == r2.tov();
    }

    vector<ll> tov() const {
        return {from, to, cost};
    }

};

ll solve_non_loop(int n, int m, int k, vector<Road> &roads) {

    UnionFind uf(n);
    vector<ll> costs(m);
    rep(i, m) costs[i] = roads[i].cost;
    for (Road &r : roads) uf.connect(r.from, r.to);
    int f = 0;
    rep(i, n) if (i == uf.root(i)) f++;

    int ct = (k - f);
    assert(ct <= m);
    sort(costs.begin(), costs.end());
    ll ans = 0;
    rep(i, ct) {
        ans += costs[i];
    }
    return ans;
}

bool
rec(int n, int now, int prev,
    vector<vector<int>> &edges, vector<int> &route, vector<bool> &used, vector<char> &memo) {
    if (memo[now] != '-') return memo[now] == 'o';
    route.push_back(now);
    if (used[now]) return true;
    used[now] = true;

    for (int next : edges[now]) {
        if (next == prev) continue;
        bool found = rec(n, next, now, edges, route, used, memo);
        if (found) {
            memo[now] = 'o';
            return true;
        }
    }
    memo[now] = 'x';
    used[now] = false;
    route.pop_back();
    return false;
}

vector<int> find_loop(int n, int m, vector<Road> &roads) {
    vector<vector<int>> edges(n);
    for (Road r : roads) edges[r.from].push_back(r.to);
    for (Road r : roads) edges[r.to].push_back(r.from);

    vector<char> memo(n, '-');
    rep(i, n) {
        vector<int> route;
        vector<bool> used(n, false);
        bool found = rec(n, i, -1, edges, route, used, memo);
        if (found) {

            int start = route.back();
            reverse(route.begin(), route.end());
            while (route.back() != start) {
                route.pop_back();
            }

            return route;
        }
    }
    return vector<int>(0);
}

Road find_min_loop_edge(vector<Road> &roads, vector<int> &loop) {
    map<P, ll> costs;
    for (Road &r: roads) costs[P(r.from, r.to)] = r.cost;

    ll ma = INF;
    rep(i, loop.size() - 1) {
        int from = loop[i];
        int to = loop[i + 1];
        if (from > to)swap(from, to);
        cmin(ma, costs[P(from, to)]);
    }

    rep(i, loop.size() - 1) {
        int from = loop[i];
        int to = loop[i + 1];
        if (from > to)swap(from, to);
        ll c = costs[P(from, to)];
        if (c == ma) return Road{from, to, c};
    }

    assert(false);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Road> roads(m);
    rep(i, m) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        roads[i].from = min(a, b);
        roads[i].to = max(a, b);
        roads[i].cost = c;
    }

    auto l = find_loop(n, m, roads);

    if (l.empty()) {
        ll ans = solve_non_loop(n, m, k, roads);
        cout << ans << endl;
        ret();
    }

//    for (int i  : l) cout << i + 1 << endl;

    Road min_loop_edge = find_min_loop_edge(roads, l);
    roads.erase(find(roads.begin(), roads.end(), min_loop_edge));
//
    ll ans = min_loop_edge.cost + solve_non_loop(n, m - 1, k, roads);
    cout << ans << endl;
}
