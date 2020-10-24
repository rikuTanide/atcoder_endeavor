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

void solve() {


    ll n;
    cin >> n;

    double nl = log10(n);

    for (int a = 0; a < 100; a++) {
        for (int b = 0; b < 100; b++) {
//            double al = log10(3) * a;
//            double bl = log10(5) * b;
//
//            if (al > nl) continue;
//            if (bl > nl) continue;

            if (pow(3, a) + pow(5, b) == n) {
                printf("%d %d\n", a, b);
                return;
            }

        }
    }

    cout << -1 << endl;
}

int main() {
    solve();
}
