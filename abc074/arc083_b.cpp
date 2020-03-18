#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e15;
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
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

class WarchallFloyd {

    int n;

public:
    vector<vector<ll>> distances;

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

    void set(int from, int to, ll c) {
        distances[from][to] = c;
        distances[to][from] = c;
    }

    ll distance(int from, int to) {
        return distances[from][to];
    }


    friend std::istream &operator>>(std::istream &in, WarchallFloyd &o) {
        int from, to;
        ll c;
        cin >> from >> to >> c;
        from--;
        to--;
        o.set(from, to, c);
        return in;
    }
};

struct Road {
    int from, to;
    ll cost;
};

int main() {
    int n;
    cin >> n;

    vector<vector<ll>> distances(n, vector<ll>(n));
    rep(y, n) rep(x, n) cin >> distances[y][x];

    WarchallFloyd wf(n);
    rep(i, n) rep(j, n) wf.set(i, j, distances[i][j]);
    wf.warshall_floyd();

    if (distances != wf.distances) {
        cout << -1 << endl;
        ret();
    }

    auto is_shortest = [&](int from, int to, int via) {
        ll direct = distances[from][to];
        ll v = distances[from][via] + distances[via][to];
        return direct < v;
    };

    auto is_all_shortest = [&](int from, int to) {
        rep(k, n) {
            if (k == from || k == to) continue;
            // iからjに行く最短距離よりiからjを経由したほうが近ければfalse
            bool b = is_shortest(from, to, k);
            if (!b) return false;
        }
        return true;
    };

    vector<Road> roads;
    rep(i, n)rep(j, n)if (i < j) roads.push_back({i, j, distances[i][j]});
    sort(roads.begin(), roads.end(), [](Road &r, Road &s) { return r.cost < s.cost; });
    ll ans = 0;
    for (Road &r : roads) {
        bool b = is_all_shortest(r.from, r.to);
        if (!b) {
            continue;
        }
        ans += r.cost;
    }

    cout << ans << endl;
}

