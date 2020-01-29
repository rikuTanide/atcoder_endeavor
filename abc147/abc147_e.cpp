#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

int main() {

    int h, w;
    cin >> h >> w;

    vector<vector<int>> as(h, vector<int>(w, 0));
    vector<vector<int>> bs(h, vector<int>(w, 0));

    rep(y, h)rep(x, w) cin >> as[y][x];
    rep(y, h)rep(x, w) cin >> bs[y][x];

    vector<vector<vector<bool>>> dp(h, vector<vector<bool>>(w, vector<bool>(12801, false)));
    dp[0][0][abs(as[0][0] - bs[0][0])] = true;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (x == 0 && y == 0) continue;
            if (x != 0) {
                for (int i = 0; i <= 12800; i++) {
                    if (!dp[y][x - 1][i]) {
                        continue;
                    }
                    int next_1 = i + abs(as[y][x] - bs[y][x]);
                    int next_2 = abs(i - abs(as[y][x] - bs[y][x]));
                    dp[y][x][next_1] = true;
                    dp[y][x][next_2] = true;
                }
            }

            if (y != 0) {
                for (int i = 0; i <= 12800; i++) {
                    if (!dp[y - 1][x][i]) {
                        continue;
                    }
                    int next_1 = i + abs(as[y][x] - bs[y][x]);
                    int next_2 = abs(i - abs(as[y][x] - bs[y][x]));
                    dp[y][x][next_1] = true;
                    dp[y][x][next_2] = true;
                }
            }


        }
    }

    for (int i = 0; i < 12800; i++) {
        if (dp[h - 1][w - 1][i]) {
            cout << i << endl;
            return 0;
        }
    }

}