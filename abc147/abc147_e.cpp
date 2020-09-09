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

    vector<vector<unordered_set<int>>> dp(h, vector<unordered_set<int>>(w));
    dp[0][0].insert(red[0][0] - blue[0][0]);
    dp[0][0].insert(blue[0][0] - red[0][0]);

    rep(y, h) {
        rep(x, w) {
            // 上から
            int k = red[y][x] - blue[y][x];

            if (y != 0) {
                for (int p : dp[y - 1][x]) {
                    dp[y][x].insert(p + k);
                    dp[y][x].insert(p - k);
                }
            }

            if (x != 0) {
                for (int p : dp[y][x - 1]) {
                    dp[y][x].insert(p + k);
                    dp[y][x].insert(p - k);
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int l : dp[h - 1][w - 1]) cmin(ans, abs(l));
    cout << ans << endl;

}
