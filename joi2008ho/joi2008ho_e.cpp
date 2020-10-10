#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<unsigned short, unsigned short> P;
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
    int cursor = 0;
    map<int, int> to_short; // <original, small >
    map<int, int> to_long; // <small, original>
    std::set<int> tmp;


public:
    void set(int original) {
        if (to_short.find(original) != to_short.end()) {
            return;
        }
        to_long[cursor] = original;
        to_short[original] = cursor;
        cursor++;
    }

    int revert(int after) {
        assert(to_long.find(after) != to_long.end());
        return to_long[after];
    }

    int convert(int original) {
        assert(to_short.find(original) != to_short.end());
        return to_short[original];
    }

    int next() {
        return cursor;
    }

    // 前計算省略のため
    void cache(int t) {
        tmp.insert(t);
    }

    void build() {
        for (int t : tmp) {
            set(t);
        }
    }

};


struct Tape {
    int x1, y1, x2, y2;
};

class MatrixSum {
    vector<vector<unsigned char>> sum;
public:
    MatrixSum(int x, int y) {
        sum = vector<vector<unsigned char>>(x, vector<unsigned char>(y));
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

    vector<vector<char>> board(h, vector<char>(w, '-'));
    rep(y, h) {
        rep(x, w) {
            if (ms.get(y, x) > 0)board[y][x] = '#';
        }
    }

    auto is_plane = [&](int y, int x) -> bool {
        if (x == -1 || x == w || y == -1 || y == h) return false;
        if (board[y][x] == '#') {
            return false;
        }
        return true;
    };

    int ans = 0;

    rep(y, h) {
        rep(x, w) {
            if (board[y][x] == '#') continue;
            ans++;
            board[y][x] = '#';
            queue<P> q;
            q.push({y, x});
            while (!q.empty()) {
                P p = q.front();
                q.pop();
                for (Direction d : directions) {
                    ll ny = p.first + d.y;
                    ll nx = p.second + d.x;
                    if (is_plane(ny, nx)) {
                        board[ny][nx] = '#';
                        q.push({ny, nx});
                    }
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

    return ans;
}


Conv make_horizontal_conv(vector<Tape> &tapes, ll w) {
    Conv horizon_conv;

//    for (Tape t : tapes) {
//        horizon_conv.cache(t.x1);
//        horizon_conv.cache(t.x2);
//    }
//
//
    for (Tape t : tapes) {
        ll s = max<ll>(0, t.x1 - 1);
        ll e = min<ll>(w - 1, t.x1);
        for (int x = s; x <= e; x++) {
            horizon_conv.cache(x);
        }
    }
    for (Tape t : tapes) {
        ll s = max<ll>(0, t.x2);
        ll e = min<ll>(w - 1, t.x2 + 1);
        for (int x = s; x <= e; x++) {
            horizon_conv.cache(x);
        }
    }
    horizon_conv.build();
    return horizon_conv;
}

Conv make_vertical_conv(vector<Tape> &tapes, ll h) {
    Conv vertical_conv;
    for (Tape t : tapes) {
        ll s = max<ll>(0, t.y1 - 1);
        ll e = min<ll>(h - 1, t.y1);
        for (int y = s; y <= e; y++) {
            vertical_conv.cache(y);
        }
    }
    for (Tape t : tapes) {
        ll s = max<ll>(0, t.y2);
        ll e = min<ll>(h - 1, t.y2 + 1);
        for (int y = s; y <= e; y++) {
            vertical_conv.cache(y);
        }
    }
    vertical_conv.build();
    return vertical_conv;
}

P calc_size(vector<Tape> &tapes, ll h, ll w) {

    Conv vertical_conv = make_vertical_conv(tapes, h);
    Conv horizon_conv = make_horizontal_conv(tapes, w);

    int nh = vertical_conv.next();
    int nw = horizon_conv.next();

    return P(nh, nw);
}

vector<Tape> convert(vector<Tape> tapes, ll h, ll w) {

    Conv vertical_conv = make_vertical_conv(tapes, h);
    Conv horizon_conv = make_horizontal_conv(tapes, w);
    for (Tape &t: tapes) t.x1 = horizon_conv.convert(t.x1);
    for (Tape &t: tapes) t.x2 = horizon_conv.convert(t.x2);
    for (Tape &t: tapes) t.y1 = vertical_conv.convert(t.y1);
    for (Tape &t: tapes) t.y2 = vertical_conv.convert(t.y2);

    return tapes;
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

    P size = calc_size(tapes, h, w);
    tapes = convert(tapes, h, w);

    cout << solve(size.first, size.second, tapes) << endl;

}
