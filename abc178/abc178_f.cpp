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

struct Counter {

    map<ll, int> m;
    set<P> s;

    void push(ll l) {
        ll count = m[l];
        m[l]++;
        if (count == 0) {
            s.insert({1, l});
        } else {
            s.erase({count, l});
            s.insert({count + 1, l});
        }
    }

    void pop(ll l) {
        ll count = m[l];
        m[l]--;
        if (count == 1) {
            s.erase({1, l});
        } else {
            s.erase({count, l});
            s.insert({count - 1, l});
        }
    }

    ll pop_max() {
        assert(!s.empty());
        auto it = s.end();
        it--;
        P p = *it;
        this->pop(p.second);
        return p.second;
    }

    ll max_count() {
        if (s.empty()) return 0;
        auto it = s.end();
        it--;
        P p = *it;
        return p.first;
    }

    ll pop_max_exclude(ll l) {
        auto it = s.end();
        it--;
        if ((*it).second == l) {
            assert(s.size() >= 2);
            it--;
        }
        P p = *it;
        this->pop(p.second);
        return p.second;
    }

    ll size() {
        return s.size();
    }

    ll top() {
        if (s.empty()) return 0;
        auto it = s.end();
        it--;
        P p = *it;
        return p.second;
    }

    P top2() {
        assert(s.size() >= 2);

        auto it = s.end();
        it--;
        ll x = (*it).second;
        it--;
        ll y = (*it).second;

        return P(x, y);
    }

    ll has(ll l) {
        return m[l] > 0;
    }

};

int main() {
    int n;
    cin >> n;
    vector<ll> as(n), bs(n);
    rep(i, n) cin >> as[i];
    rep(i, n) cin >> bs[i];

    Counter all, a_counter, b_counter;

    for (ll a : as) all.push(a);
    for (ll a : as) a_counter.push(a);

    for (ll b : bs) all.push(b);
    for (ll b : bs) b_counter.push(b);

    if (all.max_count() > n) {
        cout << "No" << endl;
        ret();
    }
    vector<P> ans_pair;
    while (all.max_count() > 0) {
        if (all.max_count() != n) {
            ll a = a_counter.pop_max();
            ll b = b_counter.pop_max_exclude(a);
            ans_pair.push_back({a, b});
            all.pop(a);
            all.pop(b);
        } else if (all.size() == 2) {
            P p = all.top2();
            if (a_counter.has(p.first) && b_counter.has(p.second)) {
                ll a = p.first;
                ll b = p.second;
                a_counter.pop(a);
                b_counter.pop(b);
                all.pop(a);
                all.pop(b);
                ans_pair.push_back({a, b});
            } else if (a_counter.has(p.second) && b_counter.has(p.first)) {
                ll b = p.first;
                ll a = p.second;
                a_counter.pop(a);
                b_counter.pop(b);
                all.pop(a);
                all.pop(b);
                ans_pair.push_back({a, b});
            } else {
                __throw_runtime_error("nande?");
            }
        } else {
            ll x = all.top();
            if (a_counter.has(x)) {
                ll a = x;
                a_counter.pop(x);
                ll b = b_counter.pop_max_exclude(x);
                ans_pair.push_back({a, b});
                all.pop(a);
                all.pop(b);
            } else {
                ll b = x;
                b_counter.pop(x);
                ll a = a_counter.pop_max_exclude(x);
                ans_pair.push_back({a, b});
                all.pop(a);
                all.pop(b);
            }
        }
        n--;
    }

    map<ll, vector<ll>> mv;
    for (P p : ans_pair) mv[p.first].push_back(p.second);

    cout << "Yes" << endl;
    for (ll a : as) {
        cout << mv[a].back() << endl;
        mv[a].pop_back();
    }


}
