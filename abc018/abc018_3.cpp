#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

class Board {
    vector<vector<char>> board;
public:
    Board(vector<vector<char>> &board) : board(board) {}

    char get(int y, int x) {
        return board[y][x];
    }

};

bool check(Board &board, int y, int x, int k, int r, int c) {

    for (int yk = 0; yk < 2 * k - 1; yk++) {
        for (int xk = 0; xk < 2 * k - 1; xk++) {
            int zy = -k + 1 + yk;
            int zx = -k + 1 + xk;

            int py = y + zy;
            int px = x + zx;

            if (py < 0) return false;
            if (py >= r) return false;
            if (px < 0) return false;
            if (px >= c) return false;

            int absx = abs(zx);
            int absy = abs(zy);
            if (absx + absy > k - 1) {
                continue;
            }

            if (board.get(py, px) == 'x') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int r, c, k;
    cin >> r >> c >> k;

    vector<vector<char>> board(r, vector<char>(c, ' '));

    rep(y, r) rep(x, c)cin >> board[y][x];

    Board b(board);

    int ans = 0;
    rep(y, r) rep(x, c) {
            if (check(b, y, x, k, r, c)) {
                ans++;
            }
        }
    cout << ans << endl;
}

