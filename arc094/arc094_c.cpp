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

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    if (a == b) {
        cout << 0 << endl;
        ret();
    }

    ll bm = INF;
    rep(i, n) {
        if (a[i] > b[i]) cmin(bm, b[i]);
    }

    cout << accumulate(a.begin(), a.end(), 0ll) - bm << endl;
}



