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
    ll n;
    ll ga, sa, ba;
    ll gb, sb, bb;
    cin >> n;
    cin >> ga >> sa >> ba;
    cin >> gb >> sb >> bb;

    vector<vector<ll>> dp_b(n + 1, vector<ll>(n + 1, -1));
    vector<vector<ll>> dp_d(n + 1, vector<ll>(n + 1, -1));

    for (ll g = 0; g <= n; g++) {
        for (ll s = 0; s <= n; s++) {
            ll use = g * ga + s * sa;
            ll rem = n - use;

            if (use > n) continue;
            if (ba > bb) {
                dp_b[g][s] = 0;
                dp_d[g][s] = rem;
            } else {
                ll b = rem / ba;
                dp_b[g][s] = b;
                dp_d[g][s] = rem - (rem / ba * ba);
            }
        }
    }

    ll ans = 0;
    for (ll g = 0; g <= n; g++) {
        for (ll s = 0; s <= n; s++) {
            if (dp_b[g][s] == -1) continue;
            ll now = g * gb + s * sb + dp_b[g][s] * bb + dp_d[g][s];
            cmax(ans, now);
        }
    }
    cout << ans << endl;
}
