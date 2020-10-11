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

struct Bridge {
    ll len, w;
};

map<ll, ll> create_w_len(vector<ll> &camels, vector<Bridge> &bridges) {
    map<ll, ll> res;

    int n = camels.size();
    rep(i, 1 << n) {
        ll w = 0;
        rep(j, n) if ((i >> j) & 1) w += camels[j];
        ll sz = 0;
        for (Bridge &b: bridges) if (b.w < w) cmax(sz, b.len);
        res[w] = sz;
    }

    return res;
}


// https://qiita.com/ta-ka/items/a023a11efe17ab097433
struct Edge {
    ll to, cost;
};

// 特定のルートまでに閉路があるか調べたいならこう
// https://atcoder.jp/contests/abc061/submissions/12926139
// https://atcoder.jp/contests/abc137/submissions/13373201
vector<ll> bellman_ford(int n, int s, vector<vector<Edge> > &graph) { // nは頂点数、sは開始頂点
    vector<ll> dist(n, INF);
    dist[s] = 0; // 開始点の距離は0
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            for (int k = 0; k < graph[v].size(); k++) {
                Edge e = graph[v][k];
                if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            for (int k = 0; k < graph[v].size(); k++) {
                Edge e = graph[v][k];
                if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = -INF;
                }
            }
        }
    }

    return dist;
}


ll solve(vector<ll> &camels, vector<Bridge> &bridges, map<ll, ll> &w_l) {

    vector<vector<Edge> > edges(camels.size());

    for (int i = 0; i < camels.size(); i++) {
        for (int j = i + 1; j < camels.size(); j++) {
            ll w = 0;
            for (int t = i; t <= j; t++) {
                w += camels[t];
            }

            ll l = w_l[w];
            if (l == INF) edges[i].push_back({j, 0});
            else edges[i].push_back({j, -l});
        }
    }

    auto bf = bellman_ford(camels.size(), 0, edges);
    ll ans = -bf.back();
    return ans;

}

// 重さごとの橋の最短を求める
// あるラクダからあるラクダまでの重さを出す
// あるラクダからあるラクダまでの長さを出す
// 逆ワーシャルフロイドにかける

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> camels(n);
    rep(i, n) cin >> camels[i];


    vector<Bridge> bridges(m);
    for (Bridge &b : bridges) cin >> b.len >> b.w;

    auto is_enable = [&]() -> bool {

        for (Bridge b : bridges) {
            for (ll l : camels) {
                if (b.w < l) return false;
            }
        }

        return true;
    };

    if (!is_enable()) {
        cout << -1 << endl;
        ret();
    }

    map<ll, ll> w_l = create_w_len(camels, bridges);

    vector<int> arr(n);
    rep(i, n)arr[i] = i;

    ll ans = INF;
    do {
        vector<ll> tmp_camels(n);
        rep(i, n) tmp_camels[i] = camels[arr[i]];
        ll now = solve(tmp_camels, bridges, w_l);
        cmin(ans, now);
    } while (std::next_permutation(arr.begin(), arr.end()));
    cout << ans << endl;
}
