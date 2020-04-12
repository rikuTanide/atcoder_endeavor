#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

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

    friend std::istream &operator>>(std::istream &in, mint &o) {
        ll a;
        in >> a;
        o = a;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const mint &o) {
        out << o.x;
        return out;
    }

};


ll gcd(ll x, ll y) {
    if (x > y) swap(x, y);
    ll m = 1;
    while (m != 0) {
        m = y % x;
        y = x;
        x = m;
    }
    return y;
}


vector<ll> get_primes(ll k) {

    vector<bool> v(k + 1, true);
    for (ll i = 2; i < k + 1; i++) {
        if (!v[i]) continue;
        for (ll j = 2; i * j < k + 1; j++) {
            v[i * j] = false;
        }
    }

    vector<ll> ans;
    rep(i, k + 1) {
        if (i <= 1) continue;
        if (v[i]) ans.push_back(i);
    }
    return ans;
}

int main() {

    ll n, k;
    cin >> n >> k;
    
    vector<ll> counts(k + 1, 0);
    rep(i, k + 1) {
        if (i <= 1) continue;
        counts[i] = k / i;
    }

    vector<mint> dp(k + 1, 0);
//    vector<ll> primes = get_primes(k);
    // 答えが2になるのは2の倍数だけでできた場合から
    // 4の倍数だけでできた場合などを引いた
    for (int i = k; i >= 2; i--) {
        mint now = mint(counts[i]).pow(n);
        for (ll l = 2; l * i <= k; l++) {
//            if (i * l > k) break;
            now -= dp[i * l];
        }
        dp[i] = now;
    }

    mint sum = 0;
    for (ll i = 2; i <= k; i++) {
        sum += (dp[i] * i);
    }

//    ll fsum = accumulate(counts.begin(), counts.end(), 0ll);
    mint fsum = 0;
    for (mint m : dp) {
        fsum += m;
    }
    mint one = mint(k).pow(n);
    one -= fsum;
    sum += one;
    cout << sum << endl;

}

