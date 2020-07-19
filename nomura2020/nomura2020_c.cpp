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
    n++;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    if (n == 1) {
        if (v[0] == 1) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
        ret();
    }

    vector<ll> u_min(n, 0), u_max(n, 0);

    for (int i = n - 2; i >= 0; i--) {
        u_min[i] = (u_min[i + 1] + v[i + 1] + 1) / 2;
        u_max[i] = u_max[i + 1] + v[i + 1];
    }


    vector<ll> d_min(n, 0), d_max(n, 0);
    d_min[0] = 1 - v[0];
    d_max[0] = 1 - v[0];
    for (int i = 1; i < n; i++) {
        ll mi = d_min[i - 1] - v[i];
        ll ma = d_max[i - 1] * 2 - v[i];
        d_min[i] = max(mi, u_min[i]);
        d_max[i] = min(ma, u_max[i]);

        if (d_max[i] - d_min[i] < 0) {
            cout << -1 << endl;
            ret();
        }
    }

    ll ans = accumulate(d_max.begin(), d_max.end(), 0ll) + accumulate(v.begin(), v.end(), 0ll);


    cout << ans << endl;


}
