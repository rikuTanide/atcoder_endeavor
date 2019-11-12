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
    ll w, h, x, y;
    cin >> w >> h >> x >> y;

    double ans = (double) w * h / 2;

    if (x * 2 == w && y * 2 == h) {
        cout << ans << ' ' << 1 << endl;
    } else {
        cout << ans << ' ' << 0 << endl;

    }

}