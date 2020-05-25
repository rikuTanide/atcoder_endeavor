#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

P get_start(vector<vector<char>> &grid, int h, int w) {
    rep(y, h) rep(x, w) if (grid[y][x] == 's') return P(y, x);
    __throw_runtime_error("nai");
}

P get_goal(vector<vector<char>> &grid, int h, int w) {
    rep(y, h) rep(x, w) if (grid[y][x] == 'g') return P(y, x);
    __throw_runtime_error("nai");
}

struct Task {
    int y, x, time;
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

bool reachable(int y, int x, vector<vector<char>> &grid, vector<vector<int>> &distances, int h, int w, double border,
               int time, vector<double> &pw) {
    if (x == -1 || x == w || y == -1 || y == h) return false;
    if (grid[y][x] == '#') {
        return false;
    }
    if (grid[y][x] == 's') {
        return false;
    }
    if (grid[y][x] == 'g') {
        return true;
    }
    if (distances[y][x] <= time) return false;

    double bright = grid[y][x] - '0';
    double n_bright = bright * pw[time];
    if (n_bright < border) return false;
    return true;
};

bool check(double border, vector<vector<char>> &grid, int h, int w, P start, P goal, vector<double> &pw) {
    queue<Task> q;
    q.push(Task{(int) start.first, (int) start.second, 0});

    vector<vector<int>> distances(h, vector<int>(w, INT_MAX));

    while (!q.empty()) {
        Task t = q.front();
        q.pop();

        for (Direction d : directions) {
            int ny = t.y + d.y;
            int nx = t.x + d.x;
            int nt = t.time + 1;

            if (!reachable(ny, nx, grid, distances, h, w, border, nt, pw)) continue;

            if (P(ny, nx) == goal) {
                return true;
            }
            distances[ny][nx] = nt;
            q.push(Task{ny, nx, nt});
        }
    }
    return false;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> grid[y][x];

    vector<double> pw(h * w);
    rep(i, h * w) pw[i] = pow(0.99, i);

    double floor = 0, ceil = INF;

    P start = get_start(grid, h, w), goal = get_goal(grid, h, w);

    if (!check(0, grid, h, w, start, goal, pw)) {
        cout << -1 << endl;
        ret();
    }

    rep(_, 1000) {
        double mid = (floor + ceil) / 2;
        bool ok = check(mid, grid, h, w, start, goal, pw);
        if (!ok) ceil = mid;
        else floor = mid;
    }
    printf("%.20f\n", floor);

}
