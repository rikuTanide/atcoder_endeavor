#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

map<ll, int> factorize(ll n) {
    map<ll, int> res;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        res[i] = 0;
        while (n % i == 0) {
            n /= i;
            res[i]++;
        }
    }

    if (n != 1) res[n] = 1;
    return res;
}

ll comb(ll l, ll r) {
    map<ll, ll> factors;
    for (ll j = l; j > (l - r); j--) {
        auto fs = factorize(j);
        for (auto f : fs) {
            factors[f.first] += f.second;
        }
    }

    for (ll j = 1; j <= r; j++) {
        auto fs = factorize(j);
        for (auto f : fs) {
            factors[f.first] -= f.second;
        }
    }

    ll s = 1;

    for (auto e : factors) {

        for (int k = 0; k < e.second; k++) {
            s *= e.first;
        }
    }

    return s;
}

int main() {
    int n;
    ll d, x, y;
    cin >> n >> d >> x >> y;

    if (x % d != 0) {
        cout << 0 << endl;
        ret();
    }
    if (y % d != 0) {
        cout << 0 << endl;
        ret();
    }

    auto can = [&](ll jump_count, ll goal) -> bool {
        if (jump_count == 0 && goal != 0) return false;
        ll min_jump_count = abs(goal) / d;
        if (jump_count < min_jump_count) return false;
        ll surplus_jump_count = jump_count - min_jump_count;
        if (surplus_jump_count % 2 != 0) return false;
        return true;
    };

    double ans = 0;

    auto rate = [&](ll jump_count, ll goal) -> double {
        ll min_jump_count = abs(goal) / d;
        ll surplus_jump_count = jump_count - min_jump_count;
        ll a = min_jump_count + (surplus_jump_count / 2);

        double k = comb(jump_count, a);

        double ans = k / pow(2, jump_count);
        return ans;
    };

    for (int i = 0; i <= n; i++) {
        ll vertical = i;
        ll horizontal = n - i;

        if (!can(vertical, y)) continue;
        if (!can(horizontal, x)) continue;

        double vertical_rate = rate(vertical, y);
        double horizontal_rate = rate(horizontal, x);

        double par = comb(n, i) / pow(2, n);

        double now = horizontal_rate * vertical_rate * par;

        ans += now;
    }

    cout << setprecision(20) << ans << endl;

}
