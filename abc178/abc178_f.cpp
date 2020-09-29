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

struct Counter {

    map<ll, int> m;
    set<P> s;

    void push(ll l) {
        ll count = m[l];
        m[l]++;
        if (count == 0) {
            s.insert({1, l});
        } else {
            s.erase({count, l});
            s.insert({count + 1, l});
        }
    }

    ll max_count() {
        auto it = s.end();
        it--;
        P p = *it;
        return p.first;
    }
};

int main() {
    int n;
    cin >> n;
    vector<ll> as(n), bs(n);
    rep(i, n) cin >> as[i];
    rep(i, n) cin >> bs[i];

    Counter all, a_counter, b_counter;

    for (ll a : as) all.push(a);
    for (ll a : as) a_counter.push(a);

    for (ll b : bs) all.push(b);
    for (ll b : bs) b_counter.push(b);

    if (all.max_count() > n) {
        cout << "No" << endl;
        ret();
    }

    __throw_runtime_error("mada");

}
