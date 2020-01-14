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

int nextNum(int j) {
    return __builtin_popcount(j) + 1;
}

bool hasDefault(vector<vector<int>> &ini, int i) {
    int y = i / 5;
    int x = i % 5;
    return ini[y][x] != 0;
}

int getDefault(vector<vector<int>> &ini, int i) {
    int y = i / 5;
    int x = i % 5;
    return ini[y][x];
}

bool check(int i, int j) {
    int y = j / 5;
    int x = j % 5;

    if (y == 0 || y == 5 - 1) return true;
    if (x == 0 || x == 5 - 1) return true;
    bool up = (i >> ((y - 1) * 5 + x)) & 1;
    bool down = (i >> ((y + 1) * 5 + x)) & 1;
    bool left = (i >> (y * 5 + x - 1)) & 1;
    bool right = (i >> (y * 5 + x + 1)) & 1;

    if (up != down) return false;
    if (left != right) return false;

    return true;
}

int f(vector<vector<int>> &ini, int i, int j) {

    int next_num = nextNum(j);
    if (hasDefault(ini, j)) {
        if (getDefault(ini, j) == next_num) {
            return 1;
        } else {
            return 0;
        }
    }
    if (check(i, j)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    vector<vector<int>> ini(5, vector<int>(5));

    rep(y, 5)rep(x, 5) cin >> ini[y][x];
    rep(y, 5)rep(x, 5) ini[y][x]--;

    vector<int> dp(1 << 25, 0);
    dp[0] = 1;
    rep(i, 1 << 25) {
        if (i == 0) continue;
        rep(j, 25) {
            if (((i >> j) & 1) == 0) continue;
            int before = i - (1 << j);
            int next = dp[before] * f(ini, before, j);
            dp[i] += next;
        }
    }

    cout << dp[(1 << 25) - 1] << endl;
}
