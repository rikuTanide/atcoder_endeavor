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

ll mp(ll start, ll left, ll right) {
    assert(left <= right);
    left -= start;
    right -= start;

    if (left < 0 && 0 < right) {
        ll r = right * (right + 1) / 2;
        left = -left;
        ll l = left * (left + 1) / 2;
        return l + r;
    }

    if (left < 0) {
        right = -right;
        left = -left;
        swap(right, left);
    }

    ll r = right * (right + 1) / 2;
    ll l = left * (left - 1) / 2;
    return r - l;

}

ll solve(ll r, ll g, ll b, ll gl) {
    // gの一番左がglであるとする。

    ll normal_rr = -100 + (r / 2);
    ll normal_bl = 100 - (b / 2);

    ll gr = gl + g - 1;

    ll rr = (gl <= normal_rr) ? gl - 1 : normal_rr;
    ll rl = rr - r + 1;

    ll bl = (normal_bl <= gr) ? gr + 1 : normal_bl;
    ll br = bl + b - 1;

    ll rp = mp(-100, rl, rr);
    ll gp = mp(0, gl, gr);
    ll bp = mp(100, bl, br);

    return rp + gp + bp;

}

int main() {
    ll r, g, b;
    cin >> r >> g >> b;

    ll ans = INF;
    for (int gl = -1000; gl < 1000; gl++) {

        ll now = solve(r, g, b, gl);
        cmin(ans, now);
    }
    cout << ans << endl;

}
