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


int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a_list(n);
    rep(i, n) {
        ll a;
        cin >> a;
        a_list[i] = a;
    }

    vector<int> one_counts(40);
    for (ll a : a_list) {
        for (int keta = 0; keta < 40; keta++) {
            int konoketaha_one_ka = (a >> keta) & 1;
            one_counts[keta] += konoketaha_one_ka;
        }
    }

    vector<int> ans_zoukaryos(40);

    rep(i, 40) {
        ll bairitsu = 1ll << i;
        ll one_count = one_counts[i];
        ll zero_count = n - one_count;
        ll one_zouraryo = zero_count - one_count;
        ans_zoukaryos[i] = bairitsu * one_zouraryo;
    }

    ll ans = 0;
    for (int keta = 40; keta >= 0; keta--) {
        // 左の桁から
        int kono_kno_ketaha_one_ka = (k >> keta) & 1;
        if (kono_kno_ketaha_one_ka == 0) continue;

        // kは1
        // ansのketaを0にした場合、最も大きいものを選ぶ

        {
            ll now = 0;
            // 貪欲
            for (int i = 0; i < keta; i++) {
                if (ans_zoukaryos[i] > 0) {
                    now += ans_zoukaryos[i];
                }
            }
            ans = max(ans, now);
        }
    }

    cout << ans << endl;

}

