#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

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
        if (t == -1) return 1;
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

mint calc(vector<ll> &v, vector<vector<int>> &add, int i) {
    rep(j, 60) {
        if ((i >> j) & 1) {
            add[j].push_back(__builtin_popcount(i));
            return mint(v[j]) * __builtin_popcount(i) + calc(v, add, i - (1 << j));
        }
    }
    return 0;
}

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

    int n;
    cin >> n;

//    rep(n, 10) {

//    int n = 4;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    sort(v.begin(), v.end());

    mint ans = 0;
//        mint ans = 0;
//        vector<vector<int>> add(60);
//        rep(i, 1 << n) {
//            ans += calc(v, add, i);
//        }
//        ans = ans * mint(2).pow(n);
//        cout << ans << endl;


//        rep(i, 20) sort(add[i].begin(), add[i].end());
    rep(i, n) {
//            ll sum = accumulate(add[i].begin(), add[i].end(), 0ll);


        int m = n - i - 1;
        mint t = i == n - 1 ? 1 : mint(m + 2) * mint(2).pow(m - 1);
        mint s = t * mint(2).pow(i);

        ans += s * v[i];

//            cout << sum << ' ' << t << ' ' << s << endl;

//            for (int j : add[i]) cout << j << ' ';
//            cout << endl;
//            cout <<  << endl;
    }
            ans = ans * mint(2).pow(n);

    cout << ans << endl;
//}

}
