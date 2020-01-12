#include <bits/stdc++.h>
#include <cmath>

using namespace std;
//typedef long long ll;
typedef unsigned long long ll;

//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;


// https://qiita.com/okaryo/items/8e6cd73f8a676b7a5d75
void warshall_floyd(int n, vector<vector<int>> &d) {
    for (int k = 0; k < n; k++) {       // 経由する頂点
        for (int i = 0; i < n; i++) {    // 始点
            for (int j = 0; j < n; j++) {  // 終点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> maze(h, vector<char>(w));

    rep(y, h) rep(x, w) {
            char c;
            cin >> c;
            maze[y][x] = c;
        }

    vector<vector<int>> distances(h * w, vector<int>(h * w, 1000));

    auto toID = [&](int y, int x) {
        return y * w + x;
    };

    vector<P> move = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0},
    };

    rep(y, h) rep(x, w) {
            if (maze[y][x] == '#') continue;
            for (P p : move) {
                int cy = p.first;
                int cx = p.second;

                int ny = y + cy;
                int nx = x + cx;

                if (ny == -1) continue;
                if (nx == -1) continue;
                if (ny == h) continue;
                if (nx == w) continue;

                if (maze[y][x] == '.' && maze[ny][nx] == '.') {
                    distances[toID(y, x)][toID(ny, nx)] = 1;
                    distances[toID(ny, nx)][toID(y, x)] = 1;
                }
            }
        }


    warshall_floyd(w * h, distances);

    int ans = 0;
    rep(i, h * w) rep(j, h * w) {
            int d = distances[i][j];
            if (d >= 1000) {
                continue;
            }
            cmax(ans, d);
        }
    assert(ans < 1000);
    cout << ans << endl;
}
