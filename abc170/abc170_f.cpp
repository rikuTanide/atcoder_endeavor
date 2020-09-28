#include <bits/stdc++.h>
//#include "atcoder/all"
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

struct Point {
    int orientation, y, x;
};

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    int sx, sy, gx, gy;
    cin >> sy >> sx >> gy >> gx;

    sx--;
    sy--;
    gx--;
    gy--;

    vector<vector<char>> board(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> board[y][x];

    vector<vector<vector<int>>> distances(2, vector<vector<int>>(h, vector<int>(w, INT_MAX / 10)));


    rep(o, 2) distances[o][sy][sx] = 0;

    queue<Point> q;
    rep(o, 2) q.push({o, sy, sx});

    auto reachable = [&](int o, int y, int x, int distance) {
        if (x == -1 || x == w || y == -1 || y == h) return false;
        if (board[y][x] == '@') {
            return false;
        }
        if (distances[o][y][x] <= distance) {
            return false;
        }
        return true;
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

    auto mindi = [&](int y, int x) -> int {
        return min(distances[0][y][x], distances[1][y][x]);
    };

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        vector<Direction> ds;
        rep(o, 4) if (o % 2 == p.orientation) ds.push_back(directions[o]);
        for (Direction d : ds) {
            int nd = mindi(p.y, p.x) + 1;

            for (int i = 1; i <= k; i++) {
                int ny = p.y + (d.y * i);
                int nx = p.x + (d.x * i);
                if (!reachable(p.orientation, ny, nx, nd)) break;

                distances[p.orientation][ny][nx] = nd;
                int eo = (p.orientation + 1) % 2;
                if (distances[eo][ny][nx] > nd) q.push({eo, ny, nx});

                if (i == k) {
                    q.push({p.orientation, ny, nx});
                }
            }

        }

    }


//    rep(y, h) {
//        rep(x, w) {
//            int ans = INT_MAX / 10;
//            rep(i, 2) cmin(ans, distances[i][y][x]);
//            if (ans >= INT_MAX / 10) cout << '-';
//            else cout << ans;
//        }
//        cout << endl;
//    }

    int ans = mindi(gy, gx);
    if (ans >= INT_MAX / 10) {
        cout << "-1" << endl;
    } else {
        cout << ans << endl;
    }

}