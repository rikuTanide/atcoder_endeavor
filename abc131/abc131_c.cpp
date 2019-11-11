#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;

const int mod = 1000000007;

ll gcd(ll x, ll y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    // cで割り切れる物の数
    ll ub_p_c = b / c;
    ll ua_p_c = a / c;
    ll bet_ab_p_c = ub_p_c - ua_p_c;

    // dで割り切れる物の数
    ll ub_p_d = b / d;
    ll ua_p_d = a / d;
    ll bet_ab_p_d = ub_p_d - ua_p_d;

    ll g = lcm(c, d);

    // cdで割り切れる物の数
    ll ub_p_cd = b / g;
    ll ua_p_cd = a / g;
    ll bet_ab_p_cd = ub_p_cd - ua_p_cd;

    ll ans = (b - a) - bet_ab_p_c - bet_ab_p_d + bet_ab_p_cd;

    if (a % c != 0 && a % d != 0) {
        ans++;
    }

    cout << ans << endl;
}