#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;


struct Lottery {
    int count;
    int cost;
    int bits = 0;
    vector<double> rates;

    Lottery(int n) : rates(n) {}


};

std::istream &operator>>(std::istream &in, Lottery &o) {
    cin >> o.count;
    cin >> o.cost;
    rep(i, o.count) {
        int idol;
        cin >> idol;
        idol--;
        cin >> o.rates[idol];
        o.rates[idol] /= 100;
        o.bits |= (1 << idol);

    }

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
    int n, m;
    cin >> n >> m;

    vector<Lottery> lotteries(m, Lottery(n));

    rep(i, m)cin >> lotteries[i];

    int state_max = 1 << n;

    Dijkstra dijkstra(state_max);

    vector<double> dp(n, 0);

    rep(i, state_max) {
        for (Lottery &lottery: lotteries) {
            rep(j, n) {
                if (lottery.rates[j] == 0) continue;

                int next_bit = i | (1 << j);

                double cost = (1.0 / lottery.rates[j]) * lottery.cost;
                dijkstra.insert(i, next_bit, cost);

            }
        }
    }

    dijkstra.dijkstra(0);
    double ans = dijkstra.distance(state_max - 1);
    printf("%.20f\n", ans);
}
