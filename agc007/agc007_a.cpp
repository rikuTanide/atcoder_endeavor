#include <bits/stdc++.h>
#include <cmath>

//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
typedef pair<int, int> P;
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;

bool contain(set<string> &s, string a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;


int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> board(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> board[y][x];

    auto can = [&](int y, int x) {
        if (y == h) return false;
        if (x == w) return false;
        if (board[y][x] == '.') return false;
        return true;
    };
    auto set = [&](int y, int x) {
        if (!can(y, x)) return;
        board[y][x] = 'o';
    };

    board[0][0] = 'o';
    rep(y, h)rep(x, w) {
            if (board[y][x] == 'o') {
                if (can(y + 1, x)) {
                    set(y + 1, x);
                } else if (can(y, x + 1)) {
                    set(y, x + 1);
                }
            }
        }


    rep(y, h)rep(x, w) {
            if (board[y][x] == '#') {
                cout << "Impossible" << endl;
                return 0;
            }
        }

    cout << (board.back().back() == 'o' ? "Possible" : "Impossible") << endl;
}


