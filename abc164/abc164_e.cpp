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
    int to, silver;
    ll time;

    Edge(int to, int silver, ll time) : to(to), silver(silver), time(time) {};
};

const ll MAX = 50 * 50;

struct Exchange {
    ll silver, time;
};

struct Data {
    int to_v, use_silver;
    ll time;

    Data(int to_v, int use_silver, ll time) : to_v(to_v), use_silver(use_silver), time(time) {}

    bool operator<(const Data &a) const {
        return time > a.time;
    }
};

// https://atcoder.jp/contests/abc164/submissions/12451637
int main() {
    int n, m;
    ll s;
    cin >> n >> m >> s;
    cmin(s, MAX);

    vector<vector<Edge>> edges(n);

    rep(i, m) {
        int u, v, silver;
        ll time;
        cin >> u >> v >> silver >> time;

        u--;
        v--;

        edges[u].emplace_back(v, silver, time);
        edges[v].emplace_back(u, silver, time);
    }

    vector<Exchange> exchanges(n);
    rep(i, n) cin >> exchanges[i].silver >> exchanges[i].time;
    vector<vector<ll>> dist(n, vector<ll>(MAX + 1, INF));
    priority_queue<Data> q;

    auto push = [&](int to_v, int to_silver, ll value) {
        if (to_silver < 0) return;
        if (dist[to_v][to_silver] <= value) return;
        dist[to_v][to_silver] = value;
        q.emplace(to_v, to_silver, value);
    };

    push(0, s, 0);

    while (!q.empty()) {
        Data d = q.top();
        q.pop();

        int to_v = d.to_v, use_silver = d.use_silver;
        ll time = d.time;
        if (dist[to_v][use_silver] != time) continue;

        int ns = min(use_silver + exchanges[to_v].silver, MAX);
        push(to_v, ns, time + exchanges[to_v].time);

        for (Edge e : edges[to_v]) {
            push(e.to, use_silver - e.silver, time + e.time);
        }
    }

    for (int i = 1; i < n; i++) {
        cout << *min_element(dist[i].begin(), dist[i].end()) << endl;
    }

}
