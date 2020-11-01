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

bool check_large(ll n, ll m, vector<P> &v) {
    set<P> s;
    for (P p : v) s.insert(P(min(p.first, p.second), max(p.first, p.second)));
    ll edge_count = n * (n - 1) / 2 - s.size();
    return !(edge_count >= n - 1);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<P> v(m);
    for (P &p:v)cin >> p.first >> p.second;

    if (!check_large(n, m, v)) {
        cout << "no" << endl;
    }

    throw_with_nested("mada");

}
