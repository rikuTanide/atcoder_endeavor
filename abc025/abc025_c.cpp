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

typedef vector<vector<int>> Board;
typedef map<Board, P> Memo;

P points(Board &board, Board &b, Board &c) {
    ll m = 0;
    ll n = 0;
    rep(y, 2) rep(x, 3) {
            if (board[y][x] == board[y + 1][x]) {
                m += b[y][x];
            } else {
                n += b[y][x];;
            }
        }
    rep(y, 3) rep(x, 2) {
            if (board[y][x] == board[y][x + 1]) {
                m += c[y][x];
            } else {
                n += c[y][x];;
            }
        }
    return P(m, n);
}

P solve(Board &board, Memo &memo, int i, Board &b, Board &c) {
    if (memo.find(board) != memo.end()) return memo[board];
    if (i == 9) return points(board, b, c);

    P ma = P(0, 0);
    rep(y, 3) rep(x, 3) {
            if (board[y][x] != 0) continue;
            Board next = board;
            next[y][x] = (i % 2 == 0 ? 1 : -1);
            P now = solve(next, memo, i + 1, b, c);

            if (i % 2 == 0) {
                if (ma.first < now.first) ma = now;
            } else {
                if (ma.second < now.second) ma = now;
            }
        }

    memo[board] = ma;
    return ma;
}

int main() {

    Board b(2, vector<int>(3));
    Board c(3, vector<int>(2));

    rep(y, 2) rep(x, 3) cin >> b[y][x];
    rep(y, 3) rep(x, 2) cin >> c[y][x];

    Memo memo;

    Board board(3, vector<int>(3, 0));
    P ans = solve(board, memo, 0, b, c);
    printf("%lld\n%lld\n", ans.first, ans.second);

}
