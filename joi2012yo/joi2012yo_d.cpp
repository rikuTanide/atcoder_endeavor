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

const int mod = 10000;

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
    vector<vector<mint>> prev(3, vector<mint>(3, 0));

    vector<int> def(n, -1);
    rep(i, k) {
        int day, source;
        cin >> day >> source;
        day--;
        source--;

        def[day] = source;
    }

    rep(day1_source, 3) {
        rep(day2_source, 3) {
            if (def[0] != -1 && day1_source != def[0]) continue;
            if (def[1] != -1 && day2_source != def[1]) continue;
            prev[day1_source][day2_source] = 1;
        }
    }

    for (int i = 2; i < n; i++) {
        vector<vector<mint>> next(3, vector<mint>(3, 0));
        rep(yesterday2_source, 3) {
            rep(yesterday1_source, 3) {
                rep(today_source, 3) {
                    if (yesterday1_source == yesterday2_source && yesterday2_source == today_source)continue;
                    if (def[i] != -1 && def[i] != today_source) continue;
                    next[yesterday1_source][today_source] += prev[yesterday2_source][yesterday1_source];
                }
            }
        }
        prev = next;
    }
    mint ans = 0;
    rep(i, 3)rep(j, 3)ans += prev[i][j];
    cout << ans << endl;

}
