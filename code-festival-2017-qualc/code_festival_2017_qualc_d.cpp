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


int rev(int bit, int i) {
    return bit ^ (1 << i);
}

int main() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> dp(n + 1, INT_MAX / 10);
    vector<int> mval(1ll << 26, INT_MAX / 10);

    dp[0] = 0;
    mval[0] = 0;

    int par = 0;
    for (int i = 1; i <= n; i++) {
        par = rev(par, s[i - 1] - 'a');
        cmin(dp[i], mval[par] + 1);
        for (int j = 0; j < 26; j++) {
            par = rev(par, j);
            cmin(dp[i], mval[par] + 1);
            par = rev(par, j);
        }
        cmin(mval[par], dp[i]);
    }
    cout << dp[n] << endl;
}
