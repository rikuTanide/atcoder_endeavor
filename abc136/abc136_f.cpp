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
    cin >> n;

    vector<P> points(n);
    for (P &p: points) cin >> p.first >> p.second;

    int ans = 0;
    rep(i, 1 << n) {
        if (i == 0) continue;
        ll l = INF, u = -INF, r = -INF, d = INF;
        rep(j, n) if ((i >> j) & 1) {
                P p = points[j];
                cmin(l, p.second);
                cmax(r, p.second);
                cmin(d, p.first);
                cmax(u, p.first);


            }
        int now = 0;
        for (P p : points) {
            if (d <= p.first && p.first <= u && l <= p.second && p.second <= r) now++;
        }
        ans += now;
    }
    cout << ans << endl;

}
