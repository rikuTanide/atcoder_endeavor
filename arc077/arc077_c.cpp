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
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    ll total = 0;
    vector<ll> imos0(2 * m);
    vector<ll> imos1(2 * m);
    rep(i, n - 1) {
        int l = v[i] - 1;
        int r = v[i + 1] - 1;
        if (r < l) r += m;
        total += r - l;
        if (r - l <= 1)continue;
        imos0[l + 2] += 1;
        imos0[r + 1] -= 1;
        imos1[r + 1] -= (r + 1) - (l + 2);
    }
    imos1[0] += imos0[0];
    rep(i, 2 * m - 1) {
        imos0[i + 1] += imos0[i];
        imos1[i + 1] += imos1[i] + imos0[i + 1];
    }
    vector<ll> reward(m);
    rep(i, m) reward[i] = imos1[i] + imos1[i + m];
    ll res = total - *whole(max_element, reward);
    cout << res << endl;
}
