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

template<class T>
std::istream &operator>>(std::istream &in, set<T> &o) {
    T a;
    in >> a;
    o.insert(a);
    return in;
}

template<class T>
std::istream &operator>>(std::istream &in, queue<T> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;
int mod = 1000000007;

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

vector<ll> get_start(ll n) {
    vector<vector<ll>> v = {
            {0,          0,    1},
            {100000000,  1917, 1527},
            {200000000,  1039, 625},
            {300000000,  973,  94},
            {400000000,  1748, 659},
            {500000000,  1678, 1627},
            {600000000,  1619, 33},
            {700000000,  1482, 175},
            {800000000,  893,  1533},
            {900000000,  1816, 216},
            {1000000000, 1917, 1527},
            {1100000000, 1039, 625},
            {1200000000, 973,  94},
            {1300000000, 1748, 659},
            {1400000000, 1678, 1627},
            {1500000000, 1619, 33},
            {1600000000, 1482, 175},
            {1700000000, 893,  1533},
            {1800000000, 1816, 216},
            {1900000000, 1917, 1527},
            {2000000000, 1039, 625},
            {2100000000, 973,  94},
    };
    reverse(v.begin(), v.end());
    for (vector<ll> &u : v) {
        if (u[0] <= n) {
            return u;
        }
    }
}

int main() {

    int n, m;
//    ll n = 1ll << 31, m = 1999;
    cin >> n >> m;
    mod = m;

    auto v = get_start(n);

    mint p1 = v[1];
    mint p2 = v[2];

    for (int i = v[0] + 1; i < n; i++) {
        mint now = p2.pow(2) + p1.pow(2);
        p2 = p1;
        p1 = now;

//        if (i % 100000000 == 0) {
//            cout << i << ' ' << p1 << ' ' << p2 << endl;
//        }

    }

    cout << p1 << endl;

}
