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


int main() {
    int n, k;
    cin >> n >> k;

    vector<P> s;
    for (int i = 1; i * i <= n; i++) {
        s.push_back(P(i, 0));
        s.push_back(P(n / i, 0));
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    rep(i, s.size() - 1) {
        int l = n / s[i + 1].first;
        int r = n / s[i].first;
        s[i].second = r - l;
    }
    s.back().second = 1;
    int m = s.size();

    map<int, int> mp;
    rep(i, m) mp[s[i].first] = i;

    vector<vector<mint>> dp(k + 1, vector<mint>(m));
    dp[0][mp[n]] = 1;

    rep(i, k) {
        for (int j = m - 2; j >= 0; j--) dp[i][j] += dp[i][j + 1];
        rep(j, m) {
            int nj = mp[n / s[j].first];
            dp[i + 1][j] = dp[i][nj] * s[j].second;
        }
    }

    mint ans = 0;
    rep(j, m)ans += dp[k][j];
    cout << ans.x << endl;

}