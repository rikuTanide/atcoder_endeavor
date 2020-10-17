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
    int n;
    cin >> n;
    vector<int> v(n + 1);
    rep(i, n) if (i != 0) cin >> v[i];

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX / 100000));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        rep(j, i) {
            rep(k, n) {
                int size = i - j;
                cmin(dp[i][abs(k - size)], dp[j][k] + v[i]);
            }
        }
    }

    cout << dp.back()[0] << endl;
}
