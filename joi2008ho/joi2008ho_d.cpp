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
    cin >> n >> m;

    vector<vector<P>> v(n);
    rep(i, n) {
        int k;
        cin >> k;
        v[i] = vector<P>(k);
        rep(j, k) {
            cin >> v[i][j].first >> v[i][j].second;
        }
    }

    vector<vector<vector<ll>>> dp(n);
    rep(i, n) {
        dp[i] = vector<vector<ll>>(m + 1, vector<ll>(v[i].size(), INF));

        // 普通のジャンプ
        if (i == 0) {
            rep(x, v[0].size()) dp[0][i][x] = 0;
            continue;
        }

        rep(x, v[i - 1].size()) {
            rep(y, v[i].size()) {
                P prev = v[i - 1][x];
                P next = v[i][y];

                rep(j, m + 1) {
                    ll hori = abs(prev.first - next.first);
                    ll slip = prev.second + next.second;
                    ll now = hori * slip;
                    cmin(dp[i][j][y], dp[i - 1][j][x] + now);
                }
            }
        }

        // 一個飛ばしジャンプ
        if (i == 1) {
            if (m > 0) rep(x, v[1].size()) dp[1][1][x] = 0;
            continue;
        }

        rep(x, v[i - 2].size()) {
            rep(y, v[i].size()) {
                P prev = v[i - 2][x];
                P next = v[i][y];

                rep(j, m) {
                    ll hori = abs(prev.first - next.first);
                    ll slip = prev.second + next.second;
                    ll now = hori * slip;
                    cmin(dp[i][j + 1][y], dp[i - 2][j][x] + now);
                }
            }
        }
    }


    ll ans = INF;
    rep(i, m + 1) rep(x, v[n - 1].size()) {
            cmin(ans, dp[n - 1][i][x]);
        }

    rep(i, m) rep(x, v[n - 2].size()) {
            cmin(ans, dp[n - 2][i][x]);
        }
    cout << ans << endl;


}
