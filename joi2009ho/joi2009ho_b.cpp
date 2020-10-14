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

vector<ll> read_shops(int n, ll d) {
    vector<ll> rs(n - 1);
    rep(i, n - 1) cin >> rs[i];

    rs.push_back(0);

    vector<ll> plus;
    for (ll l : rs) plus.push_back(d + l);

    rs.insert(rs.begin(), plus.begin(), plus.end());

    sort(rs.begin(), rs.end());

    return rs;

}

int main() {
    ll d;
    int n, m;
    cin >> d >> n >> m;

    vector<ll> shops = read_shops(n, d);

    ll ans = 0;
    rep(_, m) {
        ll a;
        cin >> a;

        ll r = *lower_bound(shops.begin(), shops.end(), a);
        ll l = *(upper_bound(shops.begin(), shops.end(), a) - 1);

        ll b1 = r - a;
        ll b2 = a - l;

        ll now = min(b1, b2);
        ans += now;
    }
    cout << ans << endl;

}
