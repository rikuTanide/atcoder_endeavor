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

struct Goal {
    int y, x, point;
};

vector<Goal> calc_distance(int start_y, int start_x, int h, int w, vector<vector<char>> &board) {
    vector<vector<int>> distances(h, vector<int>(w, INT_MAX / 10));

    distances[start_y][start_x] = 0;
    struct Point {
        ll y, x, cost;
    };

    queue<Point> q;
    q.push({start_y, start_x, 0});


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

    vector<Goal> ans;
    rep(y, h) {
        rep(x, h) {
            if (distances[y][x] >= INT_MAX / 10) continue;
            ans.push_back({y, x, distances[y][x]});
        }
    }
    return ans;


}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> board(h, vector<char>(w));
    rep(y, h)rep(x, w) cin >> board[y][x];

    auto to_id = [&](int y, int x) {
        return y * w + x;
    };

    atcoder::mcf_graph<ll, ll> flow(h * w * 2 + 2);
    const ll MAX = 100000;
    auto connect = [&](int from, int to, int point) {
//        printf("%d %d %d\n", from, to, point);
        flow.add_edge(from, to, 1, point);
    };

    rep(y, h) {
        rep(x, w) {
            if (board[y][x] != 'o') continue;
            vector<Goal> goals = calc_distance(y, x, h, w, board);

            for (Goal g : goals) {
                connect(to_id(y, x), to_id(g.y, g.x) + h * w, MAX - g.point);
            }

        }
    }
    int start = h * w * 2;
    int goal = h * w * 2 + 1;
    rep(y, h) {
        rep(x, w) {
            if (board[y][x] == 'o') {
                connect(start, to_id(y, x), 0);
            }
        }
    }
    rep(y, h) {
        rep(x, w) {
            if (board[y][x] != 'x') {
                connect(to_id(y, x) + h * w, goal, 0);
            }
        }
    }

    int ball_count = 0;
    rep(y, h) {
        rep(x, w) {
            if (board[y][x] == 'o') {
                ball_count++;
            }
        }
    }

    auto ans = flow.flow(start, goal, ball_count);
//    cout << ans.second << endl;
    cout << -ans.second + (MAX * ans.first) << endl;


}
