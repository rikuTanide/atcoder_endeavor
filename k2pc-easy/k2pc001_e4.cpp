#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

bool contain(set<ll> &s, int a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

ll to_id(int p, int q) {
    // 0,1 -> 0
    // 1,1 -> 1
    // 1,2 -> 2
    // 2,1 -> 3

    return (1ll << p) + (q - 1) - 1;

}

int main() {

    set<ll> ope;

    int k, n;
    cin >> k >> n;

    unordered_map<ll, int> depth;

    rep(_, n) {
        int p, q;
        cin >> p >> q;
        ll id = to_id(p, q);
        ope.insert(id);
        depth[id] = p;
    }

    auto has_parent = [&](ll id) -> bool {

        for (ll parent_id = id; parent_id > 0; parent_id = (parent_id - 1) / 2) {
            ll pid = (parent_id - 1) / 2;

            if (contain(ope, pid)) return true;
        }

        return false;
    };

    auto calc_score = [&](ll id) -> ll {
        ll d = depth[id];
        return (1ll << (k - d + 1)) - 1;
    };

    ll ans = (1 << (k + 1)) - 1;
    for (ll id : ope) {
        if (has_parent(id)) continue;
        ll score = calc_score(id);
        ans -= score;
    }
    cout << ans << endl;

}
