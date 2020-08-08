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
    int h, w;
    cin >> h >> w;

    vector<vector<char >> board(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> board[y][x];

    vector<vector<int>> dp_right(h, vector<int>(w, 0));
    vector<vector<int>> dp_up(h, vector<int>(w, 0));
    vector<vector<int>> dp_left(h, vector<int>(w, 0));
    vector<vector<int>> dp_down(h, vector<int>(w, 0));

    for (int y = h - 1; y >= 0; y--) {
        rep(x, w) {
            if (board[y][x] == '#')continue;
            if (y + 1 == h || board[y + 1][x] == '#') continue;
            dp_down[y][x] = dp_down[y + 1][x] + 1;
        }
    }

    for (int x = w - 1; x >= 0; x--) {
        rep(y, h) {
            if (board[y][x] == '#') continue;
            if (x + 1 == w || board[y][x + 1] == '#') continue;
            dp_right[y][x] = dp_right[y][x + 1] + 1;
        }
    }

    rep(y, h) {
        rep(x, w) {
            if (board[y][x] == '#')continue;
            if (y == 0 || board[y - 1][x] == '#') continue;
            dp_up[y][x] = dp_up[y - 1][x] + 1;
        }
    }

    rep(x, w) {
        rep(y, h) {
            if (board[y][x] == '#') continue;
            if (x == 0 || board[y][x - 1] == '#') continue;
            dp_left[y][x] = dp_left[y][x - 1] + 1;
        }

    }

    ll ans = 0;
    rep(y, h) rep(x, w) {
            if (board[y][x] == '#') continue;
            ll u = dp_up[y][x];
            ll d = dp_down[y][x];
            ll r = dp_right[y][x];
            ll l = dp_left[y][x];

// up -> right
            ll ur = d * r;

// right -> down
            ll rd = l * d;

// down-> left;
            ll dl = u * l;

// left -> up
            ll lu = r * u;

            ll now = ur + rd + dl + lu;

            ans +=
                    now;


        }

    cout << ans <<
         endl;

}
