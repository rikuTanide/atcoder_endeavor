#include <bits/stdc++.h>
#include "atcoder/all"
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

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

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

#define REP(i, n) for(int i=0;i<(int)n;++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

bool augment(const Graph &g, int u,
             vector<int> &matchTo, vector<bool> &visited) {
    if (u < 0) return true;
    FOR(e, g[u]) if (!visited[e->dst]) {
            visited[e->dst] = true;
            if (augment(g, matchTo[e->dst], matchTo, visited)) {
                matchTo[e->src] = e->dst;
                matchTo[e->dst] = e->src;
                return true;
            }
        }
    return false;
}

int bipartiteMatching(const Graph &g, int L, Edges &matching) {
    const int n = g.size();
    vector<int> matchTo(n, -1);
    int match = 0;
    REP(u, L) {
        vector<bool> visited(n);
        if (augment(g, u, matchTo, visited)) ++match;
    }
    REP(u, L) if (matchTo[u] >= 0) // make explicit matching
            matching.push_back(Edge(u, matchTo[u], 1));
    return match;
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> board(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> board[y][x];

    map<P, int> m_1;
    map<int, P> m_2;
    int half;
    {
        vector<P> a, b;
        rep(y, h) {
            rep(x, w) {
                if ((x + y) % 2 == 0) {
                    a.push_back({y, x});
                } else {
                    b.push_back({y, x});
                }
            }
        }
        half = a.size();

        rep(i, a.size()) {
            m_1[a[i]] = i;
            m_2[i] = a[i];
        }

        rep(i, b.size()) {
            m_1[b[i]] = i + a.size();
            m_2[i + a.size()] = b[i];
        }

    }

    auto to_id = [&](int y, int x) {

        return m_1[{y, x}];
    };

    Graph g(h * w);
    rep(y, h) {
        rep(x, w - 1) {
            if (board[y][x] == '.' && board[y][x + 1] == '.') {
                int from = to_id(y, x);
                int to = to_id(y, x + 1);
                g[from].push_back({from, to, 1});
                g[to].push_back({to, from, 1});
            }
        }
    }

    rep(y, h - 1) {
        rep(x, w) {
            if (board[y][x] == '.' && board[y + 1][x] == '.') {
                int from = to_id(y, x);
                int to = to_id(y, x + 1);
                g[from].push_back({from, to, 1});
                g[to].push_back({to, from, 1});
            }
        }
    }

    Edges matching;
    int a = bipartiteMatching(g, half, matching);
    cout << a << endl;

    auto from_id = [&](int id) -> P {
        return m_2[id];
    };

    for (Edge e : matching) {
        P a = from_id(e.src);
        P b = from_id(e.dst);

        if (a.first < b.first) {
            board[a.first][a.second] = 'v';
            board[b.first][b.second] = '^';
        } else if (a.first > b.first) {
            board[a.first][a.second] = '^';
            board[b.first][b.second] = 'V';
        } else if (a.second > b.second) {
            board[a.first][a.second] = '<';
            board[b.first][b.second] = '>';
        } else {
            board[a.first][a.second] = '>';
            board[b.first][b.second] = '<';
        }
    }

    rep(y, h) {
        rep(x, w) {
            cout << board[y][x];
        }
        cout << endl;
    }

}