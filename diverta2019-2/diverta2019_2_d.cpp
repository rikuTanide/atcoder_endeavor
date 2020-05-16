#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
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

ll solve(vector<ll> a, vector<ll> b, ll n) {
    vector<ll> dp(n + 1, -1);
    dp[0] = 0;
    dp[n] = n;
    auto set = [&](ll i, ll v) {
        if (i > n) return;
        if (dp[i] == -1) dp[i] = v;
        else
            cmax(dp[i], v);
    };

    rep(i, n) {
        if (dp[i] == -1) continue;
        rep(j, 3) {
            ll ld = i + a[j];
            ll gd = dp[i] + b[j];
            set(ld, gd);
        }
    }
    ll ans = *max_element(dp.begin(), dp.end());
    return ans;
}


int main() {
    int n;
    cin >> n;
    vector<ll> a(3), b(3);
    rep(i, 3) cin >> a[i];
    rep(i, 3) cin >> b[i];

    n = solve(a, b, n);
    n = solve(b, a, n);
    cout << n << endl;

}