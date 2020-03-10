#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<int, int> P;
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

struct Point {
    int x, y, distance;
};

int main() {
    int h, w;
    cin >> h >> w;
    int sx, sy, gx, gy;
    cin >> sy >> sx >> gy >> gx;

    sx--;
    sy--;
    gx--;
    gy--;

    vector<vector<char>> board(h, vector<char>(w, ' '));
    rep(y, h) rep(x, w) cin >> board[y][x];
    vector<vector<int>> distances(h, vector<int>(w, INT_MAX / 10));

    distances[sy][sx] = 0;

    queue<Point> q;
    q.push({sx, sy, 0});

    struct Direction {
        int x, y;
    };

    vector<Direction> directions = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1},
    };

    auto reachable = [&](int x, int y, int distance) {
        if (x == -1 || x == w || y == -1 || y == h) return false;
        if (board[y][x] == '#') {
            return false;
        }
        if (distances[y][x] <= distance) {
            return false;
        }
        return true;
    };


    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        for (Direction d : directions) {
            int nx = p.x + d.x;
            int ny = p.y + d.y;
            int nd = p.distance + 1;
            if (reachable(nx, ny, nd)) {
                distances[ny][nx] = nd;
                q.push({nx, ny, nd});
            }
        }
    }

    cout << distances[gy][gx] << endl;

}
