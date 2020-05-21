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


int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    s += '0';
    int n = s.size();
    vector<vector<ll>> dp(n + 2, vector<ll>(2, INF));
    dp[0][0] = 0;
    rep(i, n + 1) {
        rep(j, 2) {
            int x = s[i] - '0';
            x += j;
            rep(a, 10) {
                int ni = i + 1, nj = 0;
                int b = a - x;
                if (b < 0) {
                    nj = 1;
                    b += 10;
                }
                dp[ni][nj] = min(dp[ni][nj], dp[i][j] + a + b);
            }
        }
    }
    int ans = dp[n][0];
    cout << ans << endl;
}
