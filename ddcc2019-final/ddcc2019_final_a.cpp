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

vector<int> seq(int n, string &s) {
    vector<int> dp(n, 0);
    rep(i, n) {
        if (i == 0) continue;
        if (s[i] == '>')dp[i] = dp[i - 1] + 1;
    }
    return dp;
}

long double count(int n, string s) {
    vector<int> dp = seq(n, s);

    long double ans = 0;
    rep(i, n) {
        char c = s[i];
        if (c == '-') ans += 1.0;
        else ans += (1.0 / (dp[i] + 1));
    }
    return ans;
}

long double add(int n, string s) {

    auto dp = seq(n, s);
    int ma = *max_element(dp.begin(), dp.end());
    int change = distance(dp.begin(), find(dp.begin(), dp.end(), ma));
    assert(s[change + 1] == '-');
    s[change + 1] = '>';

    return count(n, s);

}

long double connect(int n, string s) {

    auto dp = seq(n, s);
    int ma = 0;
    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] == '>' && s[i] == '-' && s[i + 1] == '>') {
            int now = dp[i - 1] + dp[i + 1];
            cmax(ma, now);
        }
    }

    if (ma == 0) return INF;

    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] == '>' && s[i] == '-' && s[i + 1] == '>') {
            int now = dp[i - 1] + dp[i + 1];
            if (now == ma) {
                s[i] = '>';
                return count(n, s);
            }
        }
    }

    __throw_runtime_error("konai");

}

int main() {
    int n;
    string s;
    cin >> n >> s;

    long double ans = min(add(n, s), connect(n, s));

    cout << setprecision(20) << ans << endl;

}
