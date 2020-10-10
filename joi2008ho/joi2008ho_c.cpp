#include <bits/stdc++.h>
//#include "atcoder/all"
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

ll solve(int n, ll m, vector<ll> &points) {
    vector<set<ll>> dp(5, set<ll>());
    dp[0].insert(0);

    rep(i, 4) {
        for (ll p : dp[i]) {
            for (ll q : points) {
                if (p + q <= m)dp[i + 1].insert(p + q);
            }
        }
    }

    ll ans = 0;
    rep(i, 5) for (ll v : dp[i]) cmax(ans, v);

    return ans;

}

int main() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> points(n);
    rep(i, n) cin >> points[i];

    ll ans = solve(n, m, points);
    cout << ans << endl;

}