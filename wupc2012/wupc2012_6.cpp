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

int main() {
    int n;
    cin >> n;
    vector<P> v(n);
    for (P &p:v)cin >> p.first >> p.second;

    vector<vector<bool>> has(1000, vector<bool>(1000, false));
    for (P p : v) has[p.first][p.second] = true;

    MatrixSum ms(1000, 1000);
    for (P p : v) ms.add(p.first, p.second, 1);
    ms.setUp();

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int y1 = v[i].first;
            int x1 = v[i].second;
            int y2 = v[j].first;
            int x2 = v[j].second;

            if (!has[y2][x1]) continue;
            if (!has[y1][x2]) continue;

            int now = abs(y2 - y1) * abs(x2 - x1);
            cmax(ans, now);

        }
    }

    cout << ans << endl;
}
