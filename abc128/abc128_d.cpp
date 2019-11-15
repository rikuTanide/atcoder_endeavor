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

typedef tuple<string, int, int> T;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> dq(n);
    rep(i, n) {
        cin >> dq[i];
    }
    ll ans = 0;
    for (ll l = 0; l < k; l++) {
        for (ll r = 0; r < k - l; r++) {
            if (l + r > n) break;
            ll d = k - l - r;
            ll now = 0;
            vector<ll> s;
            for (ll i = 0; i < l; i++) {
                now += dq[i];
                s.push_back(dq[i]);
            }
            for (ll i = n - r; i < n; i++) {
                now += dq[i];
                s.push_back(dq[i]);
            }
            sort(s.begin(), s.end());
            for (ll i = 0; i < d; i++) {
                if (i >= s.size()) break;
                if (s[i] >= 0) break;
                now -= s[i];
            }
            ans = max(ans, now);
        }
    }

    cout << ans << endl;
}

