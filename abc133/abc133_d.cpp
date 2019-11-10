#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;

const int mod = 1000000007;

int main() {

    int n;
    cin >> n;
    vector<int> a(n);

    rep(i, n)cin >> a[i];
    ll x2 = 0;
    rep(i, n) {
        if (i % 2) x2 -= a[i];
        else x2 += a[i];
    }
    vector<int> ans(n);
    ans[0] = x2 / 2;
    rep(i, n - 1) {
        ans[i + 1] = a[i] - ans[i];
    }
    rep(i, n)ans[i] *= 2;
    rep(i, n) {
        cout << ans[i] << ' ';
    }
    cout << endl;

}

