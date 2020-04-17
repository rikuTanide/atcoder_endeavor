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

    int r, c, k;
    cin >> r >> c >> k;

    vector<vector<char>> board(r, vector<char>(c));
    rep(y, r) rep(x, c) cin >> board[y][x];

    vector<vector<int>> dp1(r, vector<int>(c, 0));
    vector<vector<int>> dp2(r, vector<int>(c, 0));
    vector<vector<int>> dp3(r, vector<int>(c, 0));
    vector<vector<int>> dp4(r, vector<int>(c, 0));

    auto get = [&](vector<vector<int>> &dp, int y, int x) {
        if (y == -1 || y == r || x == -1 || x == c) return 0;
        return dp[y][x];
    };

    // 右上
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (board[y][x] == 'x') continue;
            dp1[y][x] = min(get(dp1, y - 1, x), get(dp1, y, x - 1)) + 1;
        }
    }

    // 左下
    for (int y = r - 1; y >= 0; y--) {
        for (int x = 0; x < c; x++) {
            if (board[y][x] == 'x') continue;
            dp2[y][x] = min(get(dp2, y + 1, x), get(dp2, y, x - 1)) + 1;
        }
    }

    // 右上
    for (int y = 0; y < r; y++) {
        for (int x = c - 1; x >= 0; x--) {
            if (board[y][x] == 'x') continue;
            dp3[y][x] = min(get(dp3, y - 1, x), get(dp3, y, x + 1)) + 1;
        }
    }

    // 右下
    for (int y = r - 1; y >= 0; y--) {
        for (int x = c - 1; x >= 0; x--) {
            if (board[y][x] == 'x') continue;
            dp4[y][x] = min(get(dp4, y + 1, x), get(dp4, y, x + 1)) + 1;
        }
    }
    int ans = 0;
    rep(y, r) rep(x, c) {
            if (dp1[y][x] >= k && dp2[y][x] >= k && dp3[y][x] >= k && dp4[y][x] >= k) ans++;
        }
    cout << ans << endl;
}

