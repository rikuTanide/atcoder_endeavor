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

    set<int> empty_row = [&] {
        set<int> ans;
        rep(y, h) {
            bool ok = [&] {
                rep(x, w) {
                    if (grid[y][x] == '#') return false;
                }
                return true;
            }();
            if (ok) ans.insert(y);
        }
        return ans;
    }();

    vector<vector<char>> grid2;
    rep(y, h) if (!contain(empty_row, y)) grid2.push_back(grid[y]);

    h = grid2.size();

    set<int> empty_column = [&] {
        set<int> ans;
        rep(x, w) {
            bool ok = [&] {
                rep(y, h) {
                    if (grid2[y][x] == '#') return false;
                }
                return true;
            }();
            if (ok) ans.insert(x);
        }
        return ans;
    }();

    vector<vector<char>> grid3(h);
    rep(y, h) {
        rep(x, w) {
            if (contain(empty_column, x)) continue;
            grid3[y].push_back(grid2[y][x]);
        }
    }

    w = grid3[0].size();
    rep(y, h) {
        rep(x, w) cout << grid3[y][x];
        cout << endl;
    }

}
