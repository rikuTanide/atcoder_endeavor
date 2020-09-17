#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
#include "atcoder/all"

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
    int n, d;
    cin >> n >> d;

    vector<P> v(n);
    for (P &p:v) cin >> p.first >> p.second;

    atcoder::two_sat ts(n);

    rep(i, n) {
        rep(j, n) {
            if (i <= j) continue;
            int ia = v[i].first;
            int ib = v[i].second;
            int ja = v[j].first;
            int jb = v[j].second;

            if (abs(ia - ja) < d) {
                ts.add_clause(i, false, j, false);
            }
            if (abs(ia - jb) < d) {
                ts.add_clause(i, false, j, true);
            }
            if (abs(ib - ja) < d) {
                ts.add_clause(i, true, j, false);
            }
            if (abs(ib - jb) < d) {
                ts.add_clause(i, true, j, true);
            }
        }
    }

    if (!ts.satisfiable()) {
        cout << "No" << endl;
        ret();
    }

    cout << "Yes" << endl;
    auto answer = ts.answer();
    rep(i, n) cout << (answer[i] ? v[i].first : v[i].second) << endl;


}
