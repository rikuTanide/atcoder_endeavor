#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;
ll n, k;
vector<int> one_counts(50);
vector<ll> a_list;

int main() {
    cin >> n >> k;

    rep(i, n) {
        ll a;
        cin >> a;
        a_list.push_back(a);
    }

    for (ll a : a_list) {
        for (int keta = 0; keta < 50; keta++) {
            int konoketaha_one_ka = (a >> keta) & 1;
            one_counts[keta] += konoketaha_one_ka;
        }
    }

    ll x = 0;
    rep(i, 50) {
        ll bairitsu = 1ll << i;
        ll one_count = one_counts[i];
        ll zero_count = n - one_count;

        if (one_count < zero_count && x + bairitsu <= k) {
            x += bairitsu;
        }
    }

    ll ans = 0;
    rep(i, n) {
        ans +=( x ^ a_list[i]);
    }

    cout << ans << endl;

}

// https://atcoder.jp/contests/abc117/submissions/8569276
// 参考