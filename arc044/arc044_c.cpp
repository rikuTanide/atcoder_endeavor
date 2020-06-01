#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

struct Edge {
    ll to, cost;
};


int to_id(int t, int h, int w, int y, int x) {
    return (t * h * w) + (y * w) + x;
};

struct Direction {
    int y, x;
};


vector<Direction> directions = {
        {0,  1},
        {1,  0},
        {0,  -1},
        {-1, 0},
};

struct Beam {
    int t, d, x;


};

bool operator<(const Beam &b1, const Beam &b2) {
    auto f = vector<int>{b1.t, b1.d, b1.x};
    auto g = vector<int>{b2.t, b2.d, b2.x};
    return f < g;
}

bool operator==(const Beam &b1, const Beam &b2) {
    auto f = vector<int>{b1.t, b1.d, b1.x};
    auto g = vector<int>{b2.t, b2.d, b2.x};
    return f == g;
}


bool reachable(int h, int w, int y, int x) {
    if (x == -1 || x == w || y == -1 || y == h) return false;
    return true;
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

//        printf("insert tow %lld %lld\n", from, to);

    }

    void insert(ll from, ll to, ll cost) {
        edges[from].push_back({to, cost});

//        printf("insert %lld %lld\n", from, to);
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
    int w, h, q;
    cin >> w >> h >> q;

    set<Beam> beams;
    rep(_, q) {
        Beam b{0, 0, 0};
        cin >> b.t >> b.d >> b.x;
        b.x--;
        beams.insert(b);
    }


    int tmax = [&] {
        int ans = 0;
        for (Beam b : beams) cmax(ans, b.t);
        ans++;
        return ans;
    }();

    Dijkstra dijkstra(w * h * tmax + 2);

    // スタートから１個目

    rep(y, h) {
        rep(x, w) {
            int start = w * h * tmax;
            int id = to_id(0, h, w, y, x);
            dijkstra.insert(start, id, 0);
        }
    }


//    cout << endl;

    // 同じ時間同士
    rep(t, tmax) {
        rep(y, h) {
            rep(x, w) {
                int from_id = to_id(t, h, w, y, x);
                for (Direction d : directions) {
                    int ny = y + d.y;
                    int nx = x + d.x;

                    if (!reachable(h, w, ny, nx)) continue;
                    int next_id = to_id(t, h, w, ny, nx);
                    dijkstra.insert(from_id, next_id, 1);
                }
            }
        }
    }
//cout << endl;

    // 時間を超える
    rep(t, tmax - 1) {
        rep(y, h) {
            rep(x, w) {
                int from_id = to_id(t, h, w, y, x);
                if (!reachable(h, w, y, x)) continue;

                if (beams.find(Beam{t + 1, 0, x}) != beams.end()) {
                    continue;
                }
                if (beams.find(Beam{t + 1, 1, y}) != beams.end()) {
                    continue;
                }

                int next_id = to_id(t + 1, h, w, y, x);
                dijkstra.insert(from_id, next_id, 0);
            }
        }
    }


    // 最終面からゴール
    rep(y, h) {
        rep(x, w) {
            int goal = w * h * tmax + 1;
            int from_id = to_id(tmax - 1, h, w, y, x);
            dijkstra.insert(from_id, goal, 0);
        }
    }

    dijkstra.dijkstra(w * h * tmax);
    ll k = dijkstra.distance(w * h * tmax + 1);
    ll ans = k == INF ? -1 : k;

    cout << ans << endl;

}