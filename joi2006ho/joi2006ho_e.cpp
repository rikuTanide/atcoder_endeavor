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

class MatrixSum {
    vector<vector<ll>> sum;
public:
    MatrixSum(ll x, ll y) {
        sum = vector<vector<ll>>(x, vector<ll>(y));
    }

    void add(ll x, ll y, int v) {
        sum[x][y] += v;
    }

    ll get(ll x, ll y) {
        if (x == -1 || y == -1) {
            return 0;
        }
        if (x == sum.size() || y == sum[x].size()) {
            return 0;
        }
        return sum[x][y];
    }

    void setUp() {
        for (ll x = 0; x < sum.size(); x++) {
            for (ll y = 0; y < sum[x].size(); y++) {
                sum[x][y] += get(x - 1, y) + get(x, y - 1) - get(x - 1, y - 1);
            }
        }
    }

    ll getSum(ll xs, ll ys, ll xe, ll ye) {
        return get(xe, ye) - get(xs - 1, ye) - get(xe, ys - 1) + get(xs - 1, ys - 1);
    }

};

const int MAX = 10;

int main() {
    int n, r;
    cin >> n >> r;

    MatrixSum ms(MAX, MAX);

    rep(_, n) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        ms.add(sx, sy, 1);
        ms.add(ex, sy, -1);
        ms.add(sx, ey, -1);
        ms.add(ex, ey, 1);

    }

    ms.setUp();

    int s = 0;
    rep(x, MAX) {
        rep(y, MAX) {
            int c = ms.get(x, y);
            if (c > 0) s++;
        }
    }

    struct Direction {
        int y, x;
    };

    vector<Direction> directions = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0},
    };

    int e = 0;
    rep(x, MAX) {
        rep(y, MAX) {
            int c = ms.get(x, y);
            if (c == 0) continue;

            for (Direction d : directions) {
                int ny = y + d.y;
                int nx = x + d.x;

                int nc = ms.get(nx, ny);
                if (nc == 0) e++;
            }
        }
    }

    if (r == 1) {
        cout << s << endl;
    } else {
        cout << s << endl << e << endl;
    }

}
