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
    ll k;
    cin >> n >> k;

    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    ll target = 0;
    rep(i, 63) {

        ll one = 0, zero = 0;
        for (ll l : v) {
            if ((l >> i) & 1) one++;
            else zero++;
        }
        if (zero >= one) target |= (1ll << i);
    }


    auto f = [&](ll x) {
        ll ans = 0;
        for (ll l : v) ans += (l ^ x);
        return ans;
    };

    auto check = [&](int i) -> ll {
        ll x = 0;
        rep(j, 63) {
            if (j == 1) continue;
            else if (j < i) {
                ll b = (target >> j) & 1;
                x |= (b << j);
            } else if (j > i) {
                bool b = (target >> j) & 1;
                bool c = (k >> j) & 1;
                ll d = b && c;

                x |= (d << j);
            }
        }

        return f(x);
    };

    ll ans = f(0);
    rep(i, 63) {
        if ((k >> i) & 1) {
            ll now = check(i);
            cmax(ans, now);
        }
    }
    cout << ans << endl;
}
