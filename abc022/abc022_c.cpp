#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


class WarchallFloyd {

    int n;
    vector<vector<ll>> distances;

public:
    WarchallFloyd(int n) : n(n), distances(n, vector<ll>(n, INF)) {
        rep(i, n) distances[i][i] = 0;
    };

    void warshall_floyd() {
        for (int k = 0; k < n; k++) {       // 経由する頂点
            for (int i = 0; i < n; i++) {    // 始点
                for (int j = 0; j < n; j++) {  // 終点
                    if (distances[i][j] == INF && (distances[i][k] == INF || distances[k][j] == INF)) {
                        distances[i][j] = INF;
                    } else {
                        distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                    }
                }
            }
        }
    }

    ll distance(int from, int to) {
        return distances[from][to];
    }

    void add(int from, int to, ll cost) {
        distances[from][to] = cost;
        distances[to][from] = cost;
    }

    friend std::istream &operator>>(std::istream &in, WarchallFloyd &o) {
        int from, to;
        ll c;
        cin >> from >> to >> c;
        from--;
        to--;

        o.distances[from][to] = c;
        o.distances[to][from] = c;
        return in;
    }


};

struct Road {
    int x, y;
    ll cost;

    friend std::istream &operator>>(std::istream &in, Road &o) {
        int from, to;
        ll c;
        cin >> from >> to >> c;
        from--;
        to--;

        o.x = from;
        o.y = to;
        o.cost = c;

        return in;
    }


};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Road> roads(m);
    rep(i, m) cin >> roads[i];

    vector<Road> near;
    for (Road r : roads) {
        if (r.x == 0 || r.y == 0) near.push_back(r);
    }

    WarchallFloyd wf(n);
    for (Road r : roads) {
        if (!(r.x == 0 || r.y == 0))wf.add(r.x, r.y, r.cost);
    }
    wf.warshall_floyd();

    ll ans = INF;

    for (int i = 0; i < near.size(); i++) {
        for (int j = i + 1; j < near.size(); j++) {
            ll cost = wf.distance(near[i].y, near[j].y);
            if (cost == INF) continue;
            ll now = near[i].cost + near[j].cost + cost;
            cmin(ans, now);
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

}

