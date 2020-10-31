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

template<class T>
std::istream &operator>>(std::istream &in, set<T> &o) {
    T a;
    in >> a;
    o.insert(a);
    return in;
}

template<class T>
std::istream &operator>>(std::istream &in, queue<T> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


int main() {
    ll n, k;
    cin >> n >> k;

    map<ll, ll> counts;

    for (int i = 2; i <= 2 * n; i++) {
        if (i > n) {
            ll a = n + n - i + 1;
            counts[i] = a;

        } else {
            ll a = i - 1;
            counts[i] = a;
        }
    }
    ll ans = 0;
    for (int ab = 2; ab <= 2 * n; ab++) {
        ll bc = ab - k;
        ll now = counts[ab] * counts[bc];
        ans += now;
    }
    cout << ans << endl;

}
