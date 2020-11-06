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

template<class T, class F>
struct SegmentTree {
    F f;
    T ti;
    vector<T> dat;
    int sz;

    SegmentTree(const F &f, const T &ti) : f(f), ti(ti) {}

    void build(const vector<T> &v) {
        assert(v.size());
        sz = 1;
        while (sz < v.size())sz <<= 1;
        dat.resize(sz << 1, ti);
        for (int i = 0; i < v.size(); i++)dat[sz - 1 + i] = v[i];
        for (int i = sz - 2; i >= 0; i--)dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
    }

    inline void update(int k, T x) {
        k += sz - 1;
        dat[k] = x;
        while (k) {
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    inline void add(int k, int x) {
        k += sz - 1;
        dat[k] = f(dat[k], x);
        while (k) {
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    inline T query(int a, int b) {
        return query(a, b, 0, 0, sz);
    }

    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)return ti;
        if (a <= l && r <= b)return dat[k];
        return f(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};

int main() {
    int n, q, h;
    cin >> n >> q >> h;

    auto f = [](ll i, ll j) { return i + j; };
    SegmentTree<ll, decltype(f)> segmentTree(f, 0);
    const int MAX = 200000 + 100;
    segmentTree.build(vector<ll>(MAX, 0));

    rep(i, n) {
        ll a;
        cin >> a;
        segmentTree.update(i, a);
    }

    int c = n;

    auto sum = [&]() -> ll {
        ll s = segmentTree.query(0, c);
        return s;
    };

    auto find_up = [&](ll a) -> int {

        int floor = 0, ceil = c;
        while (floor + 1 < ceil) {
            int mid = (floor + ceil) / 2;
            ll total = segmentTree.query(0, mid);
            bool ok = total <= a;
            if (ok) floor = mid;
            else ceil = mid;
        }
        return floor;
    };

    auto find_down = [&](ll a) -> int {

        int floor = 0, ceil = c;
        while (floor + 1 < ceil) {
            int mid = (floor + ceil) / 2;
            ll total = segmentTree.query(0, mid);
            bool ok = total < a;
            if (ok) floor = mid;
            else ceil = mid;
        }
        return floor;
    };


    rep(_, q) {
        string method;
        cin >> method;


//        cout << sum() << ' ';

        if (method == "challenge") {
            ll a;
            cin >> a;

            if (sum() <= a - h) {
                cout << "miss" << endl;
                continue;
            }

            int bottom = find_up(a - h);
            int top = find_down(a + h);

            if (bottom < c && (bottom == c - 1 || bottom == top)) {
                cout << "go" << endl;
                segmentTree.update(bottom, 0);
            } else {
                cout << "stop" << endl;
                continue;
            }
        } else {
            ll a;
            cin >> a;
            segmentTree.update(c, a);
            c++;
        }

    }
}
