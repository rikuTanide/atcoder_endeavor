#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;


void moveAll(vector<vector<char>> &map, vector<vector<int>> &dijkstra, int y, int x, int h, int w);

void
on(vector<vector<char>> &map, vector<vector<int>> &dijkstra, int fromY, int fromX, int toY, int toX, int h, int w) {
    int fromCost = dijkstra[fromY][fromX];
    int toCost = dijkstra[toY][toX];
    if (map[toY][toX] == '#') return;
    if (fromCost + 1 >= toCost) return;

    dijkstra[toY][toX] = fromCost + 1;
    moveAll(map, dijkstra, toY, toX, h, w);

}


void moveAll(vector<vector<char>> &map, vector<vector<int>> &dijkstra, int y, int x, int h, int w) {
    if (x + 1 < w) {
        on(map, dijkstra, y, x, y, x + 1, h, w);
    }
    if (y + 1 < h) {
        on(map, dijkstra, y, x, y + 1, x, h, w);
    }
    if (x - 1 >= 0) {
        on(map, dijkstra, y, x, y, x - 1, h, w);
    }
    if (y - 1 >= 0) {
        on(map, dijkstra, y, x, y - 1, x, h, w);
    }

}

int main() {

    int h, w;
    cin >> h >> w;
    vector<vector<char>> map(h, vector<char>(w));
    rep(y, h)rep(x, w) cin >> map[y][x];
    vector<vector<int>> dijkstra(h, vector<int>(w, INF));
    dijkstra[0][0] = 1;
    moveAll(map, dijkstra, 0, 0, h, w);

    int start_white = 0;
    rep(y, h)rep(x, w) if (map[y][x] == '.') start_white++;

    int dijkstra_difference = dijkstra[h - 1][w - 1];

    if (dijkstra_difference == INF) {
        cout << -1 << endl;
        return 0;
    }

    int ans = start_white - dijkstra_difference;

    cout << ans << endl;
}