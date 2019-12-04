#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
const double INF = 1e10;
//const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
typedef tuple<int, int, int> Q;

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


int main() {
    string s;
    cin >> s;
    vector<vector<mint>> dp(s.size() + 1, vector<mint>(4, 0));
    dp[0][0] = 1;
    for (int i = 0; i < s.size(); i++) {

        if (s[i] == 'A') {
            dp[i + 1][1] += dp[i][0];
        } else if (s[i] == 'B') {
            dp[i + 1][2] += dp[i][1];
        } else if (s[i] == 'C') {
            dp[i + 1][3] += dp[i][2];
        } else {
            for (int j = 0; j < 3; j++) {
                dp[i + 1][j + 1] += dp[i][j];
            }
        }

        if (s[i] == '?') {
            for (int j = 0; j < 4; j++) {
                dp[i + 1][j] += dp[i][j] * 3;
            }
        } else {
            for (int j = 0; j < 4; j++) {
                dp[i + 1][j] += dp[i][j];
            }
        }

    }

    cout << dp[s.size()][3].x << endl;

}
