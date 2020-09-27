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

int main() {
    int n;
    cin >> n;

    vector<int> ps(n * n);
    rep(i, n * n) cin >> ps[i], ps[i]--;

    vector<vector<int>> theater(n, vector<int>(n));
    vector<vector<bool>> exists(n, vector<bool>(n, true));

    rep(y, n) {
        rep(x, n) {
            theater[y][x] = min({y, n - 1 - y, x, n - 1 - x});
        }
    }


    auto update = [&](int ys, int xs) {
        queue<P> q;
        q.push({ys, xs});

        struct Direction {
            int y, x;
        };

        vector<Direction> directions = {
                {0,  1},
                {1,  0},
                {0,  -1},
                {-1, 0},
        };
        auto reachable = [&](int y, int x) {
            if (x == -1 || x == n || y == -1 || y == n) return false;
            return true;
        };
        while (!q.empty()) {
            P p = q.front();
            int y = p.first;
            int x = p.second;
            q.pop();
            for (Direction d : directions) {
                int nx = x + d.x;
                int ny = y + d.y;
                if (!reachable(ny, nx)) {
                    continue;
                }

                if (theater[ny][nx] > theater[y][x] + exists[y][x]) {
                    theater[ny][nx] = theater[y][x] + exists[y][x];
                    q.push({ny, nx});
                }
            }

        }
    };

    ll ans = 0;
    for (ll p : ps) {
        int y = p / n;
        int x = p % n;

        ans += theater[y][x];
        exists[y][x] = false;
        update(y, x);
    }

    cout << ans << endl;

}
