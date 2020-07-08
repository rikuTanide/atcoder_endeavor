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

mint rec(int y, int x, int h, int w,
         vector<vector<int>> &grid,
         vector<vector<mint>> &memo,
         vector<vector<bool>> &has) {

    if (has[y][x]) return memo[y][x];

    struct Direction {
        int y, x;
    };
    vector<Direction> directions = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0},
    };


    auto reachable = [&](int y, int x, int now) {
        if (x == -1 || x == w || y == -1 || y == h) return false;
        if (grid[y][x] >= now) {
            return false;
        }
        return true;
    };

    mint ans = 1;
    for (Direction d : directions) {
        int ny = y + d.y;
        int nx = x + d.x;
        if (!reachable(ny, nx, grid[y][x])) continue;
        ans += rec(ny, nx, h, w, grid, memo, has);
    }

    has[y][x] = true;
    return memo[y][x] = ans;
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> grid(h, vector<int>(w));
    rep(y, h)rep(x, w)cin >> grid[y][x];


    vector<vector<mint>> memo(h, vector<mint>(w, 0));
    vector<vector<bool>> has(h, vector<bool>(w, false));

    rep(y, h) rep(x, w) {
            memo[y][x] = rec(y, x, h, w, grid, memo, has);
        }

    mint ans = 0;
    rep(y, h) rep(x, w) ans += memo[y][x];
    cout << ans << endl;

}
