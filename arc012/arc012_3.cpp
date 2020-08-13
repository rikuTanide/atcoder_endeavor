#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

bool check(vector<vector<char>> &board) {


    struct Direction {
        int y, x;
    };


    vector<Direction> directions = {
            {0,  -1},
            {-1, 0},
            {-1, -1},
            {1,  -1},
    };

    auto reachable = [&](int y, int x) {
        if (x == -1 || x == 19 || y == -1 || y == 19) return false;
        return true;
    };
    for (Direction d : directions) {
        vector<vector<int>> dp(19, vector<int>(19, 0));
        rep(y, 19) {
            rep(x, 19) {

                int ny = y + d.y;
                int nx = x + d.x;
                if (!reachable(ny, nx)) continue;
                if (board[y][x] == '.' && board[ny][nx] != '.') {
                    cmax(dp[ny][nx], 1);
                } else if (board[y][x] != '.' && board[ny][nx] == board[y][x]) {
                    cmax(dp[ny][nx], dp[y][x] + 1);
                }
            }
        }

        int ma = 0;
        rep(y, 19) rep(x, 19) {
                cmax(ma, dp[y][x]);
            }
        if (ma >= 5) return false;
    }
    return true;
}

bool turn_check(int y, int x, vector<vector<char>> &board) {
    char c = board[y][x];
    board[y][x] = '.';
    bool b = check(board);
    board[y][x] = c;
    return b;
}

bool solve() {
    vector<vector<char>> board(19, vector<char>(19));
    rep(y, 19) rep(x, 19) cin >> board[y][x];

    auto c_count = [&](char c) -> int {
        int ans = 0;
        rep(y, 19)rep(x, 19) if (board[y][x] == c) ans++;
        return ans;
    };

    int black_count = c_count('o');
    int white_count = c_count('x');

    if (black_count == white_count) {
        if (check(board)) return true;
        rep(y, 19) rep(x, 19) if (board[y][x] == 'x' && turn_check(y, x, board)) return true;
        return false;
    }
    if (black_count == white_count + 1) {
        if (check(board)) return true;
        rep(y, 19) rep(x, 19) if (board[y][x] == 'o' && turn_check(y, x, board)) return true;
        return false;
    }
    return false;
}

int main() {
    bool b = solve();
    cout << (b ? "YES" : "NO") << endl;
}
