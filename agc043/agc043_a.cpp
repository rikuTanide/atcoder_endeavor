#include <bits/stdc++.h>
#include <cmath>

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

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> board(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> board[y][x];

    vector<vector<int>> dp(h, vector<int>(w, INT_MAX / 10));
    if (board.front().front() == '.') dp[0][0] = 0;
    else dp[0][0] = 1;

    struct Direction {
        int x, y;
    };

    vector<Direction> directions = {
            {0, 1},
            {1, 0},
    };

    auto set = [&](int y, int x, int value) {
        cmin(dp[y][x], value);
    };

    rep(y, h) {
        rep(x, w) {
            for (Direction d : directions) {
                int ny = y + d.y;
                int nx = x + d.x;
                if (ny == h || nx == w) continue;

                if (board[ny][nx] == '.') set(ny, nx, dp[y][x]);
                else if (board[y][x] == '#') set(ny, nx, dp[y][x]);
                else if (board[y][x] == '.' && board[ny][nx] == '#') set(ny, nx, dp[y][x] + 1);
                else __throw_runtime_error("konaide");
            }
        }
    }

    cout << dp.back().back() << endl;

}


