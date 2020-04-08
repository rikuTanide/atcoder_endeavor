#define _GLIBCXX_DEBUG

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
    rep(i, h) rep(j, w) cin >> grid[i][j];

    vector<vector<int>> dp(h, vector<int>(w, INT_MAX / 100));
    dp[0][0] = grid[0][0] == '#' ? 1 : 0;

    auto set = [&](int y, int x, int value) {
        cmin(dp[y][x], value);
    };

    rep(y, h) {
        rep(x, w) {
            if (y != 0) {
                if (grid[y][x] == '.') set(y, x, dp[y - 1][x]);
                else if (grid[y - 1][x] == '#')set(y, x, dp[y - 1][x]);
                else if (grid[y - 1][x] == '.' && grid[y][x] == '#') set(y, x, dp[y - 1][x] + 1);
                else __throw_runtime_error("konai");
            }
            if (x != 0) {
                if (grid[y][x] == '.') set(y, x, dp[y][x - 1]);
                else if (grid[y][x - 1] == '#')set(y, x, dp[y][x - 1]);
                else if (grid[y][x - 1] == '.' && grid[y][x] == '#') set(y, x, dp[y][x - 1] + 1);
                else __throw_runtime_error("konai");
            }
        }
    }

    cout << dp.back().back() << endl;
}
