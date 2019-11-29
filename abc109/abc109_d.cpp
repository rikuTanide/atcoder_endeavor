#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\01.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;

int gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> board(w, vector<int>(h, -1));

    rep(y, h) rep(x, w) cin >> board[x][y];

    vector<vector<int>> ans;

    int x = 0, y = 0;
    for (int i = 0; i < (h * w) - 1; i++) {

        int next_x;
        int next_y;

        if (i % w == (w - 1)) {
            // 下
            next_x = x;
            next_y = y + 1;
        } else if (i / w % 2 == 0) {
            // 右
            next_x = x + 1;
            next_y = y;
        } else {
            // 左
            next_x = x - 1;
            next_y = y;
        }
//        printf("(%d, %d) (%d, %d)\n", x, y, next_x, next_y);

        if (board[x][y] % 2 == 1) {
            board[next_x][next_y]++;
            vector<int> now = {x + 1, y + 1, next_x + 1, next_y + 1};
            ans.push_back(now);
        }

        x = next_x;
        y = next_y;

    }
    cout << ans.size() << endl;
    for (auto a : ans) {
        printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
    }

}
