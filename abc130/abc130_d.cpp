#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
const ll INF = 1001001001;
const int mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    ll s = 0;
    int j = 0;
    ll ans = 0;

    rep(i, n) {
        while (j < n && s + a[j] < k) {
            s += a[j];
            ++j;
        }
        ans += j - i;
        s -= a[i];
    }

    ans = (ll) n * (n + 1) / 2 - ans;

    cout << ans << endl;

    return 0;
}
