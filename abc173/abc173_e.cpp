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


int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    vector<ll> plus, minus;
    int zero = 0;

    for (ll l : v) {
        if (l > 0) plus.push_back(l);
        else if (l < 0) minus.push_back(l);
        else zero++;
    }

    sort(plus.rbegin(), plus.rend());
    sort(minus.rbegin(), minus.rend());

    if ((n - zero) < k) {
        cout << 0 << endl;
        ret();
    }

    // 必ずプラス
    int mim = max<ll>(k - plus.size(), 0);
    if ((n - mim) % 2 == 0 || (plus.size() > 0 && minus.size() - mim > 0)) {

        mint now = 1;
        if (k <= plus.size()) {
            rep(i, k) now *= plus[i];
            for (int i = 0; i * 2 < k; i++) {
                int p1 = k - i * 2 - 1;
                int p2 = k - i * 2 - 2;
                if (p2 < 0) {
                    break;
                }

                ll p = plus[p1] * plus[p2];

                int mi1 = minus.size() - i * 2 - 1;
                int mi2 = minus.size() - i * 2 - 2;
                if (mi2 < 0) {
                    break;
                }
                ll m = minus[mi1] * minus[mi2];

                if (m <= p) {
                    break;
                }

                now /= p;
                now *= m;
            }
            cout << now << endl;
            ret();

        }

    }
    if (zero > 0) {
        cout << 0 << endl;
        ret();
    }
    __throw_runtime_error("mada");


}
