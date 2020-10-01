#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
#include "atcoder/all"

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

ll check(ll x, ll y) {

    vector<ll> m = {x, y};
    vector<ll> r = {0, y - 1};

    auto now = atcoder::crt(r, m);
    if (now.first == 0) return INF;
//    cout << now.second << endl;
    return now.first;
}

int main() {
    ll n;
    cin >> n;

    ll n2 = n * 2;

    ll ans = INF;
    for (ll x = 1; x * x <= n2; x++) {
        if (n2 % x != 0) continue;
        ll now = min(check(x, n2 / x), check(n2 / x, x));
        cmin(ans, now);
    }
    cout << ans << endl;

}
