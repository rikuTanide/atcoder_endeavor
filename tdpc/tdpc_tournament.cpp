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

bool equal(double a, double b) {
//    return fabs(a - b) < DBL_EPSILON;
    return fabs(a - b) < EPS;
}

template<class T>
std::istream &operator>>(std::istream &in, set<T> &o) {
    T a;
    in >> a;
    o.insert(a);
    return in;
}

template<class T>
std::istream &operator>>(std::istream &in, queue<T> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

double match(double q, double p) {
    double f = (p - q) / 400;
    return 1.0 / (1.0 + pow(10, f));
}

vector<int> vs(int i, int k) {
    int left_bit = (1 << (k - 1));
    int j = (i ^ left_bit);
    int l = ~((1 << (k - 1)) - 1);
    int m = j & l;
    vector<int> res;
    rep(n, 1 << (k - 1)) {
        res.push_back(m + n);
    }
    return res;
}

double solve(vector<double> &v, int i, int k, vector<vector<double>> &dp) {
    if (k == 0) return 1;
    if (dp[k][i] != -1) return dp[k][i];
    double ans = [&]() -> double {
        double ans = 0;
        for (auto j : vs(i, k)) {
            double me = solve(v, i, k - 1, dp);
            double other = solve(v, j, k - 1, dp);
            double m = match(v[i], v[j]);
            double now = me * other * m;
            ans += now;
        }
        return ans;
    }();
    dp[k][i] = ans;
    return ans;
}

int main() {

//    int k = 3;


    int k;
    cin >> k;
    vector<double> v(1 << k);
    rep(i, 1 << k) cin >> v[i];
//
//    for (int j = 1; j <= k; j++) {

    vector<vector<double>> dp(k + 1, vector<double>(1 << k, -1));

    rep(i, 1 << k) {
        double ans = solve(v, i, k, dp);
        printf("%.20f\n", ans);
    }
//    }

}
