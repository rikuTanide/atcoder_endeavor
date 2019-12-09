#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
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


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

struct combination {
    vector<mint> fact, ifact;

    combination(int n) : fact(n + 1), ifact(n + 1) {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }

    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
};

int main() {
    ll n;
    cin >> n;
    vector<ll> as(n);
    rep(i, n) {
        cin >> as[i];
    }

    sort(as.begin(), as.end());
    ll mx = as[n - 1];

    combination c(mx);


    ll mxc = 0;
    ll mi = 0;
    for (ll i = 0; i < n - 1; i++) {
        mint now = c(mx, as[i]);
        if (mxc < now.x) {
            mxc = now.x;
            mi = as[i];
        }
    }

    cout << mx << ' ' << mi << endl;

}
