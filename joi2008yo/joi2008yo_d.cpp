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
    int m;
    cin >> m;
    vector<P> sign(m);
    for (P &p : sign) cin >> p.first >> p.second;

    int n;
    cin >> n;
    vector<P> sky(n);
    for (P &p: sky) cin >> p.first >> p.second;

    P base = sign.back();
    sign.pop_back();

    for (P &p: sign) p.first -= base.first, p.second -= base.second;

    set<P> sky_s;
    for (P p: sky) sky_s.insert(p);

    for (P p : sky) {
        bool ok = [&]() -> bool {
            for (P q : sign) {
                P target = {p.first + q.first, p.second + q.second};
                if (sky_s.find(target) == sky_s.end()) return false;
            }
            return true;
        }();
        if (ok) {
            cout << p.first - base.first << ' ' << p.second - base.second << endl;
            ret();
        }
    }

}
