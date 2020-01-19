#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
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

// https://atcoder.jp/contests/abc020/submissions/9343993
vector<int> divisor(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i)res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}


ll ppow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b) {
        if (b & 1)res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {

    ll n, k;
    cin >> n >> k;
    vector<int> v = divisor(k);
    vector<mint> dp(2000, 0);


    rep(i, v.size()) {
        ll mi = v[i];
        ll ma = n / mi * mi;
        ll count = n / mi;
        dp[i] = ((mi + ma) * count / 2);
    }
    mint ans = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] % v[i] == 0) {
                dp[i] -= dp[j];
            }
        }
        ans += dp[i] * k * mint(v[i]).pow(mod - 2);
    }

    cout << ans.x << endl;

}

