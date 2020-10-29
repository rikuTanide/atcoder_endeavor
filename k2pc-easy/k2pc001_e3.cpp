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


ll h(ll n) {
    // 1 -> 1
    // 2 -> 2
    // 3 -> 4

    return 1ll + (n - 1) * (n) / 2;

}

ll g(ll n) {
    ll floor = 1, ceil = sqrt(LONG_LONG_MAX);
    while (floor + 1 < ceil) {

        ll mid = (floor + ceil) / 2;
        bool ok = h(mid) <= n;
        if (ok) floor = mid;
        else ceil = mid;
    }
    return floor - 1;
}

P cip(ll i) {
    ll k = g(i);
    ll l = h(k + 1);

    ll diff = i - l;
    return P(k - diff + 1, diff + 1);

}

ll conv(ll x, ll y) {
    return h(x + y + 1) + y;
}

int main() {

    ll i, j;
    cin >> i >> j;
    P a = cip(i);
    P b = cip(j);
    P c = P(a.first + b.first, a.second + b.second);


    cout << conv(c.first - 1, c.second - 1) << endl;


}