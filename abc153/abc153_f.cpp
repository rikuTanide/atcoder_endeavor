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

struct Monster {
    ll x, h;
};

std::istream &operator>>(std::istream &in, Monster &o) {
    cin >> o.x >> o.h;
    return in;
}

int main() {
    int n;
    ll d, a;
    cin >> n >> d >> a;
    vector<Monster> monsters(n);
    rep(i, n) cin >> monsters[i];

    sort(monsters.begin(), monsters.end(), [](Monster &m1, Monster &m2) {
        return m1.x < m2.x;
    });

    vector<ll> positions(n);
    rep(i, n) positions[i] = monsters[i].x;
    vector<ll> damages(n);


    ll ans = 0;
    rep(i, n) {
        if (i != 0) damages[i] += damages[i - 1];
        ll h = monsters[i].h;
        ll da = damages[i] * a;
        h -= da;
        if (h <= 0) continue;
        ll c = (h + a - 1) / a;
        ans += c;
        damages[i] += c;
        ll r = monsters[i].x + (d * 2);
        auto it = upper_bound(positions.begin(), positions.end(), r);
        if (it == positions.end()) continue;
        int ri = distance(positions.begin(), it);
        damages[ri] -= c;
    }
    cout << ans << endl;
}
