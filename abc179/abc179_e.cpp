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

bool contain(set<ll> &s, int a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;
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

void ans_from_loop(vector<ll> &as, ll n, ll x, ll m) {
    ll connect = as.back();
    assert(count(as.begin(), as.end(), connect) == 2);
    int start = distance(as.begin(), find(as.begin(), as.end(), connect));

    ll prefix_sum = accumulate(as.begin(), as.begin() + start, 0ll);
    ll suf_length = n - start;
    ll loop_size = as.size() - start - 1;
    ll loop_count = suf_length / loop_size;
    ll suffix_length = suf_length % loop_size;
    ll suffix_sum = accumulate(as.begin() + start, as.begin() + start + suffix_length, 0ll);
    ll loop_sum = accumulate(as.begin() + start, as.begin() + start + loop_size, 0ll);

    ll ans = prefix_sum + (loop_sum * loop_count) + suffix_sum;
    cout << ans << endl;

}

int main() {
    ll n, x, m;
    cin >> n >> x >> m;

    vector<ll> as;
    set<ll> used;
    used.insert(x);
    as.push_back(x);
    rep(i, n) {
        if (i == 0)continue;
        ll prev = as[i - 1];
        ll next = (prev * prev) % m;
        as.push_back(next);

        if (contain(used, next)) {
            ans_from_loop(as, n, x, m);
            ret();
        }
        used.insert(next);
    }

    ll ans = accumulate(as.begin(), as.end(), 0ll);
    cout << ans << endl;

//    for (int i : as) cout << i << ' ';

}
