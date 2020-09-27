#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
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

int main() {
    int n;
    cin >> n;
    vector<P> v(n);
    for (P &p:v) cin >> p.first >> p.second;

    int zz = 0;
    for (P p : v) if (p == P(0, 0)) zz++;

    int za = 0;
    for (P p: v) if (p.first == 0 && p.second != 0) za++;

    int az = 0;
    for (P p: v) if (p.first != 0 && p.second == 0) az++;

    map<P, int> pp, pm;

    auto is_pp = [&](P p) -> bool {
        if (p.first > 0 && p.second > 0) return true;
        if (p.first < 0 && p.second < 0) return true;
        return false;
    };

    auto norm = [](P p) -> P {
        ll a = abs(p.first);
        ll b = abs(p.second);
        ll g = __gcd(a, b);
        a /= g;
        b /= g;
        return P(a, b);
    };


    for (P p : v) {
        if (is_pp(p)) pp[norm(p)]++;
        else pm[norm(p)]++;
    }

    mint ans = 1;

    auto calc_pair = [&](ll a, ll b) -> mint {
        return mint(2).pow(a) + mint(2).pow(b) - 1;
    };

    for (auto e : pp) {
        int a = e.second;
        P f = {e.first.second, e.first.first};
        int b = pm[f];
        ans *= calc_pair(a, b);

        pm.erase(pm.find(f));
    }

    for (auto e : pm) {
        ans *= mint(2).pow(e.second);
    }

    ans *= calc_pair(az, za);

    ans += zz;

    ans = ans - 1;

    cout << ans << endl;

}
