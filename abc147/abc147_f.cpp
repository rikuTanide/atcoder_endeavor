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
const ll INF = LONG_LONG_MAX / 100;
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
    ll n, x, d;
    cin >> n >> x >> d;

    if (d == 0) {
        if (x == 0) {
            cout << 1 << endl;
        } else {
            cout << n + 1 << endl;
        }
        return 0;
    }

    map<int, vector<P>> mp;
    rep(i, n + 1) {
        ll s = x * i;
        ll l = i * (i - 1) / 2;
        ll r = l + i * (n - i);
        s += l * d;
        r -= l;
        mp[(s + (d << 30)) % d].emplace_back(s, r);
    }
    ll ans = 0;
    for (auto p : mp) {
        auto a = p.second;
        int m = a.size();
        rep(i, m) a[i].first = (a[i].first - p.first) / d;
        vector<P> ev;
        rep(i, m) {
            ev.emplace_back(a[i].first, 1);
            ev.emplace_back(a[i].first + a[i].second + 1, -1);
        }
        sort(ev.begin(), ev.end());
        ll count = 0, pre = -INF;
        for (auto e : ev) {
            ll len = e.first - pre;
            if (count) ans += len;
            count += e.second;
            pre = e.first;
        }
    }
    cout << ans << endl;
}