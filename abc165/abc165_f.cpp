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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

class Conv {
    ll cursor = 0;
    map<ll, ll> to_short; // <original, small >
    map<ll, ll> to_long; // <small, original>
    std::set<ll> tmp;


public:
    void set(ll original) {
        if (to_short.find(original) != to_short.end()) {
            return;
        }
        to_long[cursor] = original;
        to_short[original] = cursor;
        cursor++;
    }

    ll revert(ll after) {
        assert(to_long.find(after) != to_long.end());
        return to_long[after];
    }

    ll convert(ll original) {
        assert(to_short.find(original) != to_short.end());
        return to_short[original];
    }

    ll next() {
        return cursor;
    }

    // 前計算省略のため
    void cache(ll t) {
        tmp.insert(t);
    }

    void build() {
        for (ll t : tmp) {
            set(t);
        }
    }

};

void rec(int now, int prev, vector<ll> &v, vector<vector<int>> &edges, vector<ll> &dp, vector<int> &ans, int am) {
    ll now_v = v[now];
    auto it = lower_bound(dp.begin(), dp.end(), now_v);
    int a = max<int>(distance(dp.begin(), it), am);
    ans[now] = a;


    ll tmp = *it;
    *it = min(*it, now_v);

    for (int next : edges[now]) {
        if (next == prev) continue;
        rec(next, now, v, edges, dp, ans, a);
    }
    *it = tmp;
}

int main() {
    int n;
    cin >> n;

    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    vector<vector<int>> edges(n);
    rep(_, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }


    Conv conv;
    rep(i, n)conv.cache(v[i]);
    conv.build();
    rep(i, n) v[i] = conv.convert(v[i]);

    vector<ll> dp(n + 1, INF);
    dp[0] = -INF;

    vector<int> ans(n);

    rec(0, -1, v, edges, dp, ans, 0);

    for (ll a : ans) cout << a << endl;
}
