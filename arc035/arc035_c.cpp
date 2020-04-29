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

        cmin(o.distances[from][to], c);
        cmin(o.distances[to][from], c);
        return in;
    }

    void diff(int from, int to, ll c) {
        cmin(distances[from][to], c);
        cmin(distances[to][from], c);

        rep(x, n) rep(y, n) {
                ll minc = distances[x][y];
                cmin(minc, distances[x][from] + distances[from][to] + distances[to][y]);
                cmin(minc, distances[x][to] + distances[to][from] + distances[from][y]);

                cmin(distances[x][y], minc);
                cmin(distances[y][x], minc);
            }

    }


    ll sum() {
        ll ans = 0;
        rep(i, n) rep(j, n) {
                ans += distance(i, j);
            }
        ans /= 2;
        return ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    WarchallFloyd wf(n);
    rep(i, m) cin >> wf;
    wf.warshall_floyd();

    int q;
    cin >> q;
    rep(i, q) {
        int from, to;
        ll cost;
        cin >> from >> to >> cost;
        from--;
        to--;
        wf.diff(from, to, cost);
        cout << wf.sum() << endl;
    }

}
