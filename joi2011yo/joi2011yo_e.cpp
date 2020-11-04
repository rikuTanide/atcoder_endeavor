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

int main() {
    int n, h, w;
    cin >> h >> w >> n;

    vector<vector<char>> board(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> board[y][x];

    auto to_id = [&](int y, int x) {
        return y * w + x;
    };

    vector<int> points = [&]() -> vector<int> {
        vector<int> res;

        rep(y, h) {
            rep(x, w) {
                char c = board[y][x];
                if ('1' <= c && c <= '9') res.push_back(to_id(y, x));
            }
        }
        assert(res.size() == n);
        return res;

    }();


    vector<int> hard = [&]() -> vector<int> {
        vector<int> res(n);
        rep(i, n) {
            int y = points[i] / w;
            int x = points[i] % w;
            char c = board[y][x];
            assert('1' <= c && c <= '9');
            res[i] = c - '0';
        }
        return res;
    }();

    auto find = [&](char target) -> int {
        rep(y, h) {
            rep(x, w) {
                char c = board[y][x];
                if (c == target) return to_id(y, x);
            }
        }
        throw_with_nested("konaide");
    };

    auto calc_distances = [&](int start) -> vector<int> {
        vector<vector<int>> distances(h, vector<int>(w, INT_MAX / 10));

        distances[start / w][start % w] = 0;
        struct Point {
            ll y, x, cost;
        };

        queue<Point> q;
        q.push({start / w, start % w, 0});

        struct Direction {
            int y, x;
        };

        vector<Direction> directions = {
                {0,  1},
                {1,  0},
                {0,  -1},
                {-1, 0},
        };


        auto reachable = [&](int y, int x, int distance) {
            if (x == -1 || x == w || y == -1 || y == h) return false;
            if (board[y][x] == 'X') {
                return false;
            }
            if (distances[y][x] <= distance) {
                return false;
            }
            return true;
        };


        while (!q.empty()) {
            Point p = q.front();
            q.pop();
            for (Direction d : directions) {
                int nx = p.x + d.x;
                int ny = p.y + d.y;
                int nd = p.cost + 1;
                if (reachable(ny, nx, nd)) {
                    distances[ny][nx] = nd;
                    q.push({ny, nx, nd});
                }
            }
        }

        vector<int> ans(n);
        rep(i, n) {
            int point = points[i];
            int y = point / w;
            int x = point % w;

            int dis = distances[y][x];
            ans[i] = dis;
        }
        return ans;

    };

    vector<int> start_point_distance = calc_distances(find('S'));
    vector<vector<int>> point_point_distance(n);
    rep(i, n) point_point_distance[i] = calc_distances(points[i]);


    vector<int> arr(n);
    rep(i, n)arr[i] = i;
    ll ans = INF;
    do {
        bool ok = [&] {
            rep(i, n) {
                if ((hard[arr[i]] > i + 1)) {
                    return false;
                }
            }
            return true;
        }();
        if (!ok)continue;

        ll sum = start_point_distance[arr.front()];
        rep(i, n - 1) {
            ll now = point_point_distance[arr[i]][arr[i + 1]];
            sum += now;
        }
        cmin(ans, sum);
    } while (std::next_permutation(arr.begin(), arr.end()));
    cout << ans << endl;
}
