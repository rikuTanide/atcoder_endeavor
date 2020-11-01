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

template<class T>
std::istream &operator>>(std::istream &in, set<T> &o) {
    T a;
    in >> a;
    o.insert(a);
    return in;
}

template<class T>
std::istream &operator>>(std::istream &in, queue<T> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

string solve() {
    int n;
    cin >> n;
    return (n % 2 == 0 ? "White" : "Black");
}

int main() {
    int n;
    cin >> n;
    vector<P> v(n);
    for (P &p:v)cin >> p.first >> p.second;
    bool ok = [&] {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || j == k || i == k) continue;

                    P p = v[i];
                    P q = v[j];
                    P r = v[k];

                    ll x = p.first - q.first;
                    ll y = p.second - q.second;

                    ll x2 = q.first - r.first;
                    ll y2 = q.second - r.second;

                    ll f = x * y2;
                    ll t = x2 * y;

                    if (f == t) return true;
                }
            }
        }
        return false;
    }();
    cout << (ok ? "Yes" : "No") << endl;
}
