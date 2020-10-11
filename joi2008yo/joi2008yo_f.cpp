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
        if (distances[from][to] >= INF) return -1;
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

    void update(int x, int y, ll z) {
        cmin(distances[x][y], z);
        cmin(distances[y][x], z);

        rep(i, n) {
            rep(j, n) {
                ll a1 = distances[i][x] + z + distances[y][j];
                ll a2 = distances[i][y] + z + distances[x][j];
                ll mi = min(a1, a2);
                cmin(distances[i][j], mi);
                distances[j][i] = distances[i][j];
            }
        }

    }

    ll sum() {
        ll all = 0;
        rep(i, n) {
            rep(j, n) {
                all += distances[i][j];
            }
        }
        all /= 2;
        return all;
    }

};


int main() {
    int n, m;
    cin >> n >> m;

    WarchallFloyd wf(n);

    rep(_, m) {
        int k;
        cin >> k;
        if (k == 0) {
            int s, t;
            cin >> s >> t;

            s--;
            t--;
            cout << wf.distance(s, t) << endl;
        } else {
            int a, b, e;
            cin >> a >> b >> e;
            a--;
            b--;
            wf.update(a, b, e);
        }
    }

}
