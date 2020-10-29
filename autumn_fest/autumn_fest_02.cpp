#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

template<class T>
std::istream &operator>>(std::istream &in, set<T> &o) {
    T a;
    in >> a;
    o.insert(a);
    return in;
}

template<class T>
std::istream &operator>>(std::istream &in, queue<T> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


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

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> board(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> board[y][x];

    auto to_id = [&](int y, int x) -> int {
        return y * w + x;
    };

    UnionFind uf(h * w);

    for (int y = 0; y < h - 2; y++) {
        for (int x = 0; x < w; x++) {
            int a = board[y][x];
            int b = board[y + 1][x];
            int c = board[y + 2][x];

            int p = to_id(y, x);
            int q = to_id(y + 1, x);
            int r = to_id(y + 2, x);


            if (a == b && b == c) {
                uf.connect(p, q);
                uf.connect(q, r);
            }
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w - 2; x++) {
            char a = board[y][x];
            char b = board[y][x + 1];
            char c = board[y][x + 2];

            int p = to_id(y, x);
            int q = to_id(y, x + 1);
            int r = to_id(y, x + 2);

            if (a == b && b == c) {
                uf.connect(p, q);
                uf.connect(q, r);
            }
        }
    }

    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w; x++) {

            char a = board[y][x];
            char b = board[y + 1][x];
            if (a != b)continue;

            int p = to_id(y, x);
            int q = to_id(y + 1, x);

            int s = uf.size(p);
            int t = uf.size(q);

            if (s >= 3 && t >= 3) {
                uf.connect(p, q);
            }
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w - 1; x++) {
            char a = board[y][x];
            char b = board[y][x + 1];
            if (a != b)continue;

            int p = to_id(y, x);
            int q = to_id(y, x + 1);

            int s = uf.size(p);
            int t = uf.size(q);

            if (s >= 3 && t >= 3) {
                uf.connect(p, q);
            }
        }
    }
    int ans = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int p = to_id(y, x);
            if (p == uf.root(p) && uf.size(p) >= 3) ans++;
        }
    }
    cout << ans << endl;
}
