
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
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

/*
 * https://atcoder.jp/contests/joi2006yo/submissions/17087876 を参考に作成
 */
int main() {
    int n, k, m, r;
    cin >> n >> k >> m >> r;
    if (0 == m) {
        mp::cpp_int x = 10, y = mp::pow(x, r), z = y / n;
        cout << z / y << "." << setw(r) << setfill('0') << z % y << endl;
    } else {
        mp::cpp_int x = 10, y = mp::pow(x, r), z = y;
        for (int i = 1; i < n; i++) {
            z += y / i;
        }
        z /= n;
        cout << z / y << "." << setw(r) << setfill('0') << z % y << endl;
    }
    return 0;
}