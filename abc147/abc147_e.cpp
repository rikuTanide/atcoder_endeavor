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

    vector<vector<int>> grid_a(h, vector<int>(w)), grid_b(h, vector<int>(w));
    rep(y, h) rep(x, w) cin >> grid_a[y][x];
    rep(y, h) rep(x, w) cin >> grid_b[y][x];

    vector<vector<set<int>>> dp(h, vector<set<int>>(w));
    dp[0][0].insert(abs(grid_a[0][0] - grid_b[0][0]));

    auto get = [&](int y, int x) {
        set<int> s;

        if (y == 0 && x == 0) {
            s.insert(0);
            return s;
        }
        if (y > 0) s.insert(dp[y - 1][x].begin(), dp[y - 1][x].end());
        if (x > 0) s.insert(dp[y][x - 1].begin(), dp[y][x - 1].end());

        return s;
    };

    rep(y, h) rep(x, w) {
            int sub = abs(grid_a[y][x] - grid_b[y][x]);

            for (int next : get(y, x)) {
                dp[y][x].insert(next + sub);
                dp[y][x].insert(abs(next - sub));
            }

        }

    int ans = *dp.back().back().begin();
    cout << ans << endl;
}