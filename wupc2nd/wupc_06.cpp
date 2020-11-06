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
const ll INF = 200 * 100 * 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

bool equal(double a, double b) {
//    return fabs(a - b) < DBL_EPSILON;
    return fabs(a - b) < EPS;
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

template<class T, class F>
struct SegmentTree {
    F f;
    T ti;
    vector<T> dat;
    int sz;

    SegmentTree(const F &f, const T &ti) : f(f), ti(ti) {}

    void build(const vector<T> &v) {
        assert(v.size());
        sz = 1;
        while (sz < v.size())sz <<= 1;
        dat.resize(sz << 1, ti);
        for (int i = 0; i < v.size(); i++)dat[sz - 1 + i] = v[i];
        for (int i = sz - 2; i >= 0; i--)dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
    }

    inline void update(int k, T x) {
        k += sz - 1;
        dat[k] = x;
        while (k) {
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    inline void add(int k, int x) {
        k += sz - 1;
        dat[k] = f(dat[k], x);
        while (k) {
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    inline T query(int a, int b) {
        return query(a, b, 0, 0, sz);
    }

    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)return ti;
        if (a <= l && r <= b)return dat[k];
        return f(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};

int main() {
    int h, w, l;
    string s;
    cin >> h >> w >> l >> s;

    vector<vector<char>> board(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> board[y][x];

    auto mi = [](ll i, ll j) { return min(i, j); };
    auto ma = [](ll i, ll j) { return max(i, j); };


    vector<vector<SegmentTree<int, decltype(mi)>>>
            v_mins(26,
                   vector<SegmentTree<int, decltype(mi)>>(w,
                                                          SegmentTree<int, decltype(mi)>(mi, INF)));
    vector<vector<SegmentTree<int, decltype(ma)>>>
            v_maxs(26,
                   vector<SegmentTree<int, decltype(ma)>>(w,
                                                          SegmentTree<int, decltype(ma)>(ma, -1)));
    vector<vector<SegmentTree<int, decltype(mi)>>>
            h_mins(26,
                   vector<SegmentTree<int, decltype(mi)>>(h,
                                                          SegmentTree<int, decltype(mi)>(mi, INF)));
    vector<vector<SegmentTree<int, decltype(ma)>>>
            h_maxs(26,
                   vector<SegmentTree<int, decltype(ma)>>(h,
                                                          SegmentTree<int, decltype(ma)>(ma, -1)));


    {
        rep(ci, 26) {
            rep(y, h) {
                h_mins[ci][y].build(vector<int>(w, INF));
                h_maxs[ci][y].build(vector<int>(w, -1));
            }
            rep(x, w) {
                v_mins[ci][x].build(vector<int>(h, INF));
                v_maxs[ci][x].build(vector<int>(h, -1));
            }
        }

        rep(y, h) {
            rep(x, w) {
                char c = board[y][x];
                int ci = c - 'a';
                h_mins[ci][y].add(x, x);
                h_maxs[ci][y].add(x, x);
                v_mins[ci][x].add(y, y);
                v_maxs[ci][x].add(y, y);
            }
        }
    }


    vector<vector<vector<int>>> prev(4, vector<vector<int>>(h, vector<int>(w, INF)));

    rep(y, h) {
        rep(x, w) {
            if (s.front() == board[y][x]) {
                rep(i, 4) prev[i][y][x] = 1;
            }
        }
    }

    struct NextPoint {
        int y, x, cost;
    };

    auto distance = [&](int y, int x, int o, char c) -> NextPoint {
        int ci = c - 'a';
        if (o == 0) {
            // 上
            int next_y = v_maxs[ci][x].query(0, y);
            if (next_y == -1) return {0, 0, INF};
            return {next_y, x, abs(y - next_y)};
        }

        if (o == 1) {
            // 下
            int next_y = v_mins[ci][x].query(y + 1, h);
            if (next_y == INF) return {0, 0, INF};
            return {next_y, x, abs(y - next_y)};
        }

        if (o == 2) {
            // 右
            int next_x = h_mins[ci][y].query(x + 1, w);
            if (next_x == INF) return {0, 0, INF};
            return {y, next_x, abs(x - next_x)};
        }

        if (o == 3) {
            // 左
            int next_x = h_maxs[ci][y].query(0, x);
            if (next_x == -1) return {0, 0, INF};
            return {y, next_x, abs(x - next_x)};
        }

        throw_with_nested("nai");
    };


    rep(i, l) {
        if (i == 0)continue;
        vector<vector<vector<int>>> next(4, vector<vector<int>>(h, vector<int>(w, INF)));

        rep(y, h) {
            rep(x, w) {
                rep(now_o, 4) {
                    if (prev[now_o][y][x] == INF) continue;
                    rep(next_o, 4) {
                        if (now_o == next_o) continue;
                        NextPoint next_point = distance(y, x, next_o, s[i]);
                        if (next_point.cost == INF) continue;
                        int from = prev[now_o][y][x];
                        int to = from + next_point.cost;
                        cmin(next[next_o][next_point.y][next_point.x], to);
                    }
                }
            }
        }
        prev = next;
    }

    int ans = INF;
    rep(y, h) {
        rep(x, w) {
            rep(o, 4)cmin(ans, prev[o][y][x]);
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;


}
