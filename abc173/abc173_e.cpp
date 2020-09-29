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
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n)cin >> v[i];

    int p = 0, m = 0, z = 0;
    for (ll l : v) {
        if (l == 0) z++;
        else if (l < 0) m++;
        else p++;
    }

    if (p + m < k) {
        cout << 0 << endl;
        ret();
    }

    bool over_zero = [&]() -> bool {
        for (int i = 0; i * 2 <= k; i++) {
            if (i * 2 <= m && k - (i * 2) <= p) return true;
        }
        return false;
    }();

    if (!over_zero) {
        if (z > 0) {
            cout << 0 << endl;
            ret();
        }
        sort(v.begin(), v.end(), [](ll a, ll b) { return abs(a) < abs(b); });
        mint ans = 1;
        rep(i, k)ans *= v[i];
        cout << ans << endl;
        ret();
    }

    sort(v.begin(), v.end(), [](ll a, ll b) { return abs(a) > abs(b); });

    int ap = 0, am = 0;
    rep(i, k) {
        ll l = v[i];
        if (l < 0) am++;
        else ap++;
    }
    if (am % 2 == 0) {
        mint ans = 1;
        rep(i, k)ans *= v[i];
        cout << ans << endl;
        ret();
    }

    vector<ll> vp, vm;

    for (ll l: v) {
        if (l < 0) vm.push_back(l);
        else if (l > 0) vp.push_back(l);
    }

    vector<ll> vvp, vvm;
    {
        for (ll l : vp) vvp.push_back(l);
        rep(i, am - 1) vvp.push_back(vm[i]);
    }

    {
        for (ll l : vm) vvm.push_back(l);
        rep(i, ap - 1) vvm.push_back(vp[i]);
    }

    sort(vvp.begin(), vvp.end(), [](ll a, ll b) { return abs(a) > abs(b); });
    sort(vvm.begin(), vvm.end(), [](ll a, ll b) { return abs(a) > abs(b); });


    long double vvpl = 0, vvml = 0;
    if (vvp.size() >= k) rep(i, k) vvpl += log10l(abs(vvp[i]));
    if (vvm.size() >= k) rep(i, k) vvml += log10l(abs(vvm[i]));

    if (vvpl > vvml) {
        mint ans = 1;
        rep(i, k)ans *= vvp[i];
        cout << ans << endl;
        ret();
    } else {
        mint ans = 1;
        rep(i, k)ans *= vvm[i];
        cout << ans << endl;
        ret();
    }

}