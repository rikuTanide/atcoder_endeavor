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

void print(vector<vector<char>> &cakes) {
    int h = cakes.size();
    int w = cakes[0].size();
    rep(y, h) {
        rep(x, w) cout << cakes[y][x];
        cout << endl;
    }
    cout << endl;
}

vector<vector<char>> rotate(vector<vector<char>> &cakes) {
    int h = cakes.size();
    int w = cakes[0].size();
    vector<vector<char>> next(w, vector<char>(h));
    rep(y, h) {
        rep(x, w) {
            next[x][h - y - 1] = cakes[y][x];
        }
    }
    return next;
}

class MatrixSum {
    vector<vector<ll>> sum;
    bool build_end = false;
public:
    MatrixSum(ll h, ll w) {
        sum = vector<vector<ll>>(h, vector<ll>(w));
    }

    void add(ll y, ll x, ll value) {
        assert(!build_end);
        sum[y][x] += value;
    }

    ll get(ll y, ll x) {
        assert(build_end);
        if (x == -1 || y == -1) {
            return 0;
        }
        if (y == sum.size() || x == sum[y].size()) {
            return 0;
        }
        return sum[y][x];
    }

    void setUp() {
        assert(!build_end);
        build_end = true;
        for (ll y = 0; y < sum.size(); y++) {
            for (ll x = 0; x < sum[y].size(); x++) {
                sum[y][x] += get(y - 1, x) + get(y, x - 1) - get(y - 1, x - 1);
            }
        }
    }

    ll getSum(ll ys, ll xs, ll ye, ll xe) {
        assert(build_end);
        return get(ye, xe) - get(ys - 1, xe) - get(ye, xs - 1) + get(ys - 1, xs - 1);
    }

};

ll solve(vector<vector<char>> &cakes) {
    int h = cakes.size();
    int w = cakes[0].size();

    MatrixSum points(h, w), strawberry(h, w);
    rep(y, h) {
        rep(x, w) {
            if (cakes[y][x] == 'X') strawberry.add(y, x, 1);
            else points.add(y, x, cakes[y][x] - '0');
        }
    }
    points.setUp();
    strawberry.setUp();

    ll ans = 0;
    rep(y, h) {
        rep(x, w) {
            if (cakes[y][x] == 'X') continue;
            ll now = 0;
            for (int i = 0; x + i < w && y - i >= 0; i++) {
                if (strawberry.getSum(y - i, x + i, y, x + i) > 0) break;
                ll line = points.getSum(y - i, x + i, y, x + i);
                now += line;
            }
            cmax(ans, now);
        }
    }
    return ans;
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> cakes(h, vector<char>(w));
    rep(y, h) rep (x, w) cin >> cakes[y][x];

    ll ans = 0;
    rep(_, 4) {
        ll now = solve(cakes);
        cmax(ans, now);
        cakes = rotate(cakes);
    }
    cout << ans << endl;

}
