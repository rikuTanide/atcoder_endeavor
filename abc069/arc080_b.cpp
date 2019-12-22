#include <bits/stdc++.h>
#include <cmath>

#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

int snakeY(int i, int w) {
    return i / w;
}

int snakeX(int i, int w) {
    int y = snakeY(i, w);
    if (y % 2 == 0) {
        return i % w;
    }
    return (w - 1) - (i % w);
}


int main() {

    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<int>> board(h, vector<int>(w, -1));

    int k = 0;
    rep(i, n) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            board[snakeY(k, w)][snakeX(k, w)] = i + 1;
            k++;
        }
    }

    rep(y, h) {
        rep(x, w) {
            cout << board[y][x] << ' ';
        }
        cout << endl;
    }
}