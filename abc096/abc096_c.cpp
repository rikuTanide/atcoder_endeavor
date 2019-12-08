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
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

ll pow2(ll a, ll b) {
    ll res = a;
    for (ll i = 1; i < b; i++) {
        res *= a;
    }
    return res;
}

int main() {

    int h, w;
    cin >> h >> w;

    vector<vector<char>> board = vector<vector<char>>(h + 2, vector<char>(w + 2, '.'));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> board[y + 1][x + 1];
        }
    }

    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {

            bool b = [&] {

                if (board[y][x] == '.') return true;

                if (board[y - 1][x] == '#') return true;
                if (board[y + 1][x] == '#') return true;
                if (board[y][x - 1] == '#') return true;
                if (board[y][x + 1] == '#') return true;

                return false;

            }();

            if (!b) {

                cout << "No" << endl;
                return 0;
            }

        }
    }

    cout << "Yes" << endl;

}