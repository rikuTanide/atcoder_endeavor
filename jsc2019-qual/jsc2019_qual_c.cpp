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

class CumulativeSum {
    vector<ll> numbers;
    vector<ll> sums;

public:
    CumulativeSum(int n) {
        numbers.resize(n);
        sums.resize(n);
    }

    void set(int i, ll value) {
        numbers[i] = value;
    }

    ll getSum(int i) {
        if (i == -1) return 0;
        if (i == sums.size()) return sums.back();
        return sums[i];
    }

    ll getSectionSum(int start, int end) {
        return getSum(end) - getSum(start - 1);
    }

    void build() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};

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
//    ifstream cin("C:\\Users\\riku\\Downloads\\testcase_05");

    int n;
    string s;
    cin >> n >> s;

    if (s.front() != 'B' || s.back() != 'B') {
        cout << 0 << endl;
        ret();
    }

    auto turn = [&](char c) {
        if (c == 'L') return 'R';
        return 'L';
    };

    vector<char> m(2 * n);
    m[0] = 'L';
    rep(i, n * 2) {
        if (i == 0) continue;
        if (s[i] == s[i - 1]) m[i] = turn(m[i - 1]);
        else m[i] = m[i - 1];
    }

    if (count(m.begin(), m.end(), 'L') != n) {
        cout << 0 << endl;
        ret();
    }

    CumulativeSum cs_r(2 * n), cs_l(2 * n);
    rep(i, 2 * n) cs_r.set(i, m[i] == 'R' ? 1 : 0);
    rep(i, 2 * n) cs_l.set(i, m[i] == 'L' ? 1 : 0);
    cs_r.build();
    cs_l.build();

    vector<mint> dp(2 * n);
    rep(i, 2 * n) {
        if (m[i] != 'L') continue;
        ll l = cs_r.getSectionSum(i + 1, n * 2);
        ll r = cs_l.getSectionSum(i + 1, n * 2);
        assert(r <= l);

        ll now = l - r;

        dp[i] = now;
    }

    mint ans = 1;
    rep(i, 2 * n) {
        if (m[i] == 'L') ans *= dp[i];
    }

    for (int i = 1; i <= n; i++) ans *= i;
    cout << ans << endl;

}
