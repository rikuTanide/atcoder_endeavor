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

int MAX = 16;

vector<vector<ll>> solve(vector<ll> a, int offset = 0) {
    int n = a.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(MAX, INF));
    for (int j = 0; j < MAX; ++j) dp[0][j] = 0, dp[1][j] = j * 2 + offset;
    for (int i = 1; i < n; ++i) {
        ll s = a[n - i - 1];
        for (int j = 0; j < MAX; ++j) {
            ll t = a[n - i];
            int need = 0;
            while (s > t) ++need, t *= 4;
            ll add = 0;
            if (need >= MAX) {
                add = (need - MAX + 1) * i * 2;
                need = MAX - 1;
            }
            cmin(dp[i + 1][j], dp[i][need] + j * 2 + add + offset);
            s *= 4;
        }
    }
    return dp;
}

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &l:v) cin >> l;

    auto right = solve(v, 0);
    reverse(v.begin(), v.end());
    auto left = solve(v, 1);
    ll res = INF;
    for (int i = 0; i <= n; ++i) cmin(res, left[i][0] + right[n - i][0]);
    cout << res << endl;
}
