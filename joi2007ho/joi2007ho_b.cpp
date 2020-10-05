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

int dp_one(int n, int k, vector<int> &v) {
    vector<int> dp(n, 0);
    for (int i : v) dp[i] = 1;
    rep(i, n) {
        if (i == 0) continue;
        if (dp[i] == 0) continue;
        dp[i] += dp[i - 1];
    }
    int ans = *max_element(dp.begin(), dp.end());
    return ans;
}

int dp_two(int n, int k, vector<int> &v) {
    v.erase(find(v.begin(), v.end(), -1));
    vector<vector<int>> dp(2, vector<int>(n, 0));
    for (int i : v) dp[0][i] = 1;
    rep(i, n) {
        if (i == 0) continue;
        if (dp[0][i] == 0) continue;
        dp[0][i] += dp[0][i - 1];
    }

    dp[1] = vector<int>(n, 1);
    for (int i : v) dp[1][i] = 0;
    rep(i, n) {
        if (i == 0) continue;
        if (dp[1][i] == 0) dp[1][i] += dp[1][i - 1] + 1;
        else dp[1][i] += dp[0][i - 1];
    }

    int ans = *max_element(dp[1].begin(), dp[1].end());
    return ans;

}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(k);
    rep(i, k) cin >> v[i], v[i]--;

    if (find(v.begin(), v.end(), -1) == v.end()) {
        int ans = dp_one(n, k, v);
        cout << ans << endl;
    } else {
        int ans = dp_two(n, k, v);
        cout << ans << endl;
    }
}
