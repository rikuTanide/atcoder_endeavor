#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<double, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

struct Circle {
    double x, y, r;
};

std::istream &operator>>(std::istream &in, Circle &o) {
    in >> o.x >> o.y >> o.r;
    return in;
}

struct Edge {
    ll to;
    double cost;
};


class Dijkstra {
    ll vector_count;

    vector<double> distances;
    vector<vector<Edge>> edges;

public:
    Dijkstra(ll n) {
        vector_count = n;
        distances.resize(n, INF);
        edges.resize(n);
    }

    void insertTowWay(ll from, ll to, double cost) {
        edges[from].push_back({to, cost});
        edges[to].push_back({from, cost});
    }

    void insert(ll from, ll to, double cost) {
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

    double distance(ll to) {
        return distances[to];
    }

};


int main() {

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;


    int n;
    cin >> n;

    vector<Circle> v(n);
    rep(i, n) cin >> v[i];

    n += 2;
    v.push_back({x1, y1, 0});
    v.push_back({x2, y2, 0});

    Dijkstra dijkstra(n);

    rep(i, n) {
        rep(j, n) {
            if (i >= j) continue;

            Circle a = v[i], b = v[j];

            double x = a.x - b.x;
            double y = a.y - b.y;
            double xx = x * x;
            double yy = y * y;
            double sq = sqrt(xx + yy);

            double d = max<double>(sq - a.r - b.r, 0);

            dijkstra.insertTowWay(i, j, d);
        }
    }
    dijkstra.dijkstra(n - 1);
    double ans = dijkstra.distance(n - 2);
    cout << setprecision(20) << ans << endl;


}