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

bool equal(double a, double b) {
//    return fabs(a - b) < DBL_EPSILON;
    return fabs(a - b) < EPS;
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

void rec(vector<ll> v, ll x, ll f, set<ll> &used) {
    if (v.empty()) return;
    ll b = v.back();
    ll t = ((x - f) + b - 1) / b;
    used.insert(t);

    ll u = x - ((x - f) / b * b) + f;
    v.pop_back();
    rec(v, x, u, used);

}

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    set<ll> used;
    rec(v, x, 0, used);
    cout << used.size() << endl;

//    for (ll l : used) cout << l << endl;

}
