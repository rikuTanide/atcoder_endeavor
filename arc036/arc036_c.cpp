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

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<vector<vector<mint>>> dp(n + 1, vector<vector<mint>>(k + 1, vector<mint>(k + 1)));
    dp[0][0][0] = 1;

    auto add = [&](int i, int x, int y, mint value) {
        if (x > k) return;
        if (x < 0) x = 0;
        if (y > k) return;
        if (y < 0) y = 0;

        dp[i][x][y] += value;

    };

    rep(i, n) {

        char c = s[i];

        for (int x = 0; x <= k; x++) {
            for (int y = 0; y <= k; y++) {
                if (c == '0') {
                    add(i + 1, x + 1, y - 1, dp[i][x][y]);
                } else if (c == '1') {
                    add(i + 1, x - 1, y + 1, dp[i][x][y]);
                } else {
                    add(i + 1, x + 1, y - 1, dp[i][x][y]);
                    add(i + 1, x - 1, y + 1, dp[i][x][y]);
                }
            }
        }

    }
    mint ans = 0;
    for (int x = 0; x <= k; x++) {
        for (int y = 0; y <= k; y++) {
            ans += dp.back()[x][y];
        }
    }


    cout << ans << endl;

}
