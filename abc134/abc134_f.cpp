#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;

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

mint dp[55][55][2605];

int main() {
    int n, score;
    cin >> n >> score;

    dp[0][0][0] = 1;
    rep(i, n) {
        rep(j, i + 1) {
            rep(k, score + 1) {
                {
                    int nj = j;
                    dp[i + 1][nj][k + nj * 2] += dp[i][j][k];
                }
                {
                    int nj = j + 1;
                    dp[i + 1][nj][k + nj * 2] += dp[i][j][k];
                }
                {
                    int nj = j;
                    mint x = j * 2;
                    dp[i + 1][nj][k + nj * 2] += dp[i][j][k] * x;
                }
                if (j >= 1) {
                    int nj = j - 1;
                    mint x = j * j;
                    dp[i + 1][nj][k + nj * 2] += dp[i][j][k] * x;
                }
            }
        }
    }
    mint ans = dp[n][0][score];
    cout << ans.x << endl;

}

