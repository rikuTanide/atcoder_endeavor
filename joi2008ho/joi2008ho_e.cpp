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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

class Conv {
    ll cursor = 0;
    map<ll, ll> to_short; // <original, small >
    map<ll, ll> to_long; // <small, original>
    std::set<ll> tmp;


public:
    void set(ll original) {
        if (to_short.find(original) != to_short.end()) {
            return;
        }
        to_long[cursor] = original;
        to_short[original] = cursor;
        cursor++;
    }

    ll revert(ll after) {
        assert(to_long.find(after) != to_long.end());
        return to_long[after];
    }

    ll convert(ll original) {
        assert(to_short.find(original) != to_short.end());
        return to_short[original];
    }

    ll next() {
        return cursor;
    }

    // 前計算省略のため
    void cache(ll t) {
        tmp.insert(t);
    }

    void build() {
        for (ll t : tmp) {
            set(t);
        }
    }

};


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

struct Tape {
    ll x1, y1, x2, y2;
};

class MatrixSum {
    vector<vector<int>> sum;
public:
    MatrixSum(int x, int y) {
        sum = vector<vector<int>>(x, vector<int>(y));
    }

    void add(int x, int y, int value) {
        if (x >= sum.size()) return;
        if (y >= sum[x].size()) return;
        sum[x][y] += value;
    }

    int get(int x, int y) {
        if (x == -1 || y == -1) {
            return 0;
        }
        if (x == sum.size() || y == sum[x].size()) {
            return 0;
        }
        return sum[x][y];
    }

    void setUp() {
        for (int x = 0; x < sum.size(); x++) {
            for (int y = 0; y < sum[x].size(); y++) {
                sum[x][y] += get(x - 1, y) + get(x, y - 1) - get(x - 1, y - 1);
            }
        }
    }

    int getSum(int xs, int ys, int xe, int ye) {
        return get(xe, ye) - get(xs - 1, ye) - get(xe, ys - 1) + get(xs - 1, ys - 1);
    }

};

ll solve(ll h, ll w, vector<Tape> &tapes) {
    // TLEしたらIMOSする
    MatrixSum ms(h, w);
    for (Tape t : tapes) {
        ms.add(t.y1, t.x1, 1);
        ms.add(t.y1, t.x2 + 1, -1);
        ms.add(t.y2 + 1, t.x1, -1);
        ms.add(t.y2 + 1, t.x2 + 1, 1);
    }
    ms.setUp();

//    vector<vector<char>> board(h, vector<char>(w, '-'));
//    rep(y, h) {
//        rep(x, w) {
//            board[y][x] = ms.get(y, x) > 0 ? '#' : '-';
//        }
//    }

    struct Direction {
        int y, x;
    };

    vector<Direction> directions = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0},
    };

    UnionFind uf(h * w);

    auto to_id = [&](int y, int x) {
        return y * w + x;
    };
    auto is_plane = [&](int y, int x) -> bool {
        if (x == -1 || x == w || y == -1 || y == h) return false;
        if (ms.get(y, x) > 0) {
            return false;
        }
        return true;
    };


    rep(y, h) {
        rep(x, w) {
            if (ms.get(y, x) > 0) continue;
            for (Direction d : directions) {
                ll ny = y + d.y;
                ll nx = x + d.x;

                if (is_plane(ny, nx)) {
                    uf.connect(to_id(y, x), to_id(ny, nx));
                }

            }

        }
    }
    /*
    for (int y = h - 1; y >= 0; y--) {
        rep(x, w) {
            cout << board[y][x];
        }
        cout << endl;
    }
*/

    int ans = 0;
    rep(y, h) {
        rep(x, w) {
            if ( ms.get(y, x) > 0) continue;
            if (uf.root(to_id(y, x)) == to_id(y, x)) ans++;
        }
    }
    return ans;
}

int main() {
    ll w, h;
    int n;
    cin >> w >> h >> n;

    vector<Tape> tapes(n);
    for (Tape &tape: tapes)
        cin >> tape.x1 >> tape.y1 >> tape.x2 >> tape.y2,
                tape.x2--,
                tape.y2--;

    Conv horizon_conv, vertical_conv;
    for (Tape t : tapes) {
        ll s = max<ll>(0, t.y1 - 1);
        ll e = min<ll>(h - 1, t.y1 + 1);
        for (int y = s; y <= e; y++) {
            vertical_conv.cache(y);
        }
    }
    for (Tape t : tapes) {
        ll s = max<ll>(0, t.y2 - 1);
        ll e = min<ll>(h - 1, t.y2 + 1);
        for (int y = s; y <= e; y++) {
            vertical_conv.cache(y);
        }
    }
    for (Tape t : tapes) {
        ll s = max<ll>(0, t.x1 - 1);
        ll e = min<ll>(w - 1, t.x1 + 1);
        for (int x = s; x <= e; x++) {
            horizon_conv.cache(x);
        }
    }
    for (Tape t : tapes) {
        ll s = max<ll>(0, t.x2 - 1);
        ll e = min<ll>(w - 1, t.x2 + 1);
        for (int x = s; x <= e; x++) {
            horizon_conv.cache(x);
        }
    }
    horizon_conv.build();
    vertical_conv.build();

    for (Tape &t: tapes) t.x1 = horizon_conv.convert(t.x1);
    for (Tape &t: tapes) t.x2 = horizon_conv.convert(t.x2);
    for (Tape &t: tapes) t.y1 = vertical_conv.convert(t.y1);
    for (Tape &t: tapes) t.y2 = vertical_conv.convert(t.y2);


    cout << solve(vertical_conv.next(), horizon_conv.next(), tapes) << endl;

}
