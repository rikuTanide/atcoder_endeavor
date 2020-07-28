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
    rep(i, n)cin >> v[i];

    vector<ll> t;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) t.push_back(i), t.push_back(k / i);
    }
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());

    map<ll, ll> mp;
    for (ll l : v)mp[__gcd(l, k)]++;

    ll ans = 0;
    for (auto e1 : mp) {
        for (auto e2 : mp) {
            if (e1.first <= e2.first)continue;
            if (e1.first * e2.first % k == 0) ans += (e1.second * e2.second);
        }
    }

    for (auto e : mp) {
        if (e.first * e.first % k == 0) ans += (e.second * (e.second - 1) / 2);
    }

    cout << ans << endl;

}
