#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

// 全く分からんから写経した。
// https://atcoder.jp/contests/abc025/submissions/7453266

struct Point {
    int y, x;
};

int dr[] = {1, 0, -1, 0}, dc[] = {0, -1, 0, 1};

bool out(int r, int c) {
    return r < 0 || r >= 5 || c < 0 || c >= 5;
}


bool check(int r, int c, int i) {
    int nr, nc;
    for (int d = 0; d < 4; d++) {
        nr = r + dr[d], nc = c + dc[d];
        if (out(nr, nc) || ((i & (1 << (nr * 5 + nc))) == 0)) continue;
        nr = r - dr[d], nc = c - dc[d];
        if (out(nr, nc) || (i & (1 << (nr * 5 + nc)))) continue;
        return false;
    }
    return true;
}

int main() {
    map<int, Point> ini;

    rep(y, 5)
        rep(x, 5) {
            int a;
            cin >> a;
            ini[a] = {y, x};
        }

    int n = 1 << 25;
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (dp[i] == 0) continue;
        int next = __builtin_popcount(i) + 1;
        if (ini.find(next) != ini.end()) {
            Point np = ini[next];
            int j = np.y * 5 + np.x;
            bool b = (i & (1 << j)) == 0;
            if (b) {
                if (check(np.y, np.x, i)) {
                    dp[i | (1 << j)] += dp[i];
                    dp[i | (1 << j)] %= mod;
                }
            }
            continue;
        }
        for (int j = 0; j < 25; j++) {
            if (i & (1 << j)) continue;
            int r = j / 5;
            int c = j % 5;
            if (check(r, c, i)) {
                dp[i | (1 << j)] += dp[i];
                dp[i | (1 << j)] %= mod;

            }
        }
    }
    cout << dp[n - 1] << endl;
}
