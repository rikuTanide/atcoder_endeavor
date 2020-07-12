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

bool check(int w, int i) {
    rep(j, w - 2) {
        bool f = (i >> j) & 1;
        bool g = (i >> (j + 1)) & 1;

        if (f && g) return false;
    }
    return true;
};

vector<mint> get_h_dp(int w) {

    vector<mint> ans(w - 1, 0);


    rep(i, 1 << (w - 1)) {

        bool ok = check(w, i);
        if (!ok) continue;

        rep(j, w - 1) {
            if (!((i >> j) & 1)) continue;
            ans[j] = ans[j] + 1;
        }
    }

    return ans;
}

vector<mint> get_h_dp_e(int w, vector<mint> hdp) {
    mint all = 0;

    rep(i, 1 << (w - 1)) {
        bool ok = check(w, i);
        if (!ok) continue;
        all = all + 1;
    }


    vector<mint> ans(w, all);
    rep(i, w) {
        if (i < w - 1) {
            ans[i] -= hdp[i];
        }
        if (0 < i) {
            ans[i] -= hdp[i - 1];
        }
    }

    return ans;

}

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<mint> hdp = get_h_dp(w);
    vector<mint> hdp_e = get_h_dp_e(w, hdp);

    vector<vector<mint>> dp(h + 1, vector<mint>(w));
    dp[0][0] = 1;

    rep(i, h) {
        rep(j, w) {
            if (j < w - 1) {
                dp[i + 1][j + 1] += (dp[i][j] * hdp[j]);
            }
            dp[i + 1][j] += (dp[i][j] * hdp_e[j]);
            if (0 < j) {
                dp[i + 1][j - 1] += (dp[i][j] * hdp[j - 1]);
            }
        }
    }

    cout << dp[h][k - 1] << endl;

}
