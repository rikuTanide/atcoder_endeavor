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
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

int main() {

    vector<vector<int>> board(3, vector<int>(3));

    rep(y, 3)rep(x, 3) cin >> board[y][x];

    rep(y, 3) {

        set<int> ans;
        rep(x, 3) {
            int a = board[y][x] - board[(y + 1) % 3][x];
            ans.insert(a);
        }
        if (ans.size() != 1) {
            cout << "No" << endl;
            return 0;
        }
    }

    rep(x, 3) {
        set<int> ans;
        rep(y, 3) {
            int a = board[y][x] - board[y][(x + 1) % 3];
            ans.insert(a);
        }
        if (ans.size() != 1) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}