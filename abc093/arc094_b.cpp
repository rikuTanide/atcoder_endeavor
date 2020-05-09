#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef unsigned long long ll;
typedef pair<ll, ll> P;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e10;
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

ll solve(ll a, ll b) {
    ll floor = 1, ceil = INF;
    ll lim = a * b - 1;
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        ll mul = (mid + 1) / 2 * (mid + 1 - (mid + 1) / 2);
           mul = (mid + 1) / 2 * (mid + 1 - (mid + 1) / 2);
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



