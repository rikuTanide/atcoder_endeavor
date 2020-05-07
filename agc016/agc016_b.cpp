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


int main() {
    int n;
    cin >> n;

    vector<ll> cats(n);
    rep(i, n) cin >> cats[i];

    ll ma = *max_element(cats.begin(), cats.end());
    ll mi = *min_element(cats.begin(), cats.end());

    if (ma - mi >= 2) {
        cout << "No" << endl;
        ret();
    }
    if (ma - mi == 1) {
        ll x = count(cats.begin(), cats.end(), ma - 1);
        ll y = count(cats.begin(), cats.end(), ma);
        if (x < ma && 2 * (ma - x) <= y) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        ret();
    }

    if (ma == n - 1 || 2 * ma <= n) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
