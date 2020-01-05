#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct Cell {
    int x, y;
    ll value;
};

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
    int h, w;
    cin >> h >> w;

    vector<Cell> board(h * w);
    rep(y, h) {
        rep(x, w) {
            ll a;
            cin >> a;
            board[y * w + x].x = x;
            board[y * w + x].y = y;
            board[y * w + x].value = a;
        }
    }

    sort(board.begin(), board.end(), [](Cell &c, Cell &d) {
        return c.value > d.value;
    });

    vector<vector<int>> ref(h, vector<int>(w, 0));
    rep(i, h * w) {
        ref[board[i].y][board[i].x] = i;
    }

    vector<mint> scores(h * w, 1);

    rep(i, h * w) {

        auto f = [&](int y, int x, int value) {
            if (y == -1) return;
            if (y == h) return;
            if (x == -1) return;
            if (x == w) return;

            int index = ref[y][x];
            if (board[index].value <= value) return;
            scores[i] += scores[index];
        };

        Cell &cell = board[i];
        int y = cell.y;
        int x = cell.x;
        int v = cell.value;

        f(y - 1, x, v);
        f(y + 1, x, v);
        f(y, x - 1, v);
        f(y, x + 1, v);

    }

    mint ans = 0;
    for (mint a : scores) {
        ans += a;
    }

    cout << ans.x << endl;

}