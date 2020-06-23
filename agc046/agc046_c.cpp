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
const int mod =998244353
        ;

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

vector<int> split(string s) {

    int n = s.size();
    vector<int> c = {0};
    rep(i, n) {
        if (s[i] == '0') c.push_back(0);
        else c.back()++;
    }
    return c;
}

int main() {
    string s;
    ll _k;
    cin >> s >> _k;
    int os = count(s.begin(), s.end(), '1');
    int k = min<ll>(os, _k);


    vector<int> ones = split(s);
    int n = ones.size();

    vector<int> sums = ones;
    rep(i, n - 1) {
        sums[i + 1] += sums[i];
    }

    vector<vector<vector<mint>>> dp(n + 1, vector<vector<mint>>(k + 1, vector<mint>(os + 1, 0)));
    dp[0][0][0] = 1;
    rep(i, n) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= os; l++) {

                mint from = dp[i][j][l];
                for (int o = 0; o <= os; o++) {
                    if (o <= ones[i]) {
                        // g個左にあげる
                        int g = ones[i] - o;
                        if (sums[i] > l + o) continue;
                        if (l + o <= os) dp[i + 1][j][l + o] += from;
                    } else {
                        // g個右からもらう
                        int g = o - ones[i];
                        if (j + g <= k && l + ones[i] + g <= os) dp[i + 1][j + g][l + ones[i] + g] += from;
                    }
                }
            }
        }
    }
//
//    rep(i, n + 1) {
//
//        rep(j, k + 1) {
//            rep(l, os + 1) {
//                cout << dp[i][j][l] << ' ';
//            }
//            cout << endl;
//        }
//
//        cout << endl;
//    }

    mint ans = 0;
    rep(j, k + 1) ans += dp[n][j][os];
    cout << ans << endl;

}
