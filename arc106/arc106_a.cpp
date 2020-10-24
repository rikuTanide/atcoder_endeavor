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


void solve() {


    ll n;
    cin >> n;

    vector<int> ms = {
            9999433,
            9999463,
            9999469,
            9999481,
            9999511,
            9999533,
            9999593,
            9999601,
            9999637,
            9999653,
            9999659,
            9999667,
            9999677,
            9999713,
            9999739,
            9999749,
            9999761,
            9999823,
            9999863,
            9999877,
            9999883,
            9999889,
            9999901,
            9999907,
            9999929,
            9999931,
            9999937,
            9999943,
            9999971,
            9999973,
            9999991,
            1000000007
    };

    auto check = [&](int a, int b) -> bool {
        for (int m : ms) {
            mod = m;
            mint am = mint(3).pow(a);
            mint bm = mint(5).pow(b);
            mint abm = am + bm;
            if (abm.x != mint(n).x) {
                return false;
            }
        }
        return true;
    };

    double nl = log10(n);

    for (int a = 1; a < 100; a++) {
        for (int b = 1; b < 100; b++) {

            double al = log10(3) * a;
            double bl = log10(5) * b;

            if (al - 0.1 > nl) continue;
            if (bl - 0.1 > nl) continue;

            if (check(a, b)) {
                printf("%d %d\n", a, b);
                return;
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    solve();
}
