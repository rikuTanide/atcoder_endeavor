#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e9;
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
ll solve(ll a, ll b) {
    if (a == b) return (a - 1) * 2;
    ll floor = 1, ceil = INF;
    ll lim = a * b - 1;
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        ll mul = (mid + 1) / 2 * (mid + 1 - (mid + 1) / 2);
        if (mul > lim) ceil = mid;
        else floor = mid;
    }
    return floor - 1;
}

int main() {
    ll q;
    cin >> q;

    rep(i, q) {
        ll a, b;
        cin >> a >> b;

        cout << solve(a, b) << endl;
    }

}
