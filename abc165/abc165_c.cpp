#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

struct Query {
    ll a, b, c, d;
};

std::istream &operator>>(std::istream &in, Query &o) {
    cin >> o.a >> o.b >> o.c >> o.d;
    o.a--;
    o.b--;
    return in;
}

ll check(vector<ll> &v, vector<Query> &query) {
    ll ans = 0;
    for (Query &q : query) {
        if (v[q.b] - v[q.a] == q.c) ans += q.d;
    }
    return ans;
}

ll rec(ll n, ll m, vector<Query> &query, vector<ll> prev) {
    if (prev.size() == n) {
        return check(prev, query);
    }
    ll ans = 0;
    ll start = prev.empty() ? 1 : prev.back();
    for (ll i = start; i <= m; i++) {
        vector<ll> next = prev;
        next.push_back(i);
        ll now = rec(n, m, query, next);
        cmax(ans, now);
    }
    return ans;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<Query> query(q);
    rep(i, q) cin >> query[i];

    vector<ll> a;
    ll ans = rec(n, m, query, a);
    cout << ans << endl;

}
