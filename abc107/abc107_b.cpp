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

int main() {

    int h, w;
    cin >> h >> w;


    vector<vector<char>> board(h, vector<char>(w));
    rep(y, h)
        rep(x, w) {
            cin >> board[y][x];
        }

    set<int> delete_x;
    set<int> delete_y;

    rep(y, h) {
        bool white = [&] {
            rep(x, w) {
                if (board[y][x] == '#') {
                    return false;
                }
            }
            return true;
        }();
        if (white) {
            delete_y.insert(y);
        }
    }

    rep(x, w) {
        bool white = [&] {
            rep(y, h) {
                if (board[y][x] == '#') {
                    return false;
                }
            }
            return true;
        }();
        if (white) {
            delete_x.insert(x);
        }
    }


    rep(y, h) {
        if (delete_y.find(y) != delete_y.end()) continue;
        rep(x, w) {
            if (delete_x.find(x) != delete_x.end()) continue;
            cout << board[y][x] << ' ';
        }
        cout << endl;
    }

}
