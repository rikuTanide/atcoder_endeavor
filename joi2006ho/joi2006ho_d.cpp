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

int rec(int now, set<int> &used, vector<vector<int>> &edges) {
    int ma = used.size();
//    cout << ma<<endl;

    for (int next : edges[now]) {
        if (contain(used, next))continue;
        used.insert(next);
        cmax(ma, rec(next, used, edges));
        used.erase(used.find(next));
    }
    return ma;
}

int main() {
    int n;
    cin >> n;
    vector<P> v(n);
    for (P &p:v) cin >> p.first >> p.second, p.first--, p.second--;

    vector<vector<int>> edges(101);
    for (P p : v)edges[p.first].push_back(p.second);
    for (P p : v)edges[p.second].push_back(p.first);

    auto solve = [&](P p) -> int {
        set<int> used;
        used.insert(p.first);
        used.insert(p.second);
        return rec(p.second, used, edges);
    };

    int ans = 0;
    for (P p : v) cmax(ans, solve(p));
    for (P p : v) cmax(ans, solve({p.second, p.first}));
    cout << ans << endl;

}
