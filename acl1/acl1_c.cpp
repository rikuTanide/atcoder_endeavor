#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
#include "atcoder/all"

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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

typedef int Weight;

struct Edge {
    int src, dst;
    Weight weight;

    Edge(int src, int dst, Weight weight) :
            src(src), dst(dst), weight(weight) {}
};

bool operator<(const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
           e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

#define _GLIBCXX_DEBUG

#include <iostream>
#include <vector>

using namespace std;

template<typename flow_t, typename cost_t>
struct PrimalDual {
    const cost_t INF;

    struct edge {
        int to;
        flow_t cap;
        cost_t cost;
        int rev;
        bool isrev;
    };
    vector<vector<edge> > graph;
    vector<cost_t> potential, min_cost;
    vector<int> prevv, preve;

    PrimalDual(int V) : graph(V), INF(numeric_limits<cost_t>::max()) {}

    void add_edge(int from, int to, flow_t cap, cost_t cost) {
//        cout << from << ' ' << to << endl;
        graph[from].emplace_back((edge) {to, cap, cost, (int) graph[to].size(), false});
        graph[to].emplace_back((edge) {from, 0, -cost, (int) graph[from].size() - 1, true});
    }

    cost_t min_cost_flow(int s, int t, flow_t f) {
        int V = (int) graph.size();
        cost_t ret = 0;
        using Pi = pair<cost_t, int>;
        priority_queue<Pi, vector<Pi>, greater<Pi> > que;
        potential.assign(V, 0);
        preve.assign(V, -1);
        prevv.assign(V, -1);

        while (f > 0) {
            min_cost.assign(V, INF);
            que.emplace(0, s);
            min_cost[s] = 0;
            while (!que.empty()) {
                Pi p = que.top();
                que.pop();
                if (min_cost[p.second] < p.first) continue;
                for (int i = 0; i < graph[p.second].size(); i++) {
                    edge &e = graph[p.second][i];
                    cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
                    if (e.cap > 0 && min_cost[e.to] > nextCost) {
                        min_cost[e.to] = nextCost;
                        prevv[e.to] = p.second, preve[e.to] = i;
                        que.emplace(min_cost[e.to], e.to);
                    }
                }
            }
            if (min_cost[t] == INF) return -1;
            for (int v = 0; v < V; v++) potential[v] += min_cost[v];
            flow_t addflow = f;
            for (int v = t; v != s; v = prevv[v]) {
                addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
            }
            f -= addflow;
            ret += addflow * potential[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = graph[prevv[v]][preve[v]];
                e.cap -= addflow;
                graph[v][e.rev].cap += addflow;
            }
        }
        return ret;
    }

    void output() {
        for (int i = 0; i < graph.size(); i++) {
            for (auto &e : graph[i]) {
                if (e.isrev) continue;
                auto &rev_e = graph[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << rev_e.cap + e.cap << ")" << endl;
            }
        }
    }
};

P get_rd(int h, int w, vector<vector<char>> &board) {
    for (int y = h - 1; y >= 0; y--) {
        for (int x = w - 1; x >= 0; x--) {
            if (board[y][x] == 'o') return {y, x};
        }
    }
    return {-1, -1};
}

struct X {
    int from;
    int to;
    int cost;
};

vector<X> calc_dp(int h, int w, vector<vector<char>> &board, P rd) {
    vector<vector<int>> distances(h, vector<int>(w, INT_MAX / 10));

    distances[rd.first][rd.second] = 0;
    struct Point {
        ll y, x, cost;
    };

    queue<Point> q;
    q.push({rd.first, rd.second, 0});

    auto to_id = [&](int y, int x) {
        return y * w + x;
    };

    struct Direction {
        int y, x;
    };

    vector<Direction> directions = {
            {0, 1},
            {1, 0},
    };


    auto reachable = [&](int y, int x, int distance) {
        if (x == -1 || x == w || y == -1 || y == h) return false;
        if (board[y][x] == '#') {
            return false;
        }
        if (distances[y][x] <= distance) {
            return false;
        }
        return true;
    };


    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        for (Direction d : directions) {
            int nx = p.x + d.x;
            int ny = p.y + d.y;
            int nd = p.cost + 1;
            if (reachable(ny, nx, nd)) {
                distances[ny][nx] = nd;
                q.push({ny, nx, nd});
            }
        }
    }

    vector<X> ans;
    for (int y = h - 1; y >= 0; y--) {
        for (int x = w - 1; x >= 0; x--) {
            if (distances[y][x] >= INT_MAX / 100) continue;
            X xi = {
                    to_id(rd.first, rd.second),
                    to_id(y, x) + (h * w),
                    distances[y][x],
            };
            ans.push_back(xi);
        }
    }
    return ans;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> board(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> board[y][x];

    int start = h * w * 2;
    int goal = start + 1;
//    atcoder::mcf_graph<ll, ll> pd(h * w * 2 + 2);
    PrimalDual<ll, ll> pd(h * w * 2 + 2);

    rep(i, h * w) {
        pd.add_edge(start, i, 1, 0);
    }
    rep(i, h * w) {
        pd.add_edge(h * w + i, goal, 1, 0);
    }

    int count = 0;
    rep(y, h) {
        rep(x, w) {
            if (board[y][x] != 'o') continue;
            count++;
            vector<X> distances = calc_dp(h, w, board, {y, x});

            for (X x : distances) pd.add_edge(x.from, x.to, 1, -x.cost);

//
//        rep(y, h) {
//            rep(x, w) cout << board[y][x];
//            cout << endl;
//        }
//        cout << endl;

        }
    }
//    P ans = pd.flow(start, goal, 1);
    ll ans = -pd.min_cost_flow(start, goal, count);
    cout << ans << endl;
}
