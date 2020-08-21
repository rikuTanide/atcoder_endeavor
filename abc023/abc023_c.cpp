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
    int r, c, k;
    cin >> r >> c >> k;

    int n;
    cin >> n;

    vector<P> candies(n);
    for (P &p:candies) cin >> p.first >> p.second, p.first--, p.second--;

    vector<ll> horizontal(c), vertical(r);
    for (P p : candies) horizontal[p.second]++;
    for (P p : candies) vertical[p.first]++;

    map<int, ll> vertical_count, horizontal_count;
    for (int i : horizontal) horizontal_count[i]++;
    for (int i : vertical) vertical_count[i]++;

    ll ans = 0;

    for (auto e : vertical_count) {
        int v = e.first;
        ll vcr = e.second;

        if (v > k) continue;
        int need_h = k - v;
        ll hcr = horizontal_count[need_h];

        ll now = vcr * hcr;
        ans += now;
    }

    for (P p : candies) {
        ll hc = horizontal[p.second];
        ll vc = vertical[p.first];

        if (hc + vc == k) {
            ans--;
        }
        if (hc + vc == k + 1) {
            ans++;
        }
    }

    cout << ans << endl;


}
