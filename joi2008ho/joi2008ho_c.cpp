#include <bits/stdc++.h>
//#include "atcoder/all"
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

ll solve(int n, ll m, vector<ll> &points) {
    vector<set<ll>> prev(5);
    prev[0].insert(0);
    rep(i, n) {
        vector<set<ll>> next(5);

        auto add = [&](int k, ll v) {
            if (k > 4) return;
            if (v > m) return;
            next[k].insert(v);
        };

        rep(k, 4) {
            for (ll p : prev[k]) {
                for (int j = 0; j <= 4; j++) {
                    add(k + j, p + points[i] * j);
                }
            }
        }

        prev = next;
    }

    ll ans = 0;
    rep(i, 5) for(ll v : prev[i]) cmax(ans, v);
    return ans;

}

int main() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> points(n);
    rep(i, n) cin >> points[i];

    ll ans = solve(n, m, points);
    cout << ans << endl;

}