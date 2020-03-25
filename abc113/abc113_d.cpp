#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
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

#include <iostream>
#include <vector>

using namespace std;

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

bool is_adjoin(int n, int i) {
    for (int j = 0; j < n - 2; j++) {
        bool a = (i >> j) & 1;
        bool b = (i >> (j + 1)) & 1;
        if (a && b) return true;
    }
    return false;
}

vector<int> get_enable_bars(int n) {
    vector<int> ans;
    for (int i = 0; i < (1 << (n - 1)); i++) {
        if (is_adjoin(n, i)) {
            continue;
        }
        ans.push_back(i);
    }
    return ans;
}


int get_to_left(int x, vector<int> &enable_bars) {
    int ans = 0;
    for (int i : enable_bars) {
        bool b = (i >> (x - 1)) & 1;
        if (b) ans++;
    }
    return ans;
}

int get_to_down(int x, vector<int> &enable_bars) {
    int ans = 0;
    for (int i : enable_bars) {
        bool b = (i >> (x - 1)) & 1;
        bool c = (i >> x) & 1;
        assert(!(b && c));
        bool d = b || c;

        if (!d) ans++;
    }
    return ans;
}

int get_to_right(int x, vector<int> &enable_bars) {
    int ans = 0;
    for (int i : enable_bars) {
        bool b = (i >> x) & 1;
        if (b) ans++;
    }
    return ans;
}

int main() {
    ll h, w, k;
    cin >> h >> w >> k;
    vector<int> enable_bars = get_enable_bars(w);
    vector<vector<mint>> dp(h + 1, vector<mint>(w, 0));
    dp[0][0] = 1;
    rep(y, h) {
        rep(x, w) {
            if (x != 0) {
                ll to_left = get_to_left(x, enable_bars);
                dp[y + 1][x - 1] += dp[y][x] * to_left;
            }
            ll to_down = get_to_down(x, enable_bars);
            dp[y + 1][x] += dp[y][x] * to_down;
            if (x != w - 1) {
                ll to_right = get_to_right(x, enable_bars);
                dp[y + 1][x + 1] += dp[y][x] * to_right;
            }
        }
    }

    cout << dp.back()[k - 1] << endl;

}



