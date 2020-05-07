#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
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

typedef pair<ll, ll> P;

bool rec(ll x, ll y, bool b) {
    for (int i = 1; 2 * i < x; i++) {
        bool d = rec(x - (2 * i), y, !b);
        if (b == d) return b;
    }
    for (int i = 1; 2 * i < y; i++) {
        bool d = rec(x, y - (2 * i), !b);
        if (b == d) return b;
    }
    return !b;
}

int main() {
    ll x, y;
    cin >> x >> y;
    bool b = rec(x, y, true);
    if (b) {
        cout << "Alice" << endl;
    } else {
        cout << "Brown" << endl;
    }
}
