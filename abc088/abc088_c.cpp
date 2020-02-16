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
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;

bool contain(set<ll> &s, ll a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

bool check(int a, int b, int c) {
    return a == b && b == c && c == a;
}

int main() {

    vector<vector<int>> board(3, vector<int>(3));
    rep(i, 3)rep(j, 3) cin >> board[i][j];

    bool a0_a1 = check(board[0][0] - board[0][1], board[1][0] - board[1][1], board[2][0] - board[2][1]);
    bool a1_a2 = check(board[0][1] - board[0][2], board[1][1] - board[1][2], board[2][1] - board[2][2]);
    bool a2_a0 = check(board[0][2] - board[0][0], board[1][2] - board[1][0], board[2][2] - board[2][0]);

    bool b0_b1 = check(board[0][0] - board[1][0], board[0][1] - board[1][1], board[0][2] - board[1][2]);
    bool b1_b2 = check(board[1][0] - board[2][0], board[1][1] - board[2][1], board[1][2] - board[2][2]);
    bool b2_b3 = check(board[2][0] - board[0][0], board[2][1] - board[0][1], board[2][2] - board[0][2]);

    if (a0_a1 &&
        a1_a2 &&
        a2_a0 &&
        b0_b1 &&
        b1_b2 &&
        b2_b3) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

