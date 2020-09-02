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

ll solve(ll l, vector<ll> v, int k, int q) {

    vector<vector<ll>> segments = {{}};
    for (ll t : v) {
        if (t < l) segments.push_back({});
        else segments.back().push_back(t);
    }

    vector<ll> tmp;
    for (vector<ll> &u: segments) sort(u.rbegin(), u.rend());
    for (vector<ll> &u: segments) {
        while (u.size() >= k) {
            tmp.push_back(u.back());
            u.pop_back();
        }
    }

    if (tmp.size() < q) return INF;
    sort(tmp.begin(), tmp.end());
    ll a = tmp[q - 1];
    return a - l;

}

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    ll ans = INF;
    for (ll l : v) cmin(ans, solve(l, v, k, q));

    cout << ans << endl;

}
