#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

typedef pair<ll, ll> P;

P get_start(vector<vector<char>> &board, int h, int w) {
    rep(y, h) rep(x, w) {
            if (board[y][x] == 'S') return P(y, x);
        }
    __throw_runtime_error("");
}

ll check(ll y, ll x, ll h, ll w, ll k) {
    ll l = (x + k - 1) / k;
    ll u = (y + k - 1) / k;
    ll r = (w - x - 1 + k - 1) / k;
    ll d = (h - y - 1 + k - 1) / k;

    return min({l, u, r, d});

}

int main() {
    ll h, w, k;
    cin >> h >> w >> k;


    vector<vector<char>> board(h, vector<char>(w, ' '));
    rep(y, h) rep(x, w) cin >> board[y][x];
    vector<vector<int>> distances(h, vector<int>(w, INT_MAX / 10));

    P s = get_start(board, h, w);

    distances[s.first][s.second] = 0;

    struct Point {
        ll y, x, cost;
    };

    queue<Point> q;
    q.push({s.first, s.second, 0});

    auto to_id = [&](int y, int x) {
        return y * w + x;
    };

    struct Direction {
        int x, y;
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

    ll ans = INF;
    rep(y, h) rep(x, w) {
            if (distances[y][x] > k) continue;
            ll now = check(y, x, h, w, k) + 1;
            cmin(ans, now);
        }
    cout << ans << endl;

}
