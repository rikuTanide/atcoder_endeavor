#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

typedef pair<int, int> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

P calc(vector<int> &board, vector<vector<int>> &bs, vector<vector<int>> &cs) {
    assert(count(board.begin(), board.end(), 0) == 0);

    P ans = {0, 0};

    auto to_id = [](int y, int x) { return y * 3 + x; };
    rep(y, 2) rep(x, 3) {
            if (board[to_id(y, x)] == board[to_id(y + 1, x)]) ans.first += bs[y][x];
            else ans.second += bs[y][x];
        }
    rep(y, 3) rep(x, 2) {
            if (board[to_id(y, x)] == board[to_id(y, x + 1)]) ans.first += cs[y][x];
            else ans.second += cs[y][x];
        }
    return ans;
}

P recursive(map<vector<int>, P> &dp, vector<int> &board, int i, vector<vector<int>> &bs, vector<vector<int>> &cs) {

    if (dp.find(board) != dp.end()) return dp[board];

    if (i == 9) {
        return calc(board, bs, cs);
    }

    P ans = {-1, -1};
    vector<int> ans_board;
    rep(t, 9) {
        if (board[t] != 0) continue;
        board[t] = i % 2 == 0 ? 1 : -1;
        P p = recursive(dp, board, i + 1, bs, cs);
        int prev = i % 2 == 0 ? ans.first : ans.second;
        int now = i % 2 == 0 ? p.first : p.second;
        if (prev < now) {
            ans = p;
            ans_board = board;
        }
        board[t] = 0;

    }

    assert(ans.first >= 0);
    assert(ans.second >= 0);
    dp[ans_board] = ans;
    return ans;
}

int main() {

    vector<vector<int>> bs(2, vector<int>(3));
    vector<vector<int>> cs(3, vector<int>(2));
    rep(y, 2) rep(x, 3) cin >> bs[y][x];
    rep(y, 3) rep(x, 2) cin >> cs[y][x];

    map<vector<int>, P> dp;
    vector<int> board(9, 0);
    P ans = recursive(dp, board, 0, bs, cs);
    cout << ans.first << endl << ans.second << endl;
}
