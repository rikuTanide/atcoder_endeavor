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

    vector<P> cheater(m);
    for (P &p:cheater) cin >> p.first >> p.second;

    vector<ll> xs(m), ys(m);
    rep(i, m) ys[i] = cheater[i].first;
    rep(i, m) xs[i] = cheater[i].second;

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());


    auto count = [&](vector<ll> &v, ll mid) -> int {
        auto it = v.begin();
        int c = 0;
        while (it != v.end()) {
            c++;
            it = upper_bound(v.begin(), v.end(), (*it) + mid);
        }
        return c;
    };

    auto check = [&](ll mid) -> bool {
        int a = count(xs, mid);
        int b = count(ys, mid);

        int sum = a + b;
        return sum <= n;
    };

    if (check(0)) {
        cout << 0 << endl;
        ret();
    }

    ll floor = 0, ceil = INF;
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool ok = check(mid);
        if (ok) ceil = mid;
        else floor = mid;
    }

    cout << ceil << endl;

}
