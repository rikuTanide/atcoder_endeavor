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
    vector<ll> as(n), bs(n);
    for (ll &l:as)cin >> l;
    for (ll &l:bs)cin >> l;

    auto get = [&](int i) -> ll {
        return bs[(i + n) % n];
    };

    auto check = [&]() -> bool {
        rep(i, n) if (get(i) - (get(i + 1) + get(i - 1)) >= as[i]) return true;
        return false;
    };

    int ans = 0;
    while (check()) {
        rep(i, n) {
            while (get(i) - (get(i + 1) + get(i - 1)) >= as[i]) {
                ans++;
                bs[i] -= (get(i + 1) + get(i - 1));
            }
        }
    }

    if (as == bs) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

}
