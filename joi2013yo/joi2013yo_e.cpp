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

bool equal(double a, double b) {
//    return fabs(a - b) < DBL_EPSILON;
    return fabs(a - b) < EPS;
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

class Conv {
    ll cursor = 0;
    map<ll, ll> to_short; // <original, small >
    map<ll, ll> to_long; // <small, original>
    std::set<ll> tmp;

    bool build_end = false;

    void set(ll original) {
        if (to_short.find(original) != to_short.end()) {
            return;
        }
        to_long[cursor] = original;
        to_short[original] = cursor;
        cursor++;
    }

public:


    ll revert(ll after) {
        assert(build_end);
        assert(to_long.find(after) != to_long.end());
        return to_long[after];
    }

    ll convert(ll original) {
        assert(build_end);
        assert(to_short.find(original) != to_short.end());
        return to_short[original];
    }

    ll next() {
        return cursor;
    }

    // 前計算省略のため
    void cache(ll t) {
        assert(!build_end);
        tmp.insert(t);
    }

    void build() {
        assert(!build_end);
        for (ll t : tmp) {
            set(t);
        }
        build_end = true;
    }

};

struct Fish {
    int x1, y1, d1, x2, y2, d2;

    bool in(int y, int x, int d) {
        if (!(y1 <= y && y <= y2)) return false;
        if (!(x1 <= x && x <= x2)) return false;
        if (!(d1 <= d && d <= d2)) return false;
        return true;
    }
};

bool check(int y, int x, int d, vector<Fish> &fishes, int k) {
    int count = 0;
    for (Fish &f : fishes) if (f.in(y, x, d)) count++;
    return count >= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Fish> fishes(n);
    for (Fish &f: fishes)cin >> f.x1 >> f.y1 >> f.d1 >> f.x2 >> f.y2 >> f.d2;

    Conv conv_w, conv_h, conv_d;

    for (Fish f : fishes) {
        conv_w.cache(f.x1);
        conv_w.cache(f.x2 - 1);
        conv_w.cache(f.x2);

        conv_h.cache(f.y1);
        conv_h.cache(f.y2 - 1);
        conv_h.cache(f.y2);

        conv_d.cache(f.d1);
        conv_d.cache(f.d2 - 1);
        conv_d.cache(f.d2);
    }

    conv_w.build();
    conv_h.build();
    conv_d.build();

    for (Fish &f: fishes) {
        f.y1 = conv_h.convert(f.y1);
        f.y2 = conv_h.convert(f.y2 - 1);

        f.x1 = conv_w.convert(f.x1);
        f.x2 = conv_w.convert(f.x2 - 1);

        f.d1 = conv_d.convert(f.d1);
        f.d2 = conv_d.convert(f.d2 - 1);
    }

//    for (Fish &f:fishes)f.x2--, f.y2--, f.d2--;

    auto conv_replace = [&](int y, int x, int d) -> ll {
        ll y1 = conv_h.revert(y);
        ll y2 = conv_h.revert(y + 1);

        ll x1 = conv_w.revert(x);
        ll x2 = conv_w.revert(x + 1);

        ll d1 = conv_d.revert(d);
        ll d2 = conv_d.revert(d + 1);

        ll w = y2 - y1;
        ll h = x2 - x1;
        ll de = d2 - d1;

        return w * h * de;

    };

    ll ans = 0;
    for (int y = 0; y <= conv_h.next(); y++) {
        for (int x = 0; x <= conv_w.next(); x++) {
            for (int d = 0; d <= conv_d.next(); d++) {
                if (check(y, x, d, fishes, k)) {
                    ans += conv_replace(y, x, d);
                }
            }
        }
    }

    cout << ans << endl;
}
