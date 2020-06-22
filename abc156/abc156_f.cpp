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
    int k, q;
    cin >> k >> q;
    vector<ll> ds(k);
    rep(i, k) cin >> ds[i];

    rep(_, q) {

        int n, x, m;
        cin >> n >> x >> m;

        vector<ll> ds2 = ds;
        for (ll &l : ds2) l %= m;

        ll s = accumulate(ds2.begin(), ds2.end(), 0ll);
        ll zero = count(ds2.begin(), ds2.end(), 0);

        ll ma = (n - 1) / k;
        ll y = x + ma * s;
        zero *= ma;

        ll tail = (n - 1) % k;
        y += accumulate(ds2.begin(), ds2.begin() + tail, 0ll);
        zero += count(ds2.begin(), ds2.begin() + tail, 0);

        ll f = (y / m - x / m);

        cout << n - 1 - f - zero << endl;


    }
}
