#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;


int main() {
    int n;
    cin >> n;


    vector<vector<int>> board(2, vector<int>(n));
    rep(y, 2) rep(x, n) {
            cin >> board[y][x];
        }

    vector<int> sum_1(n + 1, 0);
    for (int i = 0; i < n; i++) {
        sum_1[i + 1] = sum_1[i] + board[0][i];
    }

    vector<int> sum_2(n + 1, 0);
    for (int i = n; i > 0; i--) {
        sum_2[i - 1] = sum_2[i] + board[1][i - 1];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int now = sum_1[i + 1] + sum_2[i];
        cmax(ans, now);

    }

    cout << ans << endl;
}