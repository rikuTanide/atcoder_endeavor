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
    int n, m;
    string s;
    cin >> n >> m >> s;

    vector<int> dp(m, 0);
    rep(i, m) {
        char a = i == 0 ? '*' : s[i - 1], b = s[i];
        string ab;
        ab.push_back(a);
        ab.push_back(b);
        // II
        if (ab == "II") {
            dp[i] = 1;

        }
            // IO
            // OI
        else if (ab == "IO" || ab == "OI") {
            dp[i] = dp[i - 1] + 1;
        }
            // OO
        else if (ab == "OO") {
            dp[i] = 0;
        }
            // *I
        else if (ab == "*I") {
            dp[i] = 1;
        }
            // *O
        else if (ab == "*O") {
            dp[i] = 0;
        }
    }

    int ans = 0;
    rep(i, m) {
        if (s[i] == 'O') continue;
        int t = dp[i];
        if (t >= n * 2 + 1) ans++;
    }

    cout << ans << endl;

}
