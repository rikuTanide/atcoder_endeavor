#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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

typedef pair<string, string> PS;

int lcs(string s, string t) {
    int n = s.size(), m = t.size();
    s += '$';
    t += '%';
    vector<vector<int> > dp(n + 2, vector<int>(m + 2, -(n + m)));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cmax(dp[i + 1][j], dp[i][j]);
            cmax(dp[i][j + 1], dp[i][j]);
            cmax(dp[i + 1][j + 1], dp[i][j] + (s[i] == t[j]));
        }
    }
    return dp[n][m];
}

int main() {

    int n;
    string s;
    cin >> n >> s;

    vector<PS> pairs;
    for (int i = 0; i <= s.size(); i++) {
        pairs.emplace_back(s.substr(0, i), s.substr(i));
    }

    int ans = 0;
    for (PS p : pairs) {
        int now = lcs(p.first, p.second);
        cmax(ans, now);
    }
    cout << n - ans * 2 << endl;
}
