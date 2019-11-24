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

    int a, b, q;
    cin >> a >> b >> q;

    vector<ll> sha_list(a);
    vector<ll> tera_list(b);

    rep(i, a) {
        ll s;
        cin >> s;
        sha_list[i] = s;
    }

    rep(i, b) {
        ll t;
        cin >> t;
        tera_list[i] = t;
    }

    rep(i, q) {
        ll x;
        cin >> x;

        auto sha_left = MINF;
        auto sha_right = INF;
        auto sha_it = upper_bound(sha_list.begin(), sha_list.end(), x);
        if (sha_list[0] >= x) {
            sha_right = sha_list[0];
        } else if (sha_list[a - 1] <= x) {
            sha_left = sha_list[a - 1];
        } else if (*sha_it == x) {
            sha_left = *sha_it;
            sha_right = *sha_it;
        } else {
            sha_right = *sha_it;
            sha_left = *(sha_it - 1);
        }


        auto tera_left = MINF;
        auto tera_right = INF;
        auto tera_it = upper_bound(tera_list.begin(), tera_list.end(), x);
        if (tera_list[0] >= x) {
            tera_right = tera_list[0];
        } else if (tera_list[b - 1] <= x) {
            tera_left = tera_list[b - 1];
        } else if (*tera_it == x) {
            tera_left = *tera_it;
            tera_right = *tera_it;
        } else {
            tera_right = *tera_it;
            tera_left = *(tera_it - 1);
        }

        ll ans = INF;
        {
            // 寺右 神社右
            ll now = max(tera_right, sha_right) - x;
            ans = min(ans, now);
        }
        {
            // 寺右 神社左
            ll sha_dis = x - sha_left;
            ll tera_dis = tera_right - x;
            ll back = min(sha_dis, tera_dis);

            ll now = sha_dis + tera_dis + back;
            ans = min(ans, now);
        }
        {
            // 寺左 神社右
            ll sha_dis = sha_right - x;
            ll tera_dis = x - tera_left;
            ll back = min(sha_dis, tera_dis);

            ll now = sha_dis + tera_dis + back;
            ans = min(ans, now);
        }
        {
            // 寺左 神社左
            ll now = x - min(tera_left, sha_left);
            ans = min(ans, now);
        }

        cout << ans << endl;

    }

}

