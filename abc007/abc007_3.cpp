#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef long long ll;
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;
// https://atcoder.jp/contests/abc008/submissions/9264344
// なんもわからん。

struct Cell {
    int x, y, shortness;
};

int bfs(int sx, int sy, int gx, int gy, vector<vector<char>> maze, int w, int h) {
    vector<vector<int> > shortness(h, vector<int>(w, -1));

    queue<Cell> q;
    {
        Cell start = {sx, sy, 0};
        q.push(start);
    }

    while (!q.empty()) {
        Cell c = q.front();
        q.pop();
        if (c.x < 0 || w <= c.x) continue;
        if (c.y < 0 || h <= c.y) continue;
        if (maze[c.y][c.x] == '#') continue;
        if (shortness[c.y][c.x] > -1) continue;
        shortness[c.y][c.x] = c.shortness;
        {
            Cell n = {c.x + 1, c.y, c.shortness + 1};
            q.push(n);
        }
        {
            Cell n = {c.x - 1, c.y, c.shortness + 1};
            q.push(n);
        }
        {
            Cell n = {c.x, c.y + 1, c.shortness + 1};
            q.push(n);
        }
        {
            Cell n = {c.x, c.y - 1, c.shortness + 1};
            q.push(n);
        }
    }
    return shortness[gy][gx];
}

int main() {
    int r, c;
    cin >> r >> c;

    int sx, sy, gx, gy;
    cin >> sy >> sx >> gy >> gx;
    sx--;
    sy--;
    gx--;
    gy--;

    vector<vector<char> > maze(r, vector<char>(c));
    rep(y, r) rep(x, c) cin >> maze[y][x];
    cout << bfs(sx, sy, gx, gy, maze, c, r) << endl;

}
