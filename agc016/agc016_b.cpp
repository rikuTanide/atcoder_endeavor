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
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    auto p = minmax_element(v.begin(), v.end());
    int mi = *p.first;
    int ma = *p.second;

    int d = ma - mi;
    if (ma - mi >= 2) {
        cout << "No" << endl;
        ret();
    }
    if (d == 1) {
        ll x = count(v.begin(), v.end(), mi);
        ll y = count(v.begin(), v.end(), ma);
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
