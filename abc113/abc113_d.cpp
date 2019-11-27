#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e10;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\01.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;

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
};

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    if (w == 1) {
        cout << 1 << endl;
        return 0;
    }

//    w = 3;
//    h = 3;

//    vector<int> bridge_patterns;
    vector<int> bridge_counts(w - 1, 0);
    vector<int> non_bridge_counts(w - 1, 0);
    vector<int> sayu_non_bridge_counts(w - 2, 0);
    for (int b = 0; b < (1 << (w - 1)); b++) {
        bool ok = [&] {
            for (int i = 0; i < (w - 1); i++) {
                int a = (b >> i);
                int c = a & 0b11;
                if (c == 0b11) {
                    return false;
                }
            }
            return true;
        }();
        if (ok) {
//            bridge_patterns.push_back(b);
            for (int i = 0; i < (w - 1); i++) {
                int a = b >> i;
                int c = a & 1;
                if (c == 1) {
                    bridge_counts[i]++;
                } else {
                    non_bridge_counts[i]++;
                }
            }

            for (int i = 0; i < (w - 2); i++) {
                int a = b >> i;
                int c = a & 0b11;
                if (c == 0) {
                    sayu_non_bridge_counts[i]++;
                }
            }

        }
    }

    vector<vector<mint>> dp(h + 1, vector<mint>(w, 0));
    dp[0][0] = 1;
    for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {

            mint current = dp[x][y];
            // 左下へ
            if (y != 0) {
                ll bc = bridge_counts[y - 1];
                mint before = dp[x + 1][y - 1];
                dp[x + 1][y - 1] = before + current * bc;
            }
            // 真下へ
            if (y == 0) {
                ll bc = non_bridge_counts[y];
                mint before = dp[x + 1][y];
                dp[x + 1][y] = before + current * bc;
            } else if (y == w - 1) {
                ll bc = non_bridge_counts[y - 1];
                mint before = dp[x + 1][y];
                dp[x + 1][y] = before + current * bc;
            } else {
                ll bc = sayu_non_bridge_counts[y - 1];
                mint before = dp[x + 1][y];
                dp[x + 1][y] = before + current * bc;
            }

            // 右下へ
            if (y != w - 1) {
                ll bc = bridge_counts[y];
                mint before = dp[x + 1][y + 1];
                dp[x + 1][y + 1] = before + current * bc;
            }
        }
    }
    cout << dp[h][k - 1].x << endl;

}

