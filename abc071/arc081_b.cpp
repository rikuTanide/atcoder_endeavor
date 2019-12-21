#include <bits/stdc++.h>
#include <cmath>


#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

class Board {
    vector<vector<char>> board;
    vector<vector<int>> variations;

public:
    Board(int n) {
        board = vector<vector<char>>(n, vector<char>(2));
        variations = vector<vector<int>>(n, vector<int>(2));
    }

    void set(int x, int y, char color) {
        board[x][y] = color;
    }

    void setVariation(int x, int y, int variation) {
        variations[x][y] = variation;
    }

    char get(int x, int y) {
        if (x == -1 || y == -1) {
            return '.';
        }
        if (x == board.size() || y == board[x].size()) {
            return '.';
        }
        return board[x][y];
    }

    bool isChild(int x, int y) {

        char c = get(x, y);
        char l = get(x - 1, y);
        char u = get(x, y - 1);

        return c == l || c == u;
    }

    bool isHorizontal(int x, int y) {
        assert(!isChild(x, y));
        return get(x, y) == get(x + 1, y);
    }

    bool isVertical(int x, int y) {
        assert(!isChild(x, y));
        return get(x, y) == get(x, y + 1);
    }


    bool isLeftHorizontal(int x, int y) {
        char lu = get(x - 1, y);
        char ld = get(x - 1, y + 1);
        return lu != ld;
    }

    int getVariation(int x, int y) {
        return variations[x][y];
    }
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
    int n;
    cin >> n;

    Board board(n);

    rep(i, 2) {
        rep(j, n) {
            char c;
            cin >> c;
            board.set(j, i, c);
        }
    }

    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < n; x++) {
            if (y == 0 && x == 0) {
                board.setVariation(x, y, 3);
            } else if (board.isChild(x, y)) {
                board.setVariation(x, y, 1);
            } else if (x == 0) {
                board.setVariation(x, y, 2);
            } else if (y == 0 && board.isHorizontal(x, y) && board.isLeftHorizontal(x, y)) {
                board.setVariation(x, y, 3);
            } else if (y == 0 && board.isHorizontal(x, y)) {
                board.setVariation(x, y, 2);
            } else if (y == 0 && board.isVertical(x, y) && board.isLeftHorizontal(x, y)) {
                board.setVariation(x, y, 1);
            } else if (y == 0 && board.isVertical(x, y)) {
                board.setVariation(x, y, 2);
            } else {
                board.setVariation(x, y, 1);
            }
        }
    }

    mint ans = 1;

    rep(y, 2) {
        rep(x, n) {
            ans *= board.getVariation(x, y);
        }
    }
    cout << ans.x << endl;

}