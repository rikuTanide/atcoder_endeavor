#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

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
    int h, w;
    cin >> h >> w;

    vector<vector<char>> g(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> g[y][x];

    mint ans = 0;
    rep(c, w - 1) {
        vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(303, vector<ll>(303, INF)));

        rep(i, 303) dp[0][0][i] = 0;
        rep(i, 303) dp[0][i][0] = 0;
        dp[1][0][0] = 0;

        rep(a, h) rep(b, h) {
                ll x = dp[0][a + 1][b + 1];
                ll y = dp[0][a][b] + (g[a][c] == g[b][c + 1]);
                dp[0][a + 1][b + 1] = min(x, y);
            }
        rep(i, h + 1) rep(j, h + 1) {
                ll x1 = dp[1][i + 1][j];
                ll x2 = dp[1][i][j] + dp[0][h - i][h - j];

                ll y1 = dp[1][i][j + 1];
                ll y2 = dp[1][i][j] + dp[0][h - i][h - j];

                dp[1][i + 1][j] = min(x1, x2);
                dp[1][i][j + 1] = min(y1, y2);
            }

        ans += dp[1][h][h];
    }

    cout << ans << endl;

}
