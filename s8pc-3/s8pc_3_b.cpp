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

void down(int h, int w, vector<vector<char>> &board, int fy, int fx) {
    for (int y = fy; y >= 1; y--) {
        board[y][fx] = board[y - 1][fx];
    }
    board[0][fx] = ' ';
}

class UnionFind {
public:
    // 親の番号を格納する。親だった場合-size
    vector<int> parents;

    UnionFind(int n) {
        parents = vector<int>(n, -1);
    }

    // aがどのグループに属しているか
    int root(int a) {
        if (parents[a] < 0) {
            return a;
        }
        return parents[a] = root(parents[a]);
    }

    int size(int a) {
        return -parents[root(a)];
    }

    // aとbをくっつける
    bool connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra == rb) {
            return false;
        }
        // 大きいほうにA
        if (size(ra) < size(rb)) {
            swap(ra, rb);
        }
        parents[ra] += parents[rb];
        parents[rb] = ra;
        return true;
    }

    bool is_union(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        return ra == rb;
    }
};

bool has_set(int h, int w, int k, vector<vector<char>> &board) {
    UnionFind uf(h * w);
    auto to_id = [&](int y, int x) {
        return y * w + x;
    };
    rep(y, h) {
        rep(x, w - 1) {
            if (board[y][x] == ' ') continue;
            if (board[y][x] == board[y][x + 1]) uf.connect(to_id(y, x), to_id(y, x + 1));
        }
    }
    rep(y, h) {
        rep(x, w) {
            if (uf.size(to_id(y, x)) >= k) return true;
        }
    }
    return false;
}

ll down_all(int h, int w, int k, vector<vector<char>> &board) {
    UnionFind uf(h * w);
    auto to_id = [&](int y, int x) {
        return y * w + x;
    };
    rep(y, h) {
        rep(x, w - 1) {
            if (board[y][x] == ' ') continue;
            if (board[y][x] == board[y][x + 1]) uf.connect(to_id(y, x), to_id(y, x + 1));
        }
    }
    ll ans = 0;
    rep(y, h) {
        rep(x, w) {
            if (uf.size(to_id(y, x)) >= k) {
                int ci = board[y][x] - '0';
                ans += ci;
                down(h, w, board, y, x);
            }
        }
    }
    return ans;
}

ll check(int h, int w, int k, vector<vector<char>> board, int fy, int fx) {

//    if (fy == 3 && fx == 2) {
//        cout << endl;
//    }

    down(h, w, board, fy, fx);
    ll ans = 0;
    for (int i = 0; has_set(h, w, k, board); i++) {
        ll t = down_all(h, w, k, board);
        ll now = (1ll << i) * t;
        ans += now;
    }
//    cout << ans << endl;
    return ans;
}

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> board(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> board[y][x];

    ll ans = 0;
    rep(y, h) rep(x, w) cmax(ans, check(h, w, k, board, y, x));
    cout << ans << endl;
}
