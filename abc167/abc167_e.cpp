#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

struct Query {
    ll a, b, c, d;
};

std::istream &operator>>(std::istream &in, Query &o) {
    cin >> o.a >> o.b >> o.c >> o.d;
    o.a--;
    o.b--;
    return in;
}


const int mod = 998244353;

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
} combination(1000000);


int main() {
    int n, m, k;
    cin >> n >> m >> k;

    mint ans = 0;

    vector<mint> rs(n + 1);
    rs[0] = m;
    rep(i, n) {
        rs[i + 1] = rs[i] * (m - 1);
    }

    rep(i, k + 1) {
        int sp = n - 1;
        mint c = combination(sp, i);
        int blk = n - i;

        mint r = rs[blk - 1];

        mint now = r * c;
        ans += now;

    }

    cout << ans << endl;
}
