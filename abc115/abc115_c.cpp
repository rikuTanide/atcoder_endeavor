#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;


int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> hs(n);
    rep(i, n) {
        cin >> hs[i];
    }
    sort(hs.begin(), hs.end());

    ll ans = INF;
    for (int i = 0; i < n - k + 1; i++) {
        ll h = hs[i + k - 1];
        ll m = hs[i];
        ll now = h  - m ;
        ans = min(ans, now);
    }

    cout << ans << endl;

}

