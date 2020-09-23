#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

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
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &l:v) cin >> l;

    vector<vector<map<int, ll>>> dp(n + 1, vector<map<int, ll>>(2));// dp[ここまで見て][一個前を使った][選んだ数]=合計
    dp[0][0][0] = 0;

    rep(i, n) {

        int ma = min(i / 2 + 5, n);
        int mi = max(i / 2 - 5, 0);

        auto set = [&](bool b, int j, ll value) {
            if (j < mi) return;
            if (j > ma) return;
            if (dp[i + 1][b].find(j) == dp[i + 1][b].end()) {
                dp[i + 1][b][j] = value;
            } else {
                cmax(dp[i + 1][b][j], value);
            }
        };


        {
            // 選ばない → 選ぶ
            for (auto e : dp[i][false]) {
                set(true, e.first + 1, e.second + v[i]);
//                dp[i + 1][true][e.first + 1] = e.second + v[i];
            }
        }

        {
            // 選ばない → 選ばない
            for (auto e : dp[i][false]) {
                set(false, e.first, e.second);
//                dp[i + 1][false][e.first] = e.second;
            }
        }

        {
            // 選ぶ → 選ばない
            for (auto e : dp[i][true]) {
                set(false, e.first, e.second);
//                cmax(dp[i + 1][false][e.first], e.second);
            }
        }

    }

    ll ans = -INF;
    rep(b, 2) {
        cmax(ans, dp[n][b][n / 2]);
    }
    cout << ans << endl;

}
