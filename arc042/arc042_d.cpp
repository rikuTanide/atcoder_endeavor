#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

int mod;

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


void small(ll x, ll p, ll a, ll b) {
    ll ans = INF;
    for (ll i = a; i <= b; i++) {
        mint now = mint(x).pow(i);
        cmin(ans, now.x);
    }
    cout << ans << endl;
}

ll modpow(ll a, ll n = mod - 2) {
    ll r = 1;
    while (n) r = r * ((n % 2) ? a : 1) % mod, a = a * a % mod, n >>= 1;
    return r;
}

void big(ll x, ll p, ll a, ll b) {
    map<ll, int> MM;

    ll cur = 1, sq;
    for (sq = 0; sq * sq <= p; sq++) {
        MM[cur] = sq;
        cur = cur * x % p;
    }

    ll re = modpow(x), xsq = 1;
    rep(i, sq) xsq = xsq * re % p;
    ll XA = modpow(x, a);
    ll XAr = modpow(XA);
    for (ll a = 1; a <= p; a++) {
        ll tar = a * XAr % mod;
        ll st = 1;
        rep(i, sq) {
            if (MM.count(tar) && sq * i + MM[tar] <= b) {
                cout << a << endl;
                return;
            }
            tar = tar * xsq % mod;
        }
    }
}

int main() {
    ll x, p, a, b;
    cin >> x >> p >> a >> b;

    mod = p;


    if (b - a >= p) {
        cout << 1 << endl;
        ret();
    }

    if (b - a <= 1000000ll) {
        small(x, p, a, b);
    } else {
        big(x, p, a, b);
    }


}
