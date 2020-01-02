#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
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

int main() {

    ll n;
    cin >> n;
    bitset<100> d(n);

    int max_digit = 0;

    for (int i = 100; i >= 0; i--) {
        if (d[i]) {
            max_digit = i;
            break;
        }
    }
    vector<vector<mint>> dp(3, vector<mint>(100, 0));
    dp[0][max_digit] = 1, dp[1][max_digit] = 1;

    for (int i = max_digit - 1; i >= 0; i--) {
        if (d[i] == 0) {
            dp[0][i] = dp[0][i + 1] + dp[1][i + 1];
            dp[1][i] = dp[1][i + 1];
            dp[2][i] = dp[1][i + 1] + dp[2][i + 1] * 3;
        } else {
            dp[0][i] = dp[0][i + 1];
            dp[1][i] = dp[0][i + 1] + dp[1][i + 1];
            dp[2][i] = dp[1][i + 1] * 2 + dp[2][i + 1] * 3;
        }
    }

    cout << (dp[0][0] + dp[1][0] + dp[2][0]).x << endl;
    return 0;
}