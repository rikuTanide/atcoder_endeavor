#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<unsigned long long , unsigned long long > P;
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


ll rec(ll cost2, ll cost3, ll cost5, ll cost1, ll now_value, map<ll, ll> &cache) {
    if (now_value == 0) return 0;
    if (now_value == 1) return cost1;

    if (cache.find(now_value) != cache.end()) return cache[now_value];

    vector<P> ps;

    for (P f : {P(2, cost2), P(3, cost3), P(5, cost5)}) {
        if (now_value % f.first == 0) {

            ll next_value = now_value / f.first;
            ll next_cost = f.second;
            ps.emplace_back(next_value, next_cost);

        } else {
            ll ta = now_value / f.first * f.first;
            ll tb = (now_value + f.first - 1) / f.first * f.first;

            for (ll t : {ta, tb}) {
                ll diff = t > now_value ? t - now_value : now_value - t;// abs(now_value - t);
                ll next_value = t / f.first;
                ll next_cost = (diff * cost1) + f.second;

                ps.emplace_back(next_value, next_cost);

            }
        }

    }

    ll ans = cost1 * now_value;
    for (P p : ps) {
        ll now = rec(cost2, cost3, cost5, cost1, p.first, cache);
        cmin(ans, now + p.second);

    }

    if (ans < 0) {
        cout << endl;
    }

    cache[now_value] = ans;
    return ans;

}

int main() {

    int t;
    cin >> t;

    rep(_, t) {
        ll n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        map<ll, ll> cache;
        ll ans = rec(a, b, c, d, n, cache);
        cout << ans << endl;
    }


}
