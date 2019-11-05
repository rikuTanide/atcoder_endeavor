#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;

const ll INF = 1001001001;


int main() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    rep(i, n)cin >> a[i];
    ll sum = 0;
    rep(i, n) sum += a[i];

    set<ll> candidates;
    for (int i = 1; i * i <= sum; i++) {
        if (sum % i != 0) continue;
        candidates.insert(i);
        candidates.insert(sum / i);
    }

    ll ans = 1;
    for (ll x : candidates) {
        ll need;
        {
            vector<ll> r(n);
            rep(i, n) r[i] = a[i] % x;
            sort(r.begin(), r.end());
            ll rsum = 0;
            rep(i, n)rsum += x - r[i];
            ll lsum = 0;
            need = INF;
            rep(i, n) {
                lsum += r[i];
                rsum -= x - r[i];
                need = min(need, max(lsum, rsum));
            }
        }
        if (need <= k) {
            ans = max(ans, x);
        }
    }

    cout << ans << endl;

}
