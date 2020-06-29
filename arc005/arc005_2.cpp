#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {
    int sx, sy;
    string d;
    cin >> sx >> sy >> d;

    sy--;
    sx--;

    int horizontal = [&] {
        if (d == "R" || d == "RU" || d == "RD") return 1;
        if (d == "L" || d == "LU" || d == "LD") return -1;
        return 0;
    }();

    int vertical = [&] {
        if (d == "U" || d == "RU" || d == "LU") return -1;
        if (d == "D" || d == "RD" || d == "LD") return 1;
        return 0;
    }();

    vector<vector<char>> board(9, vector<char>(9));
    rep(y, 9) rep(x, 9) cin >> board[y][x];

    rep(i, 4) {
        cout << board[sy][sx];

        if (sy + vertical >= 9 || sy + vertical < 0) vertical = -vertical;
        if (sx + horizontal >= 9 || sx + horizontal < 0) horizontal = -horizontal;
        sy += vertical;
        sx += horizontal;
    }
    cout << endl;

}
