#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Train {
    int u, v;
    ll a, b;

};


std::istream &operator>>(std::istream &in, Train &o) {
    cin >> o.u >> o.v >> o.a >> o.b;
    o.u--;
    o.v--;
    return in;
}

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
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    s--;
    t--;

    vector<Train> trains(m);
    rep(i, m) cin >> trains[i];

    Dijkstra yen(n), snuuk(n);
    for (Train &train: trains) {
        yen.insertTowWay(train.u, train.v, train.a);
        snuuk.insertTowWay(train.u, train.v, train.b);
    }
    yen.dijkstra(s);
    snuuk.dijkstra(t);


    vector<ll> ans;
    ll mi = 0;
    rep(i, n) {
        int j = n - i - 1;
        ll a = yen.distance(j);
        ll b = snuuk.distance(j);
        ll now = 10e14;
        now -= (a + b);
        cmax(mi, now);
        ans.push_back(mi);
    }
    reverse(ans.begin(), ans.end());
    for (ll l : ans) cout << l << endl;

}
