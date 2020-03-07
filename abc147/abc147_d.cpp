#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef long long ll;
typedef long long ll;
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
const double PI = 3.14159265358979323846;

typedef pair<ll, ll> P;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}

    mint operator-() const { return mint(-x); }

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

    mint operator+(const mint a) const { return mint(*this) += a; }

    mint operator-(const mint a) const { return mint(*this) -= a; }

    mint operator*(const mint a) const { return mint(*this) *= a; }

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod - 2); }

    mint &operator/=(const mint a) { return *this *= a.inv(); }

    mint operator/(const mint a) const { return mint(*this) /= a; }
};

int main() {

    int n;
    cin >> n;
    vector<ll> numbers(n);
    rep(i, n)cin >> numbers[i];


    vector<int> zeros(61, 0), ones(61, 0);

    for (ll a : numbers) {

        for (int i = 0; i <= 60; i++) {
            int b = a % 2;
            if (b) ones[i]++;
            else zeros[i]++;
            a /= 2;
        }

    }

    vector<ll> conb(61, 0);
    rep(i, 61) conb[i] = zeros[i] * ones[i];

    mint ans = 0;
    rep(i, 61) {
        mint now = mint(2).pow(i) * conb[i];
        ans += now;
    }
    cout << ans.x << endl;

}