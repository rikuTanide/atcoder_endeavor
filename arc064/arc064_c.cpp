#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

typedef pair<ll, double> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Circle {
    double x, y, r;
};

// https://qiita.com/ta-ka/items/a023a11efe17ab097433
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

    vector<Circle> circles(n);
    rep(i, n) cin >> circles[i].x >> circles[i].y >> circles[i].r;

    circles.push_back({x1, y1, 0});
    circles.push_back({x2, y2, 0});
    n += 2;


    Dijkstra dijkstra(n);


    rep(i, n) {
        rep(j, n) {
            Circle c1 = circles[i], c2 = circles[j];
            double dx = c1.x - c2.x;
            double dxx = dx * dx;
            double dy = c1.y - c2.y;
            double dyy = dy * dy;

            double d = sqrt(dxx + dyy);
            double sr = max(d - c1.r - c2.r, 0.0);

            dijkstra.insertTowWay(i, j, sr);

        }
    }

    dijkstra.dijkstra(n - 2);
    double ans = dijkstra.distance(n - 1);
    printf("%.20f\n", ans);

}
