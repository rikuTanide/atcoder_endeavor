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


int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<ll>> board(n, vector<ll>(n));
    rep(y, n) rep(x, n)cin >> board[y][x];

    auto to_id = [&](int y, int x) {
        return y * n + x;
    };

//    map<int, char> mm;
    vector<int> vs, hs;


    rep(y, n) {
        rep(x, n) {
//            mm[to_id(y, x)] = 'b';
        }
    }
    rep(y, n) {
//        mm[n * n + y] = 'v';
        vs.push_back(n * n + y);
    }
    rep(x, n) {
//        mm[n * n + n + x] = 'h';
        hs.push_back(n * n + n + x);
    }
    int s = n * n + n + n, g = n * n + n + n + 1;

    atcoder::mcf_graph<ll, ll> graph(g + 1);

    for (ll v: vs) graph.add_edge(s, v, k, 0);
    for (ll h: hs) graph.add_edge(h, g, k, 0);

    rep(y, n) {
        rep(x, n) {
            graph.add_edge(vs[y], to_id(y, x), 1, 0);
        }
    }

    ll MAX = 1e10;

    rep(y, n) {
        rep(x, n) {
            graph.add_edge(to_id(y, x), hs[x], 1, MAX - board[y][x]);
        }
    }

    graph.add_edge(s, g, n * k, MAX);

    auto flow = graph.flow(s, g, n * k);

//    ll use = 0;
//    for (auto e : graph.edges()) {
//        if (e.flow == 0) continue;
//        if (find(hs.begin(), hs.end(), e.to) == hs.end()) continue;
//        use += e.flow;
//    }

    cout << MAX * n * k - flow.second << endl;

    vector<vector<char>> ans(n, vector<char>(n, '.'));
    for (auto e : graph.edges()) {
        if (e.flow == 0) continue;
        if (find(hs.begin(), hs.end(), e.to) == hs.end()) continue;

        int y = e.from / n;
        int x = e.from % n;

        ans[y][x] = 'X';
    }


    rep(y, n) {
        rep(x, n) {
            cout << ans[y][x];
        }
        cout << endl;
    }

}