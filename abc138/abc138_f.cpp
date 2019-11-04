#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

typedef long long ll;
const int INF = 1001001001;

const int mod = 1000000007;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}

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

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod - 2);
    }

    mint &operator/=(const mint a) {
        return (*this) *= a.inv();
    }

    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
};

mint dp[61][2][2][2];

int main() {
    ll l, r;
    cin >> l >> r;

    dp[60][0][0][0] = 1;

    for (int i = 59; i >= 0; i--) {
        int lb = l >> i & 1;
        int rb = r >> i & 1;

        rep(j, 2) rep(k, 2)rep(s, 2) {
                    mint pre = dp[i + 1][j][k][s];
                    rep(x, 2)
                        rep(y, 2) {
                            if (x && !y) continue;

                            int nj = j, nk = k, ns = s;

                            if (!s && x != y) continue;
                            if (x && y) ns = 1;

                            if (!j && !x && lb) continue;
                            if (x && !lb) nj = 1;

                            if (!k && y && !rb) continue;
                            if (!y && rb) nk = 1;

                            dp[i][nj][nk][ns] += pre;
                        }

                }
    }

    mint ans;
    rep(j, 2) {
        rep(k, 2) {
            rep(s, 2) {
                ans += dp[0][j][k][s];
            }
        }
    }
    cout << ans.x << endl;
}
