#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Point {
    int y, x;
};

Point get_start(vector<vector<char>> &grid, int h, int w) {
    rep(y, h) rep (x, w) if (grid[y][x] == 'S') return Point{y, x};
    __throw_runtime_error("konai");
}


Point get_goal(vector<vector<char>> &grid, int h, int w) {
    rep(y, h) rep (x, w) if (grid[y][x] == 'G') return Point{y, x};
    __throw_runtime_error("konai");
}


class WarchallFloyd {

    int n;
    vector<vector<ll>> distances;

public:
    WarchallFloyd(int n) : n(n), distances(n, vector<ll>(n, INF)) {
        rep(i, n) distances[i][i] = 0;
    };

    void warshall_floyd() {
        for (int k = 0; k < n; k++) {       // 経由する頂点
            for (int i = 0; i < n; i++) {    // 始点
                for (int j = 0; j < n; j++) {  // 終点
                    if (distances[i][j] == INF && (distances[i][k] == INF || distances[k][j] == INF)) {
                        distances[i][j] = INF;
                    } else {
                        distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                    }
                }
            }
        }
    }

    ll distance(int from, int to) {
        return distances[from][to];
    }

    void add(int from, int to, ll cost) {
        distances[from][to] = cost;
//        distances[to][from] = cost;
    }

    friend std::istream &operator>>(std::istream &in, WarchallFloyd &o) {
        int from, to;
        ll c;
        cin >> from >> to >> c;
        from--;
        to--;

        o.distances[from][to] = c;
        o.distances[to][from] = c;
        return in;
    }


};


bool check(vector<vector<char>> &grid, ll mid, int h, int w, Point start, Point goal, ll t) {
    struct Direction {
        int x, y;
    };

    vector<Direction> directions = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0},
    };


    auto reachable = [&](int x, int y) {
        if (x == -1 || x == w || y == -1 || y == h) return false;
        return true;
    };

    auto to_id = [&](int y, int x) {
        return y * w + x;
    };

    WarchallFloyd wf(h * w);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            for (Direction d : directions) {
                int nx = x + d.x;
                int ny = y + d.y;
                if (!reachable(nx, ny))continue;
                char next = grid[ny][nx];
                if (next == '#') {
                    wf.add(to_id(y, x), to_id(ny, nx), mid);
                } else {
                    wf.add(to_id(y, x), to_id(ny, nx), 1);
                }
            }
        }
    }

    wf.warshall_floyd();

    return wf.distance(to_id(start.y, start.x), to_id(goal.y, goal.x)) <= t;
}

int main() {
    int h, w;
    ll t;
    cin >> h >> w >> t;
    vector<vector<char>> grid(h, vector<char>(w));
    rep(y, h) rep (x, w) cin >> grid[y][x];

    Point start = get_start(grid, h, w);
    Point goal = get_goal(grid, h, w);

    ll floor = 0, ceil = INF;
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool b = check(grid, mid, h, w, start, goal, t);
        if (b) {
            floor = mid;
        } else {
            ceil = mid;
        }
    }
    cout << floor << endl;
}

