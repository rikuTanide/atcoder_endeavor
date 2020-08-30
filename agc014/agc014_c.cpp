#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

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

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<vector<char>> board(h, vector<char>(w, ' '));
    rep(y, h) rep(x, w) cin >> board[y][x];
    vector<vector<int>> distances(h, vector<int>(w, INT_MAX / 10));

    P start = [&] {
        rep(y, h) {
            rep(x, w) {
                if (board[y][x] == 'S') return P(y, x);
            }
        }
        __throw_runtime_error("konaide");
    }();

    distances[start.first][start.second] = 0;
    struct Point {
        ll y, x, cost;
    };

    queue<Point> q;
    q.push({start.first, start.second, 0});

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

    auto calc = [&](int y, int x) -> int {
        auto p = [&](int a) -> int {
            return (a + k - 1) / k;
        };
        int l = p(x);
        int r = p(w - x - 1);
        int u = p(y);
        int d = p(h - y - 1);


        return min({l, r, u, d});
    };

    int ans = INT_MAX;
    rep(y, h) {
        rep(x, w) {
            if (distances[y][x] > k) continue;
            int now = calc(y, x);
            cmin(ans, now);
        }
    }
    cout << ans + 1 << endl;
}
