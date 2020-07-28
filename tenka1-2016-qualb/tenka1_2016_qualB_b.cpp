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
    int n = s.size();

    // i文字目まで見て、'(' - ')'がjであり、最後に変更を加えたのはk文字目であるときの最小コスト
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX / 10)));
    dp[0][0][0] = 0;
    auto set = [&](int i, int j, int k, int v) {
        if (j < 0) return;
        cmin(dp[i][j][k], v);
    };

    rep(i, n) {
        rep(j, n) {
            rep(k, n) {

                // 変えない
                if (s[i] == '(') {
                    set(i + 1, j + 1, k, dp[i][j][k]);
                } else {
                    set(i + 1, j - 1, k, dp[i][j][k]);
                }

                // 変える
                if (s[i] == '(') {
                    set(i + 1, j - 1, i, dp[i][j][k] + 1);
                } else {
                    set(i + 1, j + 1, i, dp[i][j][k] + 1);
                }

            }
        }
    }

    int ans = INT_MAX;
    rep(i, n) cmin(ans, dp[n][0][i] + i);
    cout << ans << endl;
}
