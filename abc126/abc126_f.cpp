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

const int mod = 1e9 + 7;

ll pow2(ll a, ll b) {
    ll res = a;
    for (ll i = 1; i < b; i++) {
        res *= a;
    }
    return res;
}

int main() {
    ll m, k;
    cin >> m >> k;

    if (pow2(2, m) <= k) {
        cout << -1 << endl;
        return 0;
    }

    if (m == 0) {
        if (k == 0) {
            cout << "0 0" << endl;
            return 0;
        } else {
            cout << "-1" << endl;
            return 0;
        }
    }

    if (m == 1) {
        if (k == 1) {
            cout << "-1" << endl;
            return 0;
        } else {
            cout << "0 0 1 1" << endl;
            return 0;
        }
    };

    ll c = pow2(2, m);

    vector<ll> ans(c * 2, 0);
    for (ll i = 0; i < c; i++) {
        ans[i] = i;
    }
    ans[c] = k;
    for (ll i = 0; i < c; i++) {
        ans[2 * c - i - 2] = i;
    }

    ans[2 * c - 1] = k;


    for (auto i : ans) {
        cout << ' ' << i;
    }
    cout << endl;

}

