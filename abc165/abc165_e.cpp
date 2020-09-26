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
    int ev = (m + 1) / 2;
    int od = m / 2;
    assert(ev + od == m);

    deque<int> eq, oq;
    rep(i, ev * 2) eq.push_back(i);
    rep(i, od * 2) oq.push_back(i + eq.size());
    oq.push_back(oq.back() + 1);

    while (!eq.empty()) {
        printf("%d %d\n", eq.front() + 1, eq.back() + 1);
        eq.pop_front();
        eq.pop_back();
    }

    while (oq.size() > 1) {
        printf("%d %d\n", oq.front() + 1, oq.back() + 1);
        oq.pop_front();
        oq.pop_back();
    }
}
