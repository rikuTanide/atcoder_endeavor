#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
//const int INF = INT_MAX  ;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;

int main() {

    int n, m;

    cin >> n >> m;
    vector<P> pharmacies(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        pharmacies[i] = P(a, b);
    }

    sort(pharmacies.begin(), pharmacies.end());

    ll ans = 0;
    ll count = 0;

    for (auto p : pharmacies) {
        if (count + p.second >= m) {
            ll h = m - count;
            ans += h * p.first;
            break;
        } else {
            count += p.second;
            ans += p.second * p.first;
        }
    }

    cout << ans << endl;
}

