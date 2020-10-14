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
    int n, d;
    cin >> n >> d;

    vector<vector<ll>> stores(n, vector<ll>(d));

    rep(day, d) rep(shop, n) cin >> stores[shop][day];

    vector<vector<ll>> prev(2, vector<ll>(n, INF));
    rep(shop, n) prev[0][shop] = stores[shop][0];

    for (int day = 1; day < d; day++) {
        ll mi1 = *min_element(prev[0].begin(), prev[0].end());
        ll mi2 = *min_element(prev[1].begin(), prev[1].end());
        vector<vector<ll>> next(2, vector<ll>(n, INF));

        rep(shop, n) {
            ll cost = stores[shop][day];

            ll cost_90par = cost / 10 * 9;
            ll cost_70par = cost / 10 * 7;

            next[0][shop] = min(mi1 + cost, mi2 + cost);
            next[1][shop] = min(prev[0][shop] + cost_90par, prev[1][shop] + cost_70par);
        }
        prev = next;
    }

    ll mi1 = *min_element(prev[0].begin(), prev[0].end());
    ll mi2 = *min_element(prev[1].begin(), prev[1].end());

    ll ans = min(mi1, mi2);

    cout << ans << endl;

}


