#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> grid[y][x];

    int sx, sy, gx, gy;
    rep(y, h) rep(x, w) if (grid[y][x] == 's') {
                sx = x;
                sy = y;
            }
    rep(y, h) rep(x, w) if (grid[y][x] == 'g') {
                gx = x;
                gy = y;
            }


    struct Task {
        int x, y, cost;
    };

    queue<Task> q;
    q.push({sx, sy, 0});

    vector<vector<ll>> costs(h, vector<ll>(w, INF));

    struct Direction {
        int x, y;
    };

    vector<Direction> directions = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0},
    };


    while (!q.empty()) {
        Task t = q.front();
        q.pop();

        for (Direction d : directions) {
            int x = t.x + d.x;
            int y = t.y + d.y;
            if (x == -1 || x == w || y == -1 || y == h) continue;
            int cost = grid[y][x] == '#' ? t.cost + 1 : t.cost;
            if (costs[y][x] <= cost) continue;
            if (cost >= 3) continue;
            costs[y][x] = cost;
            q.push({x, y, cost});
        }
    }

    if (costs[gy][gx] <= 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}
