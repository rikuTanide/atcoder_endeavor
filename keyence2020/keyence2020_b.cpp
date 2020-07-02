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


struct Robot {
    ll x, l;

    ll left() {
        return x - l + 1;
    }

    ll right() {
        return x + l - 1;
    }

};

std::istream &operator>>(std::istream &in, Robot &o) {
    cin >> o.x >> o.l;
    return in;
}


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

struct Range {
    int l, r;
};

int main() {
    int n;
    cin >> n;

    vector<Robot> robots(n);
    rep(i, n) cin >> robots[i];

    Conv conv;
    for (Robot r : robots) conv.cache(r.left()), conv.cache(r.right());
    conv.build();

    vector<Range> ranges(n);
    rep(i, n) ranges[i].l = conv.convert(robots[i].left());
    rep(i, n) ranges[i].r = conv.convert(robots[i].right());

    sort(ranges.begin(), ranges.end(), [](Range r1, Range r2) {
        return r1.r < r2.r;
    });

    vector<int> dp(conv.next(), 0);

    auto get = [&](int i) -> int {
        if (i == -1) return 0;
        return dp[i];
    };

    rep(i, n) {
        Range range = ranges[i];
        dp[range.r] = max(get(range.l - 1) + 1, get(range.r - 1));
    }

    cout << dp.back() << endl;

}
