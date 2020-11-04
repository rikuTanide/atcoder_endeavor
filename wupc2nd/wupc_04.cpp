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

bool equal(double a, double b) {
//    return fabs(a - b) < DBL_EPSILON;
    return fabs(a - b) < EPS;
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

int main() {
    ll a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    ll ans = 0;
    ans += e;

    {
        ans += d;
        ll p = 5 * 5 * 5 - 4 * 4 * 4;
        ll q = p * d;
        a = max<ll>(a - q, 0);
    }

    {
        ans += c;
        {
            ll q = min(c * 7, b);
            b = max<ll>(b - q, 0);

            {
                ll r = (5 * 5 * 5 - 3 * 3 * 3) * c - q * (2 * 2 * 2);
                a = max<ll>(a - r, 0);
            }

        }
    }

    {
        ll q = (b + 7) / 8;
        ans += q;

        ll r = (5 * 5 * 5) * q - (b * (2 * 2 * 2));
        a = max<ll>(a - r, 0);
    }

    ans += (a + 124) / 125;

    cout << ans << endl;

}
