#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

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

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

const int MAX = 4040404;

struct V {
    int u, v;
    ll d;

};

std::istream &operator>>(std::istream &in, V &o) {
    cin >> o.u >> o.v >> o.d;
    o.u--;
    o.v--;
    return in;
}

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

const int mod = 1000000007;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}

    mint &operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }

    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }

    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }

    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod - 2);
    }

    mint &operator/=(const mint a) {
        return (*this) *= a.inv();
    }

    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }

    friend std::istream &operator>>(std::istream &in, mint &o) {
        ll a;
        in >> a;
        o = a;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const mint &o) {
        out << o.x;
        return out;
    }

};

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    vector<V> edges(m);
    rep(i, m) cin >> edges[i];

    Dijkstra dijkstra(n);
    for (V v: edges) dijkstra.insertTowWay(v.u, v.v, v.d);
    dijkstra.dijkstra(s);

    vector<P> dis_order(n);
    rep(i, n) dis_order[i] = P(dijkstra.distance(i), i);
    sort(dis_order.begin(), dis_order.end());

    vector<ll> dp1(n, 0);
    dp1[s] = 1;
    rep(i, n) {
        for (Edge e: dijkstra.edges[dis_order[i].second]) {
            if (dijkstra.distance(dis_order[i].second) + e.cost == dijkstra.distance(e.to)) {
                dp1[e.to] += dp1[dis_order[i].second];
            }
        }
    }

    vector<ll> dp2(n);
    dp2[t] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (Edge e: dijkstra.edges[dis_order[i].second]) {
            if (dijkstra.distance(dis_order[i].second) == dijkstra.distance(e.to) + e.cost) {
                dp2[e.to] += dp2[dis_order[i].second];
            }
        }
    }

    ll dt = dijkstra.distance(t);


    mint ans = dp1[t] * dp1[t];
    rep(i, n) {
        if (dijkstra.distance(i) * 2 == dt) {
            ans -= dp1[i] * dp1[i] * dp2[i] * dp2[i];
        }
    }


    rep(i, m) {
        int u = edges[i].u, v = edges[i].v;
        ll du = dijkstra.distance(u);
        ll dv = dijkstra.distance(v);
        if (du > dv) swap(u, v), swap(du, dv);
        if (2 * du < dt && 2 * dv > dt && du + edges[i].d == dv) {
            ans -= dp1[u] * dp1[u] * dp2[v] * dp2[v];
        }
    }

    cout << ans << endl;

}