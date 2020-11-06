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

int main() {
    int n, m;
    cin >> n >> m;
    vector<P> trains(m);
    for (P &p:trains)cin >> p.first >> p.second, p.first--, p.second--;

    assert(n <= 8 && m <= 8);

    int ans = 0;
    rep(i, 1 << m) {
        vector<int> ts(n);
        rep(j, m) {
            if (!((i >> j) & 1)) continue;
            P p = trains[j];
            for (int k = p.first; k <= p.second; k++) ts[k]++;
        }

        int count = 0;
        rep(j, n) if (ts[j] >= 2) count++;
        if (count == n) ans++;
    }
    cout << ans << endl;
}
