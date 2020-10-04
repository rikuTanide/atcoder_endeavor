#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>

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

using cpp_dec_float = mp::number<mp::cpp_dec_float<14000>>;

int main() {
    int n, k, m, r;
    cin >> n >> k >> m >> r;
    if (m == 0) {
        cpp_dec_float one = 1;
        cpp_dec_float _n = n;
        cpp_dec_float ans = one / _n;
        cout << ans.str(r, std::ios_base::fixed) << endl;
    } else {
        throw_with_nested("mada");
    }

//    mp::cpp_dec_float<20000> x;
//    cout << x << endl;
}
