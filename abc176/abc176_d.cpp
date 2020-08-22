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

// https://qiita.com/ta-ka/items/a023a11efe17ab097433
struct Edge {
    ll to, cost;
};


class Dijkstra {
    ll vector_count;

    vector<ll> distances;
    vector<vector<Edge>> edges;

public:
    Dijkstra(ll n) {
        vector_count = n;
        distances.resize(n, INF);
        edges.resize(n);
    }

    void insertTowWay(ll from, ll to, ll cost) {
        edges[from].push_back({to, cost});
        edges[to].push_back({from, cost});
    }

    void insert(ll from, ll to, ll cost) {
        edges[from].push_back({to, cost});
    }

    void dijkstra(ll k) {
        distances[k] = 0;  // 始点sへの最短距離は0

        priority_queue<P, vector<P>, greater<P>> que;  // 距離が小さい順に取り出せるようgreater<P>を指定
        que.push(P(0, k));
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;  // 更新した頂点の中で距離が最小の頂点v
            if (distances[v] < p.first) {
                continue;
            }
            for (auto e : edges[v]) {  // 頂点vから出る辺eを走査
                if (distances[e.to] > distances[v] + e.cost) {
                    distances[e.to] = distances[v] + e.cost;
                    que.push(P(distances[e.to], e.to));
                }
            }
        }
    }

    ll distance(ll to) {
        return distances[to];
    }

};

int main() {
    int h, w;
    int ch, cw;
    int dh, dw;
    cin >> h >> w >> ch >> cw >> dh >> dw;

    ch--;
    cw--;
    dh--;
    dw--;

    vector<vector<char>> board(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> board[y][x];


    auto to_id = [&](int y, int x) {
        return y * w + x;
    };

    struct Direction {
        int y, x;
    };


    auto reachable = [&](int y, int x) {
        if (x <= -1 || x >= w || y <= -1 || y >= h) return false;
        if (board[y][x] == '#') {
            return false;
        }
        return true;
    };


    Dijkstra dijkstra(h * w);
    {
        vector<Direction> directions = {
                {0,  1},
                {1,  0},
                {0,  -1},
                {-1, 0},
        };
        rep(y, h) {
            rep(x, w) {
                if (board[y][x] == '#') continue;
                int from_id = to_id(y, x);

                for (Direction d1 : directions) {
                    int ya = y + d1.y;
                    int xa = x + d1.x;
                    if (!reachable(ya, xa)) continue;

                    int a_id = to_id(ya, xa);
                    dijkstra.insert(from_id, a_id, 0);
                }

            }
        }


    }

    {
        vector<Direction> directions = {
                {0,  1},
                {1,  1},
                {1,  0},
                {1,  -1},
                {0,  -1},
                {-1, -1},
                {-1, 0},
                {-1, 1},
                {0,  0},
        };

        rep(y, h) {
            rep(x, w) {
                if (board[y][x] == '#') continue;
                int from_id = to_id(y, x);

                for (Direction d1 : directions) {
                    int ya = y + d1.y;
                    int xa = x + d1.x;
                    if (reachable(ya, xa)) {
                        int a_id = to_id(ya, xa);
                        dijkstra.insert(from_id, a_id, 1);
                    }

                    for (Direction d2: directions) {
                        int yb = ya + d2.y;
                        int xb = xa + d2.x;
                        if (!reachable(yb, xb)) continue;

                        int b_id = to_id(yb, xb);
                        dijkstra.insert(from_id, b_id, 1);

                    }
                }

            }
        }
    }
    int start = to_id(ch, cw);
    int end = to_id(dh, dw);

    dijkstra.dijkstra(start);
    ll ans = dijkstra.distance(end);

    //
//    cout << dijkstra.distance(to_id(2, 1)) << endl;

    if (ans >= INF) {
        cout << -1 << endl;
        ret();
    }

    cout << ans << endl;


}
