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

ll get_c(vector<ll> v) {
    sort(v.begin(), v.end());
    return v[v.size() / 2];
}

int main() {
    int n;
    cin >> n;
    vector<P> v(n);
    for (P &p: v)cin >> p.first >> p.second;
    for (P &p : v) if (p.first > p.second) swap(p.first, p.second);

    vector<ll> ss, ts;
    for (P p: v) ss.push_back(p.first);
    for (P p: v) ts.push_back(p.second);

    ll s = get_c(ss);
    ll t = get_c(ts);

    ll ans = 0;
    for (P p : v) {
        ll now = abs(p.first - s);
        now += abs(p.second - p.first);
        now += abs(p.second - t);
        ans += now;
    }

    cout << ans << endl;

}
