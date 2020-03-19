#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;


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

class MatrixSum {
    vector<vector<ll>> sum;
public:
    MatrixSum(ll x, ll y) {
        sum = vector<vector<ll>>(x, vector<ll>(y));
    }

    void add(ll x, ll y) {
        assert(x < sum.size());
        assert(y < sum[x].size());
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

int main() {
    int n, k;
    cin >> n >> k;

    vector<P> points(n);
    rep(i, n) cin >> points[i].first >> points[i].second;


    Conv conv_x, conv_y;
    for (P p : points) conv_x.cache(p.first);
    for (P p : points) conv_y.cache(p.second);
    conv_x.build();
    conv_y.build();

    vector<P> conv_points(n);
    rep(i, n) conv_points[i].first = conv_x.convert(points[i].first);
    rep(i, n) conv_points[i].second = conv_y.convert(points[i].second);

    MatrixSum ms(conv_x.next(), conv_y.next());
    for (P p : conv_points) ms.add(p.first, p.second);
    ms.setUp();


    ll ans = LONG_LONG_MAX;
    for (ll xs = 0; xs < conv_x.next(); xs++) {
        for (ll xe = xs + 1; xe < conv_x.next(); xe++) {
            for (ll ys = 0; ys < conv_y.next(); ys++) {
                for (ll ye = ys + 1; ye < conv_y.next(); ye++) {
                    ll count = ms.getSum(xs, ys, xe, ye);
                    if (count < k) continue;
                    ll w = abs(conv_x.revert(xe) - conv_x.revert(xs));
                    ll h = abs(conv_y.revert(ye) - conv_y.revert(ys));
                    ll now = w * h;
                    cmin(ans, now);
                }
            }
        }
    }

    cout << ans << endl;

}

