#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
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
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

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

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<ll>> magic_point(10, vector<ll>(10));
    rep(y, 10) rep(x, 10) cin >> magic_point[y][x];
    warshall_floyd(10, magic_point);
    vector<vector<int>> wall(h, vector<int>(w));
    rep(y, h) rep(x, w) cin >> wall[y][x];

    ll ans = 0;
    rep(y, h) rep(x, w) if (wall[y][x] != -1) ans += magic_point[wall[y][x]][1];
    cout << ans << endl;
}