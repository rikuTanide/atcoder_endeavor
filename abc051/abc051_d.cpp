#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, int> P;
const ll INF = 1e15;
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

void warshall_floyd(int n, vector<vector<ll>> &distances) {
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

struct Edge {
    int from, to, distance;

    friend std::istream &operator>>(std::istream &in, Edge &o) {
        int a, b, c;
        in >> a >> b >> c;
        a--;
        b--;
        o.from = a;
        o.to = b;
        o.distance = c;
        return in;
    }

};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    rep(i, m) cin >> edges[i];

    vector<vector<ll>> distance(n, vector<ll>(n, INF));
    rep(i, n) distance[i][i] = 0;

    for (Edge edge : edges) distance[edge.from][edge.to] = edge.distance;
    for (Edge edge : edges) distance[edge.to][edge.from] = edge.distance;

    warshall_floyd(n, distance);

    int ans = 0;
    for (Edge edge : edges) if (distance[edge.from][edge.to] != edge.distance) ans++;
    cout << ans << endl;
}
