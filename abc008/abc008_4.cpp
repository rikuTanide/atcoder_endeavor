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

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

vector<ll> tp(ll l, ll t, ll r, ll d) {
    return vector<ll>{l, t, r, d};
}

ll rec(map<vector<ll>, ll> &memo, ll h, ll w, vector<P> &machines, ll l, ll t, ll r, ll d) {
    auto index = tp(l, t, r, d);
    if (memo.find(index) != memo.end()) return memo[index];

    ll ans = 0;

    for (P p : machines) {
        ll y = p.first;
        ll x = p.second;

        if (!(d <= y && y <= t && l <= x && x <= r)) {
            continue;
        }

        ll start = (r - l) + (h - d) + 1;
        ll lu = rec(memo, h, w, machines, l, t, x - 1, y + 1);
        ll ru = rec(memo, h, w, machines, x + 1, t, r, y + 1);
        ll rd = rec(memo, h, w, machines, x + 1, y - 1, r, d);
        ll ld = rec(memo, h, w, machines, l, y - 1, x - 1, d);

        ll now = start + lu + ru + rd + ld;

        cmax(ans, now);

    }

    memo[index] = ans;

    return ans;

}

int main() {
    ll w, h;
    cin >> w >> h;

    int n;
    cin >> n;

    vector<P> machines(n);
    rep(i, n) cin >> machines[i].second >> machines[i].first;


    map<vector<ll>, ll> memo;
    ll ans = rec(memo, h, w, machines, 1, h, w, 1);
    cout << ans << endl;
}

