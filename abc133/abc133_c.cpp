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

    ll l, r;
    cin >> l >> r;

    r = min(r, l + (2 * 2019));

    int ans = 2018;

    for (ll i = l; i <= r; i++) {
        for (ll j = i + 1; j <= r; j++) {
            int x = i * j % 2019;
            ans = min(ans, x);
        }
    }

    cout << ans << endl;

}

