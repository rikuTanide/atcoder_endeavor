#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
#include "atcoder/all"

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


P get_rd(int h, int w, vector<vector<char>> &board) {
    for (int y = h - 1; y >= 0; y--) {
        for (int x = w - 1; x >= 0; x--) {
            if (board[y][x] == 'o') return {y, x};
        }
    }
    return {-1, -1};
}

P calc_dp(int h, int w, vector<vector<char>> &board, P rd) {
    vector<vector<int>> distances(h, vector<int>(w, INT_MAX / 10));

    distances[rd.first][rd.second] = 0;
    struct Point {
        ll y, x, cost;
    };

    queue<Point> q;
    q.push({rd.first, rd.second, 0});

    auto to_id = [&](int y, int x) {
        return y * w + x;
    };

    struct Direction {
        int y, x;
    };

    vector<Direction> directions = {
            {0, 1},
            {1, 0},
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

    int ma = 0;
    for (int y = h - 1; y >= 0; y--) {
        for (int x = w - 1; x >= 0; x--) {
            if (distances[y][x] >= INT_MAX / 100) continue;
            cmax(ma, distances[y][x]);
        }
    }
    for (int y = h - 1; y >= 0; y--) {
        for (int x = w - 1; x >= 0; x--) {
            if (distances[y][x] == ma) return {y, x};
        }
    }
    __throw_runtime_error("konaide");
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> board(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> board[y][x];

    ll ans = 0;
    while (true) {
        P rd = get_rd(h, w, board);
        if (rd == P(-1, -1)) break;

        P next = calc_dp(h, w, board, rd);
        board[rd.first][rd.second] = '.';
        board[next.first][next.second] = '#';
        ll now = (next.first - rd.first) + (next.second - rd.second);
        ans += now;
//
//        rep(y, h) {
//            rep(x, w) cout << board[y][x];
//            cout << endl;
//        }
//        cout << endl;

    }
    cout << ans << endl;
}
