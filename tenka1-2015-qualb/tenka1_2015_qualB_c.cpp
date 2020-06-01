#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

ll naive_solution(ll l) {
    ll cnt = 0;
    for (ll a = 1; a <= l; a++) {
        for (ll b = a + 1; b <= l; b++) {
            for (ll c = b + 1; c <= l; c++) {
                if (b - a != 1 && c - b != 1) {
                    continue;
                }
                if (a + b <= c) {
                    break;
                }
                if (a + b + c > l) {
                    break;
                }
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int l;
    cin >> l;

    vector<mint> tmp(100);
    rep(i, 100) tmp[i] = naive_solution(i);

    if (l < 100) {
        cout << tmp[l] << endl;
        ret();
    }

    ll x = 99;

    while ((l - x) % 12) {
        x -= 1;
    }
    x -= 36;

    ll n = (l - x) / 12;

    mint a = tmp[x];
    mint b = tmp[x + 12];
    mint c = tmp[x + 24];
    mint d = tmp[x + 36];

    mint ans = a * (n - 1) * (n - 2) * (n - 3) / (-6);
    ans += b * (n - 0) * (n - 2) * (n - 3) / 2;
    ans += c * (n - 0) * (n - 1) * (n - 3) / (-2);
    ans += d * (n - 0) * (n - 1) * (n - 2) / 6;

    cout << ans << endl;


}