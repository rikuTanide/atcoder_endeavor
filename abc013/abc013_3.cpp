#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {
    int n;
    ll h;
    ll a, b, c, d, e;
    cin >> n >> h >> a >> b >> c >> d >> e;

    ll ans = INF;
    for (int nukuhi = 0; nukuhi <= n; nukuhi++) {
        ll heri = h - e * nukuhi;
        int taberuhi = n - nukuhi;
        if (b * taberuhi + heri <= 0) continue;

        if (d * taberuhi + heri > 0) {
            ll now = c * taberuhi;
            cmin(ans, now);
            continue;
        }

        ll t = -(heri + d * taberuhi);
        assert(t >= 0);
        ll s = b - d;

        ll hutu = (t + s) / s;
        ll siso = taberuhi - hutu;
        ll now = hutu * a + siso * c;
        cmin(ans, now);
    }
    cout << ans << endl;
}
