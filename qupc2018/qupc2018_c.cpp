#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

vector<vector<char>> solve_p_board(int h, int w, int k, vector<vector<char>> board) {
    vector<vector<int>> distances(h, vector<int>(w, INT_MAX / 10));


    struct Point {
        ll y, x, cost;
    };
    queue<Point> q;

    rep(y, h) rep(x, w) {
            if (board[y][x] != '@') continue;
            distances[y][x] = 0;
            q.push({y, x, 0});
        }

    auto to_id = [&](int y, int x) {
        return y * w + x;
    };

    struct Direction {
        int y, x;
    };

    vector<Direction> directions = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0},
    };


    auto reachable = [&](int y, int x, int distance) {
        if (x == -1 || x == w || y == -1 || y == h) return false;
        if (board[y][x] == '#' || board[y][x] == '@') {
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
            int nd = p.cost + 1;
            if (reachable(ny, nx, nd)) {
                distances[ny][nx] = nd;
                q.push({ny, nx, nd});
            }
        }
    }
    vector<vector<char>> next = board;
    rep(y, h) rep(x, w) {
            if (board[y][x] == '#') continue;
            if (distances[y][x] <= k) next[y][x] = '#';
        }
    return next;
}

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<vector<char>> board(h, vector<char>(w, ' '));
    rep(y, h) rep(x, w) cin >> board[y][x];
    auto p_board = solve_p_board(h, w, k, board);

    int sx = -1, sy = -1, gx = -1, gy = -1;
    rep(y, h) {
        rep(x, w) {
            if (p_board[y][x] == 'S') {
                sx = x;
                sy = y;
            }
            if (p_board[y][x] == 'G') {
                gx = x;
                gy = y;
            }
        }
    }


    vector<vector<int>> distances(h, vector<int>(w, INT_MAX / 10));

    distances[sy][sx] = 0;
    struct Point {
        ll y, x, cost;
    };

    queue<Point> q;
    q.push({sy, sx, 0});

    auto to_id = [&](int y, int x) {
        return y * w + x;
    };

    struct Direction {
        int y, x;
    };

    vector<Direction> directions = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0},
    };


    auto reachable = [&](int y, int x, int distance) {
        if (x == -1 || x == w || y == -1 || y == h) return false;
        if (p_board[y][x] == '#') {
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
            int nd = p.cost + 1;
            if (reachable(ny, nx, nd)) {
                distances[ny][nx] = nd;
                q.push({ny, nx, nd});
            }
        }
    }

    if (sx == -1 || gx == -1) {
        cout << -1 << endl;
        ret();
    }

    int ans = distances[gy][gx];
    if (ans >= INT_MAX / 10) {
        cout << -1 << endl;
        ret();
    }
    cout << ans << endl;

}
