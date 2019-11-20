#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;

//< ave , a(time), b(manzoku) >
typedef tuple<double, int, int> A;

int gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int main() {
    int n;
    cin >> n;

    vector<int> list(n);
    rep(i, n) {
        int a;
        cin >> a;
        list[i] = a;
    }

    // 0~iまでの最大公約数
    vector<int> lgcds(n);
    lgcds[0] = list[0];
    // n~iまでの最大公約数
    vector<int> rgcds(n);
    rgcds[n - 1] = list[n - 1];


    rep(i, n) {
        if (n == 0) continue;
        lgcds[i] = gcd(lgcds[i - 1], list[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        rgcds[i] = gcd(rgcds[i + 1], list[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            int r = rgcds[1];
            ans = max(ans, r);
        } else if (i == n - 1) {
            int l = lgcds[n - 2];
            ans = max(ans, l);
        } else {
            int l = lgcds[i - 1];
            int r = rgcds[i + 1];
            ans = max(ans, gcd(l, r));
        }
    }

    cout << ans << endl;

}

