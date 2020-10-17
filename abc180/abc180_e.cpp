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

struct Point {
    ll a, b, c;
};

ll calc_cost(Point x, Point y) {
    ll a = x.a;
    ll b = x.b;
    ll c = x.c;
    ll p = y.a;
    ll q = y.b;
    ll r = y.c;

    return abs(p - a) + abs(q - b) + max(0ll, r - c);

}

void solve() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (Point &p : points)cin >> p.a >> p.b >> p.c;

    map<ll, vector<P>> m;
    rep(i, n) {
        rep(j, n) {
            if (i == j)continue;
            ll cost = calc_cost(points[i], points[j]);
            m[cost].push_back(P(i, j));
        }
    }
    vector<bool> in_used(n, false);
    vector<bool> out_used(n, false);

    ll sum = 0;

    for (auto &e : m) {
        for (P p : e.second) {
            ll cost = e.first;
            assert(cost > 0);
            if ((!in_used[p.first]) && (!out_used[p.second])) {
                in_used[p.first] = true;
                out_used[p.second] = true;
                sum += cost;
            }
        }
    }

    assert(count(in_used.begin(), in_used.end(), true) == n);
    assert(count(out_used.begin(), out_used.end(), true) == n);

    cout << sum << endl;

}

int main() {
    solve();
}
