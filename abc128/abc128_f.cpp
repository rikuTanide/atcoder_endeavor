#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef tuple<string, int, int> T;

int main() {

    ll n;
    cin >> n;

    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    ll ans = 0;

    for(ll c = 1 ; c < n ; c ++) {
        ll sum = 0;
        set<ll> used;
        for(ll x = 0; ; x ++) {
            ll b = x * c;
            ll r = (n - 1 ) - (x * c);

            if(!(b < n && r >= 0) ) break;
            if(r <= 0 || (r - c) <= 0) break;
            used.insert(b);
            if(used.find(r) != used.end()) {
                break;
            }

            sum += a[b];
            sum += a[r];
            ans = max(sum , ans);

            
        }

    }

    cout << ans << endl;
}

