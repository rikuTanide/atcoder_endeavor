#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

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

    void add(ll x, ll y) {
        sum[x][y]++;
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
        assert(xs <= xe);
        assert(ys <= ye);
        return get(xe, ye) - get(xs - 1, ye) - get(xe, ys - 1) + get(xs - 1, ys - 1);
    }

};

struct Hope {
    ll x, y;
    char c;

    Hope norm(int k) {
        ll nx = x % (2 * k);
        ll ny = y % (2 * k);

        if (nx >= k && ny >= k) {
            return Hope{nx % k, ny % k, c,};
        }
        if (ny >= k) {
            return Hope{nx + k, ny % k, c,};
        }
        return Hope{nx, ny, c,};
    }

    Hope up_right_right(int k) {
        return Hope{x + 3 * k, y + k, c};
    }

    Hope right(int k) {
        return Hope{x + 2 * k, y, c};
    }

    Hope up_right(int k) {
        return Hope{x + k, y + k, c};
    }

};


int main() {
    int n, k;
    cin >> n >> k;
    vector<Hope> hopes(n);
    for (Hope &hope: hopes)cin >> hope.x >> hope.y >> hope.c;

    rep(i, n) hopes[i] = hopes[i].norm(k);

    {
        vector<Hope> dummy;
        for (Hope hope: hopes) dummy.push_back(hope);
        for (Hope hope: hopes) dummy.push_back(hope.up_right_right(k));
        for (Hope hope: hopes) dummy.push_back(hope.right(k));
        for (Hope hope: hopes) dummy.push_back(hope.up_right(k));
        hopes = dummy;
    }

    MatrixSum blacks(5 * k + 100, 2 * k + 100), whites(5 * k + 100, 2 * k + 100);
    for (Hope hope: hopes) {
        if (hope.c == 'B') blacks.add(hope.x, hope.y);
        if (hope.c == 'W') whites.add(hope.x, hope.y);
    }
    blacks.setUp();
    whites.setUp();
    int ans = 0;
    rep(x, 2 * k) {
        rep(y, k) {
            int black = blacks.getSum(x, y, x + k - 1, y + k - 1);
            int white = whites.getSum(x + k, y, x + k + k - 1, y + k - 1);
            int now = black + white;
            cmax(ans, now);
        }
    }
    cout << ans << endl;
}
