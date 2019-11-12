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

struct mint {
    ll x;

    mint(ll x = 0) : x(x % mod) {}

    mint &operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }

    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }

    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }

    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
};


mint dp0[2005][2005];
mint dp1[2005][2005];

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> s(n + 1), t(m + 1);
    rep(i, n)scanf("%d", &s[i]);
    rep(i, m)scanf("%d", &t[i]);
    dp0[0][0] = 1;

    rep(i, n + 1)
        rep(j, m + 1) {
            dp0[i + 1][j] += dp0[i][j];
            dp1[i][j] += dp0[i][j];
            dp1[i][j + 1] += dp1[i][j];
            if (s[i] == t[j]) {
                dp0[i + 1][j + 1] += dp1[i][j];
            }
        }
    mint ans = dp1[n][m];
    cout << ans.x << endl;
}
