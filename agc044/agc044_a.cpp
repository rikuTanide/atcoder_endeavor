#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef unsigned long long ll;
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

ll rec(ll n, ll c2, ll c3, ll c5, ll c1, map<ll, ll> &memo) {
    if (memo.find(n) != memo.end()) return memo[n];

    if (n == 0) return 0;
    if (n == 1) return c1;

    auto t1 = [&](ll x, ll c) -> ll {
        ll target = n / x * x;
        ll one = (n - target) * c1;
        return rec(target / x, c2, c3, c5, c1, memo) + one + c;
    };


    auto t2 = [&](ll x, ll y) -> ll {
        if (n % x == 0) return INF;
        ll target = (n + x - 1) / x * x;
        assert(target > n);
        ll one = (target - n) * c1;
        return rec(target / x, c2, c3, c5, c1, memo) + one + y;
    };

    ll ans = n * c1;
    cmin(ans, t1(2, c2));
    cmin(ans, t1(3, c3));
    cmin(ans, t1(5, c5));
    cmin(ans, t2(2, c2));
    cmin(ans, t2(3, c3));
    cmin(ans, t2(5, c5));

    memo[n] = ans;
    return ans;

}

int main() {
    int t;
    cin >> t;
    rep(_, t) {
        ll n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;

        map<ll, ll> memo;
        ll now = rec(n, a, b, c, d, memo);
        cout << now << endl;

    }

}
