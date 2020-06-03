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

ll f(ll n, ll k) {
    ll sum = 0;
    ll n_ = n;
    while (n_ != 0) {
        sum += n_ % 10;
        n_ /= 10;
    }
    return (n - sum) % k;
}

ll easy(ll k, ll m) {
    ll ans = 0;
    for (ll i = 1; i <= m; i++) {
        if (f(i, k) == 0) ans++;
    }
    return ans;
}


ll solve(ll k, ll m) {
    if (m <= 100000) {
        return easy(k, m);
    }

    map<ll, ll> cnt1;

    for (ll i = 0; i < 100000; i++) {
        cnt1[f(i, k)]++;
    }

    ll ans = 0;
    ll a = m / 100000;
    for (ll i = 0; i < a; i++) {
        ll x = f(i * 100000, k);
        ll y = x == 0 ? 0 : k - x;
        ans += cnt1[y];
    }

    for (ll j = a * 100000; j <= m; j++) {
        if (f(j, k) == 0) ans++;
    }

    return ans - 1;

}

int main() {
    ll k, m;
    cin >> k >> m;

    cout << solve(k, m) << endl;

}

