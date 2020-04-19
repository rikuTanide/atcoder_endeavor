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


int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> grid[y][x];

    vector<vector<vector<int>>> dp(2, vector<vector<int>>(h, vector<int>(w, -1)));


    struct Direction {
        int x, y;
    };

    vector<Direction> directions = {
            {0, 1},
            {1, 0},
            {1, 1},
    };


    auto reachable = [&](int x, int y) {
        if (x == -1 || x == w || y == -1 || y == h) return false;
        if (grid[y][x] == '#') {
            return false;
        }
        return true;
    };

    auto turn = [](int t) {
        return (t + 1) % 2;
    };

    auto check = [&](int t, int y, int x) {
        auto dpi = dp[turn(t)];

        for (Direction d : directions) {
            int ny = y + d.y;
            int nx = x + d.x;
            if (!reachable(nx, ny)) continue;
            if (dpi[ny][nx] == t) return t;
        }
        return turn(t);

    };

    for (int y = h - 1; y >= 0; y--) {
        for (int x = w - 1; x >= 0; x--) {
            for (int t : {0, 1}) {
                dp[t][y][x] = check(t, y, x);
            }
        }
    }

    cout << (dp[0][0][0] == 0 ? "First" : "Second") << endl;

}

