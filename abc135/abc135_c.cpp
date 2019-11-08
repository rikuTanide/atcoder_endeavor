#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;

int main() {
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    rep(i, n + 1) cin >> a[i];
    vector<ll> b(n);
    rep(i, n) cin >> b[i];

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll left = min(a[i], b[i]);
        a[i] -= left;
        b[i] -= left;
        sum += left;

        ll right = min(a[i + 1], b[i]);
        a[i + 1] -= right;
        b[i] -= right;
        sum += right;
    }
    cout << sum << endl;

}
