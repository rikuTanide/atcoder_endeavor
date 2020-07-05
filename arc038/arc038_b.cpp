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
    vector<vector<char>> grid(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> grid[y][x];

    vector<vector<char>>
            first(h, vector<char>(w, '-')),
            second(h, vector<char>(w, '-'));

    struct Direction {
        int y, x;
    };

    vector<Direction> directions = {
            {0, 1},
            {1, 0},
            {1, 1},
    };


    auto reachable = [&](int y, int x) {
        if (x == -1 || x == w || y == -1 || y == h) return false;
        if (grid[y][x] == '#') {
            return false;
        }
        return true;
    };


    for (int y = h - 1; y >= 0; y--) {
        for (int x = w - 1; x >= 0; x--) {
            if (grid[y][x] == '#') continue;
            rep(turn, 2) {
                bool ok = [&] {
                    for (Direction d : directions) {
                        int ny = y + d.y;
                        int nx = x + d.x;
                        if (!reachable(ny, nx)) continue;
                        char c = turn == 0 ? second[ny][nx] : first[ny][nx];
                        assert(c != '-');
                        bool ok = c == 'x';
                        if (ok) return true;
                    }
                    return false;
                }();

                if (turn == 0) first[y][x] = (ok ? 'o' : 'x');
                else second[y][x] = (ok ? 'o' : 'x');
            }
        }
    }

    cout << (first[0][0] == 'o' ? "First" : "Second") << endl;

}
