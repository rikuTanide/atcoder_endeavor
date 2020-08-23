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
    ll n;
    int m;
    cin >> n >> m;

    vector<ll> v(m);
    rep(i, m) cin >> v[i];

    auto one = [&](ll start, ll mid, ll x) -> ll {
        if (x < start) {
            return max(start, x + mid);
        }
        if (start < x - mid) {
            return -1;
        }
        ll t = x - start;
        assert(t >= 0);
        assert(mid >= t);

        ll s1 = mid - 2 * t;
        ll s2 = (mid - t) / 2;
        ll s = max(s1, s2);
        return x + s;

    };

    auto check = [&](ll mid) -> bool {

        ll start = 0;

        rep(i, m) {
            ll next = one(start + 1, mid, v[i]);
            if (next == -1) return false;
            start = next;
        }

        return start >= n;

    };

    if (check(0)) {
        cout << 0 << endl;
        ret();
    }

    ll floor = 0, ceil = INF;
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool ok = check(mid);
        if (ok) ceil = mid;
        else floor = mid;
    }

    cout << ceil << endl;


}
