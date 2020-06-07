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
//
//int N;
//
//string str(ll n) {
//    return to_string(n);
//}

bool q(ll n) {
    cout << "? " << n << endl << flush;
    char c;
    cin >> c;
    return c == 'Y';
}

ll solve() {
    ll x = [&] {
        ll x = 10;
        for (; x <= ll(1e9) && q(x); x *= 10) {}
        return x;
    }();

    if (x == ll(1e10)) {
        x = 2;
        for (; x <= 2 * ll(1e9) && !q(x); x *= 10) {}
        return x / 2;
    }

    ll floor = x / 10, ceil = x - 1;

    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        if (q(mid * ll(1e9))) ceil = mid;
        else floor = mid;
    }
    return ceil;

}

int main() {
    ll n = solve();

//    printf("! %lld\n", n);
    cout << '!' << ' ' << n << endl << flush;

//    rep(i, 10000) {
//        if (i == 0) continue;
//        N = i;
//        cout << i << ' ' << n << endl;

//        cout << (n == N ? "OK" : "NG") << endl;
//    }

}
