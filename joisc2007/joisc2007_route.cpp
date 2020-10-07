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
// https://qiita.com/ta-ka/items/a023a11efe17ab097433
struct Edge {
    ll to, cost;
};


class Dijkstra {
    ll vector_count;

    vector<ll> distances;

public:
    vector<vector<Edge>> edges;

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
//        cout << from << ' ' << to << endl;
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
    int n, m;
    cin >> n >> m;

    vector<P> points(n);
    for (P &p:points)cin >> p.first >> p.second;


    auto in = [&](int i) -> int {
        return i;
    };
    auto out = [&](int i) -> int {
        return i + m;
    };

    struct Road {
        int start, goal, cost;
    };

    vector<Road> roads(m);

    for (Road &r : roads)cin >> r.start >> r.goal >> r.cost, r.start--, r.goal--;

    Dijkstra dijkstra(2 * m + 2);

    rep(i, m) {
        if (roads[i].start == 0 || roads[i].goal == 0) dijkstra.insert(m * 2, in(i), 0);
        if (roads[i].start == 1 || roads[i].goal == 1) dijkstra.insert(out(i), m * 2 + 1, 0);
    }

    rep(i, m) {
        dijkstra.insert(in(i), out(i), roads[i].cost);
    }

    auto is_connect = [&](int x, int y) -> bool {
        set<int> s;
        s.insert(roads[x].start);
        s.insert(roads[x].goal);
        s.insert(roads[y].start);
        s.insert(roads[y].goal);

        return s.size() == 3;
    };

    auto get_v = [&](int x, int y) -> int {
        map<int, int> mp;
        mp[roads[x].start]++;
        mp[roads[x].goal]++;
        mp[roads[y].start]++;
        mp[roads[y].goal]++;

        for (auto e : mp) if (e.second == 2) return e.first;
    };


    auto get_eis = [&](int x, int y) -> P {
        map<int, int> mp;
        mp[roads[x].start]++;
        mp[roads[x].goal]++;
        mp[roads[y].start]++;
        mp[roads[y].goal]++;
        vector<int> a;
        for (auto e : mp) if (e.second == 1) a.push_back(e.first);

        return P(a[0], a[1]);
    };

    auto is_acute = [&](int x, int y) -> bool {
        int vi = get_v(x, y);
        P eis = get_eis(x, y);

        P v = points[vi];
        P e1 = points[eis.first];
        P e2 = points[eis.second];

        e1.first -= v.first;
        e1.second -= v.second;
        e2.first -= v.first;
        e2.second -= v.second;

        double tan1 = atan2(e1.second, e1.first);
        double tan2 = atan2(e2.second, e2.first);

        if (tan1 < 0) tan1 += PI * 2;
        if (tan2 < 0) tan2 += PI * 2;

        double tan = abs(tan1 - tan2);

        return tan < PI / 2 - EPS;


    };

    for (int x = 0; x < m; x++) {
        for (int y = x + 1; y < m; y++) {
            if (!is_connect(x, y))continue;
            if (is_acute(x, y)) continue;;
            dijkstra.insert(out(x), in(y), 0);
            dijkstra.insert(out(y), in(x), 0);
        }
    }
    dijkstra.dijkstra(2 * m);
    cout << dijkstra.distance(2 * m + 1) << endl;

}
