#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<long double , ll> P;
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

struct User {
    long double x, y, t, r;
};


std::istream &operator>>(std::istream &in, User &o) {
    in >> o.x >> o.y >> o.t >> o.r;
    return in;
}

// https://qiita.com/ta-ka/items/a023a11efe17ab097433
struct Edge {
    ll to;
    long double cost;
};


class Dijkstra {
    ll vector_count;

    vector<long double> distances;
    vector<vector<Edge>> edges;

public:
    Dijkstra(ll n) {
        vector_count = n;
        distances.resize(n, INF);
        edges.resize(n);
    }

    void insertTowWay(ll from, ll to, long double cost) {
        edges[from].push_back({to, cost});
        edges[to].push_back({from, cost});
    }

    void insert(ll from, ll to, long double cost) {
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

    long double distance(ll to) {
        return distances[to];
    }

};

int main() {
    int n;
    cin >> n;

    vector<User> users(n);
    rep(i, n) cin >> users[i];

    Dijkstra dijkstra(n);

    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            User u = users[i], t = users[j];
            long double speed = min(u.t, t.r);

            long double x = u.x - t.x;
            long double y = u.y - t.y;
            long double xx = x * x;
            long double yy = y * y;

            long double dis = sqrt(xx + yy);
            long double time = dis / speed;
            dijkstra.insert(i, j, time);

        }
    }

    dijkstra.dijkstra(0);

    vector<long double> v(n);
    rep(i, n) v[i] = dijkstra.distance(i);
    sort(v.rbegin(), v.rend());
    rep(i, n) v[i] += i;

    long double ans = *max_element(v.begin(), v.end());
    cout << setprecision(20) << ans << endl;

}
