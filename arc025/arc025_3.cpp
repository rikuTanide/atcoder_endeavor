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
    ll from;
};

std::istream &operator>>(std::istream &in, Edge &o) {
    cin >> o.from >> o.to >> o.cost;
    o.from--;
    o.to--;
    return in;
}

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

struct RangeCount {
    int upper, r_equal, between, l_equal, lower;

    friend std::ostream &operator<<(std::ostream &out, const RangeCount &o) {
        cout << endl;
        cout << "upper" << ' ' << o.upper << endl;
        cout << "r_equal" << ' ' << o.r_equal << endl;
        cout << "between" << ' ' << o.between << endl;
        cout << "l_equal" << ' ' << o.l_equal << endl;
        cout << "lower" << ' ' << o.lower << endl;
        return out;
    }
};

RangeCount range_count(vector<ll>::iterator begin, vector<ll>::iterator end, ll l, ll r) {
    if (l > r) return RangeCount{0, 0, 0, 0, 0};
    if (begin >= end) return RangeCount{0, 0, 0, 0, 0};

    if (l == r) {
        RangeCount rc;
        auto it = std::equal_range(begin, end, r);

        rc.upper = distance(it.second, end);
        rc.r_equal = distance(it.first, it.second);
        rc.between = 0;
        rc.l_equal = rc.r_equal;
        rc.lower = distance(begin, it.first);

        return rc;
    }

    RangeCount rc;
    auto it_r = std::equal_range(begin, end, r);
    auto it_l = std::equal_range(begin, end, l);

    auto it_ru = it_r.second;
    auto it_rl = it_r.first;
    rc.upper = distance(it_ru, end);
    rc.r_equal = distance(it_rl, it_ru);
    auto it_lu = it_l.second;
    auto it_ll = it_l.first;
    rc.between = distance(it_lu, it_rl);
    rc.l_equal = distance(it_ll, it_lu);
    rc.lower = distance(begin, it_ll);

    return rc;

}


int main() {
    int n, m, usa, kame;
    cin >> n >> m >> usa >> kame;

    vector<Edge> edges(m);
    rep(i, m) cin >> edges[i];
    ll ans = 0;

    rep(goal, n) {
        Dijkstra dijkstra(n);
        for (Edge edge : edges) dijkstra.insertTowWay(edge.from, edge.to, edge.cost);
        dijkstra.dijkstra(goal);

        vector<ll> kame_times, usa_times;
        rep(j, n) {
            if (j == goal)continue;
            ll len = dijkstra.distance(j);
            kame_times.push_back(len * usa);
            usa_times.push_back(len * kame);
        }
        sort(kame_times.begin(), kame_times.end());
        sort(usa_times.begin(), usa_times.end());

        for (ll kame_time : kame_times) {
            auto rc = range_count(usa_times.begin(), usa_times.end(), kame_time, kame_time);
            ans += rc.upper;
        }

    }
    cout << ans << endl;

}
