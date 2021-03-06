#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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

template<class T>
std::istream &operator>>(std::istream &in, set<T> &o) {
    T a;
    in >> a;
    o.insert(a);
    return in;
}

template<class T>
std::istream &operator>>(std::istream &in, queue<T> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

P e(P p) {
    return P(min(p.first, p.second), max(p.first, p.second));
}

bool rec(int n, int start, int prev, vector<char> &memo, vector<vector<int>> &edges, vector<bool> &used) {
    if (memo[start] != '-') return memo[start] == 'o';

    used[start] = true;

    bool ok = [&] {

        for (int next : edges[start]) {
            if (next == prev) continue;
            if (used[next]) return false;
            bool ok = rec(n, next, start, memo, edges, used);
            if (!ok) return false;
        }
        return true;
    }();

    used[start] = false;
    memo[start] = ok ? 'o' : 'x';

    return ok;

}


bool check(ll n, set<P> &s) {

    vector<char> memo(n, '-');

    vector<vector<int>> edges(n);
    for (P p: s) edges[p.first].push_back(p.second), edges[p.second].push_back(p.first);
    rep(i, n) {
        vector<bool> used(n, false);
        bool ok = rec(n, i, -1, memo, edges, used);
        if (!ok) return false;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<P> v(m);
    for (P &p:v)cin >> p.first >> p.second, p.first--, p.second--;
    for (P &p : v) p = e(p);

    bool ng = [&]() -> bool {
        set<P> s;
        for (P p : v) {
            if (contain(s, p)) s.erase(p);
            else s.insert(p);
            ll edge_count = n * (n - 1) / 2 - s.size();
            if (edge_count > n - 1) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }();

    if (ng) {
        rep(i, m) cout << "no" << endl;
        ret();
    }


    set<P> s;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            s.insert(P(i, j));
        }
    }

    for (P p : v) {
        if (contain(s, p))s.erase(p);
        else s.insert(p);

        ll edge_count = s.size();

        if (edge_count > n - 1) {
            cout << "no" << endl;
        } else {
            cout << (check(n, s) ? "yes" : "no") << endl;
        }
    }


}
