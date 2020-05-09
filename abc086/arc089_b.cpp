#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
typedef pair<ll, ll> P;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

struct Believe {
    ll x, y;
    char c;
};

std::istream &operator>>(std::istream &in, Believe &o) {
    cin >> o.x >> o.y >> o.c;
    return in;
}

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
        return get(xe, ye) - get(xs - 1, ye) - get(xe, ys - 1) + get(xs - 1, ys - 1);
    }

};

struct Rect {
    ll y1, x1, y2, x2;
};

vector<Rect> get_segments(Rect rect, ll k) {
    if (rect.y2 < k && rect.x2 < k) return {rect};
    if (rect.y2 >= k) {
        ll w = rect.x2 - rect.x1 + 1;
        ll h = rect.y2 - rect.y1 + 1;
        Rect old = Rect{
                rect.y1, rect.x1, k - 1, rect.x1 + w - 1,
        };
        ll oh = old.y2 - old.y1 + 1;
        ll nh = h - oh;
        Rect add = Rect{
                0, old.x2 + 1, nh - 1, old.x2 + 1 + w - 1,
        };

        vector<Rect> v;
        for (Rect r : get_segments(old, k)) v.push_back(r);
        for (Rect r : get_segments(add, k)) v.push_back(r);
        return v;
    }
    if (rect.x2 >= k * 2) {
        ll w = rect.x2 - rect.x1 + 1;
        ll h = rect.y2 - rect.y1 + 1;
        Rect old = Rect{
                rect.y1, rect.x1, rect.y2, 2 * k - 1,
        };
        ll ow = old.x2 - old.x1 + 1;
        ll nw = w - ow;
        Rect add = Rect{
                rect.y1, 0, rect.y2, nw - 1,
        };
        return {old, add};
    }
    return {rect};
}


int main() {
    ll n, k;
    cin >> n >> k;

    vector<Believe> believes(n);
    rep(i, n) cin >> believes[i];
    rep(i, n) believes[i].x %= (k * 2);
    rep(i, n) believes[i].y %= (k * 2);
    rep(i, n) {
        Believe &b = believes[i];
        if (b.x < k && b.y < k) continue;
        else if (b.x >= k && b.y >= k) b.x -= k, b.y -= k;
        else if (b.y >= k) b.x += k, b.y -= k;
    }

    MatrixSum
            blacks(k * 2, k),
            whites(k * 2, k);

    rep(i, n) {
        Believe b = believes[i];
        if (b.c == 'W') whites.add(b.x, b.y);
        else blacks.add(b.x, b.y);
    }
    blacks.setUp();
    whites.setUp();

    ll b_all = 0;
    for (Believe b : believes) if (b.c == 'B') b_all++;

    auto get_count = [&](MatrixSum &ms, vector<Rect> &rect) {
        ll sum = 0;
        for (Rect &r : rect) {
            sum += ms.getSum(r.x1, r.y1, r.x2, r.y2);
        }
        return sum;
    };



    ll ans = 0;
    for (ll y = 0; y < k; y++) {
        for (ll x = 0; x < k; x++) {
            vector<Rect> segments = get_segments(Rect{y, x, y + k - 1, x + k - 1}, k);

            ll w = get_count(whites, segments);
            ll b = get_count(blacks, segments);

            ll now = w + (b_all - b);
            cmax(ans, now);

        }
    }
    cout << ans << endl;
}

