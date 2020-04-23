#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Participant {
    double x, y, throw_limit, catch_limit;
};

std::istream &operator>>(std::istream &in, Participant &o) {
    cin >> o.x >> o.y >> o.throw_limit >> o.catch_limit;
    return in;
}

struct Edge {
    ll to;
    double cost;
};


class Dijkstra {

    vector<double> distances;
    vector<vector<Edge>> edges;

public:
    Dijkstra(ll n) {
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
    int n;
    cin >> n;
    vector<Participant> participants(n);
    rep(i, n) cin >> participants[i];

    Dijkstra dijkstra(n);

    rep(i, n) rep(j, n) {
            if (i == j) continue;
            Participant p1 = participants[i], p2 = participants[j];
            double speed = min(p1.throw_limit, p2.catch_limit);

            double x = p1.x - p2.x;
            double y = p1.y - p2.y;
            double xx = x * x;
            double yy = y * y;

            double distance = sqrt(xx + yy);
            double cost = distance / speed;
            dijkstra.insert(i, j, cost);
        }
    dijkstra.dijkstra(0);

    vector<double> time(n);
    rep(i, n) {
        if (i == 0) continue;
        time[i] = dijkstra.distance(i);
    }
    sort(time.rbegin(), time.rend());
    rep(i, n - 1) {
        time[i] += (1.0 * i);
    }

    double ans = *max_element(time.begin(), time.end());
    printf("%.20f\n", ans);


}
