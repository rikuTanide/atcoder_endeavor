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

int main() {
    int n, m;
    cin >> n >> m;

    if (n == 1 && m == 0) {
        cout << "1 2" << endl;
        ret();
    }

    if (n - abs(m) < 2) {
        cout << -1 << endl;
        ret();
    }

    if (m < 0) {
        cout << -1 << endl;
        ret();
    }

    int now = 0;

    P cover = {0, -1};
    vector<P> inner(m + 1);
    for (P &p : inner) p.first = ++now, p.second = ++now;
    cover.second = ++now;

    vector<P> outer(n - 1 - (m + 1));
    for (P &p : outer) p.first = ++now, p.second = ++now;

    vector<P> ans;
    ans.push_back(cover);

    for (P p : inner) ans.push_back(p);
    for (P p : outer) ans.push_back(p);

    for (P p : ans) printf("%lld %lld\n", p.first, p.second);


}
