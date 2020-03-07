#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef long long ll;
typedef long long ll;
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
const double PI = 3.14159265358979323846;

typedef pair<ll, ll> P;


void warshall_floyd(int n, vector<vector<int>> &distances) {
    for (int k = 0; k < n; k++) {       // 経由する頂点
        for (int i = 0; i < n; i++) {    // 始点
            for (int j = 0; j < n; j++) {  // 終点
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w, 0));

    rep(y, h) rep(x, w) cin >> grid[y][x];


    auto to_id = [&](int y, int x) {
        return y * w + x;
    };


    vector<vector<int >> distance(h * w, vector<int>(h * w, INT_MAX / 100));
    rep(i, h * w) distance[i][i] = 0;


    auto to_next = [&](int y, int x, P p) {
        return P(y + p.first, x + p.second);
    };

    vector<P> directions = {
            P(1, 0),
            P(-1, 0),
            P(0, 1),
            P(0, -1),
    };

    rep(y, h) {
        rep(x, w) {
            for (P p : directions) {
                P next = to_next(y, x, p);
                int ny = next.first;
                int nx = next.second;
                if (ny == -1 || ny == h) continue;
                if (nx == -1 || nx == w) continue;
                if (grid[y][x] == '#') continue;
                if (grid[ny][nx] == '#') continue;

                int f_id = to_id(y, x);
                int t_id = to_id(ny, nx);
                distance[f_id][t_id] = 1;
                distance[t_id][f_id] = 1;
            }
        }
    }

    warshall_floyd(w * h, distance);

    int ans = 0;

    rep(i, w * h) {
        rep(j, w * h) {
            if (distance[i][j] == INT_MAX / 100) continue;
            cmax(ans, distance[i][j]);
        }
    }
    cout << ans << endl;

}

