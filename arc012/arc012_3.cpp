#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
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

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Participant {
    double x, y, throw_limit, catch_limit;
};

std::istream &operator>>(std::istream &in, Participant &o) {
    cin >> o.x >> o.y >> o.throw_limit >> o.catch_limit;
    return in;
}

bool check5(vector<vector<char>> &goban) {

    struct Direction {
        int x, y;
    };

    vector<Direction> directions = {
            {0,  -1},
            {-1, 0},
            {-1, -1},
            {1,  -1},
    };
    for (Direction d : directions) {
        vector<vector<int>> dp(19, vector<int>(19, 0));
        rep(y, 19) rep (x, 19) {
                if (goban[y][x] == '.') continue;
                int by = y + d.y, bx = x + d.x;
                if (by == -1 || bx == -1 || bx == 19) continue;
                if (goban[y][x] != goban[by][bx]) dp[y][x] = 1;
                else dp[y][x] = dp[by][bx] + 1;
            }
        int ans = 0;
        rep(y, 19) rep (x, 19) cmax(ans, dp[y][x]);
        if (ans >= 5) return false;
    }

    return true;
}

int main() {
    vector<vector<char>> goban(19, vector<char>(19, ' '));
    rep(y, 19) rep (x, 19) cin >> goban[y][x];

    auto color_count = [&](char c) {
        int i = 0;
        rep(y, 19) rep (x, 19) if (goban[y][x] == c) i++;
        return i;
    };

    int b_count = color_count('o'),
            w_count = color_count('x');

    auto check = [&](char c) {
        if (check5(goban)) return true;
        rep(y, 19) rep (x, 19) {
                if (goban[y][x] != c) continue;
                vector<vector<char>> tmp_goban = goban;
                tmp_goban[y][x] = '.';
                if (check5(tmp_goban)) {
                    return true;
                }
            }
        return false;
    };


    bool solve = [&] {
        if (b_count == w_count) return check('x');
        else if (b_count == w_count + 1) return check('o');
        return false;
    }();

    if (solve) {
        cout << "YES" << endl;
    } else {
        __throw_runtime_error("error");
    }
}

