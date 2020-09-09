#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> red(h, vector<int>(w));
    vector<vector<int>> blue(h, vector<int>(w));

    rep(y, h)rep(x, w)cin >> red[y][x];
    rep(y, h)rep(x, w)cin >> blue[y][x];

    const int MAX = (80 + 80) * 80;

    vector<vector<vector<bool>>> dp(h, vector<vector<bool>>(w, vector<bool>(MAX, false)));
    dp[0][0][abs(red[0][0] - blue[0][0])] = true;

    rep(y, h) {
        rep(x, w) {
            // 上から
            int k = red[y][x] - blue[y][x];

            if (y != 0) {
                rep(p, MAX) {
                    if (!dp[y - 1][x][p]) continue;
                    dp[y][x][abs(p + k)] = true;
                    dp[y][x][abs(p - k)] = true;
                }
            }

            if (x != 0) {
                rep(p, MAX) {
                    if (!dp[y][x - 1][p]) continue;
                    dp[y][x][abs(p + k)] = true;
                    dp[y][x][abs(p - k)] = true;
                }
            }
        }
    }

    int ans = INT_MAX;
    rep(i, MAX) if (dp[h - 1][w - 1][i]) cmin(ans, i);
    cout << ans << endl;

}
