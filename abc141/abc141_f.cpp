#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);

    rep(i, n)cin >> a[i];
    ll s = 0;
    rep(i, n) s ^= a[i];
    ll ans = s;
    rep(i, n) {
        a[i] &= ~s;
    }

    int r = 0;
    vector<int> top(n);
    for (int i = 60; i >= 0; i--) {
        int j = r;
        for (; j < n; j++) {
            if (a[j] >> i & 1) {
                swap(a[r], a[j]);
                break;
            }
        }
        if (j == n) continue;
        top[r] = i;
        rep(k, n) {
            if (r == k) continue;
            if (a[k] >> i & 1) {
                a[k] ^= a[r];
            }
        }
        r++;
    }
    ll x = 0;
    for (int i = 60; i >= 0; i--) {
        ll nx = x | (1ll << i);
        {
            ll b = nx;
            rep(j, r) {
                if (b >> top[j] & 1)b ^= a[j];
            }
            if ((b & nx) == 0) {
                x = nx;
            }
        }
    }
    ans += x * 2;
    cout << ans << endl;


}
