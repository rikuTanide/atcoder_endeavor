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

int main() {
    int n;
    cin >> n;
    vector<ll> v(n * 3);
    rep(i, 3 * n) cin >> v[i];

    vector<ll> l(3 * n);
    ll l_sum = accumulate(v.begin(), v.begin() + n, 0ll);
    PQ_ASK lq;
    for (int i = 0; i < n; i++) lq.push(v[i]);
    l[n - 1] = l_sum;
    for (int i = n; i < n * 2; i++) {
        l_sum += v[i];
        ll mi = lq.top();
        l_sum -= mi;
        lq.pop();
        l[i] = l_sum;
    }

    vector<ll> r(3 * n);
    ll r_sum = accumulate(v.begin() + 2 * n, v.end(), 0ll);
    priority_queue<ll> rq;
    for (int i = 3 * n - 1; i >= 2 * n; i--) rq.push(v[i]);
    r[2 * n] = r_sum;
    for (int i = 2 * n - 1; i >= n; i--) {
        r_sum += v[i];
        ll ma = rq.top();
        r_sum -= ma;
        rq.pop();
        r[i] = r_sum;
    }
    ll ans = -INF;
    for (int i = n - 1; i < 2 * n; i++) {
        ll now = l[i] - r[i + 1];
        cmax(ans, now);
    }
    cout << ans << endl;

}
