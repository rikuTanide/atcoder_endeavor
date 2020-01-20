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

class BoardSum {
    vector<vector<int>> board_sum;
    int r, c;
public:
    BoardSum(vector<vector<char>> &board, int r, int c) : board_sum(r, vector<int>(c)), r(r), c(c) {
        rep(y, r) rep(x, c) {
                if (x == 0) {
                    if (board[y][x] == 'o') {
                        board_sum[y][x] = 1;
                    } else {
                        board_sum[y][x] = 0;
                    }
                } else {
                    if (board[y][x] == 'o') {
                        board_sum[y][x] = board_sum[y][x - 1] + 1;
                    } else {
                        board_sum[y][x] = 0;
                    }
                }
            }
    };

    int get(int y, int x) {
        if (y < 0) return -1;
        if (y >= r) return -1;
        if (x < 0) return -1;
        if (x >= c) return -1;
        return board_sum[y][x];
    }

};

bool check(BoardSum &boardSum, int y, int x, int k, int r, int c) {

    for (int yz = -k + 1; yz < k; yz++) {
        int yp = y + yz;
        if (yp < 0) return false;
        if (yp >= r) return false;

        int max_c = 2 * k - 1;
        int dis = abs(yz);
        int p_c = max_c - dis * 2;
        int rt = x + p_c / 2;
        int a = boardSum.get(yp, rt);
        if (a == -1) return false;
        if (a < p_c) return false;

    }

    return true;
}

int main() {
    int r, c, k;
    cin >> r >> c >> k;

    vector<vector<char>> board(r, vector<char>(c, ' '));

    rep(y, r) rep(x, c)cin >> board[y][x];

    BoardSum boardSum(board, r, c);


    int ans = 0;
    rep(y, r) rep(x, c) {
            if (check(boardSum, y, x, k, r, c)) {
                ans++;
            }
        }
    cout << ans << endl;
}

