#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

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

// queueで順番に入れていく方法と
// 事前に減産する方法がありそう。

// まず、スタート地点をマイナスで表す
//

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


struct Construction {
    int id;
    ll start, end, x;

    void norm() {
        ll diff = end - start;
        end = x - start;
        start = end - diff;
    }
};

int main() {
    int n, query_count;
    cin >> n >> query_count;

    vector<Construction> constructions(n);
    for (Construction &construction: constructions) cin >> construction.start >> construction.end >> construction.x;
    sort(constructions.begin(), constructions.end(), [](Construction c1, Construction c2) { return c1.x < c2.x; });
    rep(i, n) constructions[i].id = i;

    vector<ll> queries(query_count);
    rep(i, query_count) cin >> queries[i];

    rep(i, n) constructions[i].norm();

    Conv conv;
    for (Construction construction : constructions) conv.cache(construction.x);
    for (Construction construction : constructions) conv.cache(construction.start);
    for (Construction construction : constructions) conv.cache(construction.end);
    for (ll l : queries) conv.cache(-l);
    conv.build();

    for (Construction &c : constructions) c.start = conv.convert(c.start);
    for (Construction &c : constructions) c.end = conv.convert(c.end);
    for (Construction &c : constructions) c.x = conv.convert(c.x);
    for (ll &q : queries) q = conv.convert(-q);

    vector<vector<int>> starts(conv.next()), ends(conv.next());
    for (Construction c : constructions) starts[c.start].push_back(c.id);
    for (Construction c : constructions) ends[c.end].push_back(c.id);

    vector<int> constructors(conv.next());
    set<int> current_constructors;
    rep(i, conv.next()) {
        if (current_constructors.empty()) constructors[i] = -1;
        else constructors[i] = (*current_constructors.begin());
        for (int c : starts[i]) current_constructors.insert(c);
        for (int c : ends[i]) current_constructors.erase(current_constructors.find(c));
    }

    for (ll q : queries) {
        int c = constructors[q];
        if (c == -1) {
            cout << -1 << endl;
        } else {
            cout << conv.revert(constructions[c].x) << endl;
        }
    }

}
