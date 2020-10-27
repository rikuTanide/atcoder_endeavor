#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int solve(int h, int w, int sy, int sx, int gy, int gx, vector<vector<char>> &board) {

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
            int nd = p.cost + 1;
            if (reachable(ny, nx, nd)) {
                distances[ny][nx] = nd;
                q.push({ny, nx, nd});
            }
        }
    }

    return distances[gy][gx];
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> board(h, vector<char>(w, ' '));
    rep(y, h) rep(x, w) cin >> board[y][x];

    auto find = [&](char c) -> P {
        rep(y, h) {
            rep(x, w) {
                if (board[y][x] == c) return P(y, x);
            }
        }
        throw_with_nested("konaide");
    };

    P start = find('S');
    P cp = find('C');
    P goal = find('G');

    int ans =
            solve(h, w, start.first, start.second, cp.first, cp.second, board)
            + solve(h, w, cp.first, cp.second, goal.first, goal.second, board);

    if (ans >= INT_MAX / 10) {
        cout << -1 << endl;
        ret();
    }

    cout << ans << endl;

}
