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

//    ifstream cin("C:\\Users\\riku\\Downloads\\hand_04.txt");

    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n)cin >> v[i];

//    for(ll l : v) printf("%.10f\n", log10(abs(l)));

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

    mint ans = 1;
    rep(i, k)ans *= v[i];

    if (am % 2 == 0) {
        cout << ans << endl;
        ret();
    }

    auto can_out_minus_in_plus = [&]() -> bool {
        if (am == 0) return false;
        if (ap == p) return false;
        return true;
    };

    auto can_in_minus_out_plus = [&]() -> bool {
        if (am == m) return false;
        if (ap == 0) return false;
        return true;
    };

    auto get_abs_min_minus = [&]() -> ll {
        for (int i = k - 1; i >= 0; i--) {
            if (v[i] < 0) return v[i];
        }
        __throw_runtime_error("konaide");
    };

    auto get_abs_max_minus = [&]() -> ll {
        for (int i = k; i < n; i++) {
            if (v[i] < 0) return v[i];
        }
        __throw_runtime_error("konaide");
    };

    auto get_abs_min_plus = [&]() -> ll {
        for (int i = k - 1; i >= 0; i--) {
            if (v[i] > 0) return v[i];
        }
        __throw_runtime_error("konaide");
    };

    auto get_abs_max_plus = [&]() -> ll {
        for (int i = k; i < n; i++) {
            if (v[i] > 0) return v[i];
        }
        __throw_runtime_error("konaide");
    };

    if (can_out_minus_in_plus() && can_in_minus_out_plus()) {
        ll abs_min_minus = get_abs_min_minus();
        ll abs_max_minus = get_abs_max_minus();
        ll abs_min_plus = get_abs_min_plus();
        ll abs_max_plus = get_abs_max_plus();

        if (abs_min_plus * abs_max_plus >= abs_min_minus * abs_max_minus) {
            ans /= abs_min_minus;
            ans *= abs_max_plus;
        } else {
            ans /= abs_min_plus;
            ans *= abs_max_minus;
        }
    } else if (can_out_minus_in_plus()) {
        ll abs_min_minus = get_abs_min_minus();
        ll abs_max_plus = get_abs_max_plus();


        ans /= abs_min_minus;
        ans *= abs_max_plus;
    } else if (can_in_minus_out_plus()) {
        ll abs_max_minus = get_abs_max_minus();
        ll abs_min_plus = get_abs_min_plus();
        ans /= abs_min_plus;
        ans *= abs_max_minus;

    } else {
        __throw_runtime_error("konaide");
    }
    cout << ans << endl;
}