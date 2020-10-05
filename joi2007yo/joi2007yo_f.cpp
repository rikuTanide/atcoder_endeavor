#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

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
    int w, h;
    cin >> w >> h;

    vector<vector<ll>> dp(h, vector<ll>(w, 0));
    dp[0][0] = 1;
    auto add = [&](int y, int x, ll v) {
        if (y >= h) return;
        if (x >= w) return;
        if (dp[y][x] == -1) return;
        dp[y][x] += v;
    };

    int n;
    cin >> n;
    rep(_, n) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        dp[y][x] = -1;
    }
    rep(y, h) {
        rep(x, w) {
            if (dp[y][x] == -1) continue;
            ll now = dp[y][x];
            add(y + 1, x, now);
            add(y, x + 1, now);
        }
    }

    cout << dp.back().back() << endl;


}
