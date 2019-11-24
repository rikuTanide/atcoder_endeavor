#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
//const int INF = INT_MAX  ;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;


int main() {
    int n;
    cin >> n;
    double ans = 0;
    rep(i, n) {
        double x;
        string u;
        cin >> x >> u;
        if (u == "JPY") {
            ans += x;
        } else {
            ans += 380000.0 * x;
        }
    }

    printf("%.10f", ans);
}

