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

struct Light {
    int l, r;
    ll cost;
};

std::istream &operator>>(std::istream &in, Light &o) {
    in >> o.l >> o.r >> o.cost;
    return in;
}

template<class T, class F>
struct SegmentTree {
    F f;
    T ti;
    vector<T> val;
    vector<T> dat;
    int sz;

    SegmentTree(const F &f, const T &ti) : f(f), ti(ti) {}

    void build(const vector<T> &v) {
        val = v;
        assert(v.size());
        sz = 1;
        while (sz < v.size())sz <<= 1;
        dat.resize(sz << 1, ti);
        for (int i = 0; i < v.size(); i++)dat[sz - 1 + i] = v[i];
        for (int i = sz - 2; i >= 0; i--)dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
    }

    inline void update(int k, T x) {
        val[k] = x;
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
    int n, l;
    cin >> n >> l;
    vector<Light> lights(n);
    rep(i, n) cin >> lights[i];

    sort(lights.begin(), lights.end(), [](Light l1, Light l2) {
        return l1.r < l2.r;
    });

    vector<ll> dp(l + 1, INF);
    dp[0] = 0;


    auto f = [](ll i, ll j) { return min(i, j); };
    SegmentTree<ll, decltype(f)> segmentTree(f, INF);
    segmentTree.build(dp);

    auto get = [&](int left, int right) -> ll {
        ll now = segmentTree.query(left, right);
        return now;
    };

    auto put = [&](int r, ll value) {
        ll now = segmentTree.query(r, r + 1);
        ll next = min(now, value);
        segmentTree.update(r, next);
    };

    rep(i, n) {
        Light light = lights[i];
        ll prev = get(light.l, light.r);
        ll next = prev + light.cost;
        put(light.r, next);
    }

    ll ans = segmentTree.query(l, l + 1);
    cout << ans << endl;
}
