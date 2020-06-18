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

const int mod = 998244353;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}

    mint &operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }

    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }

    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }

    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod - 2);
    }

    mint &operator/=(const mint a) {
        return (*this) *= a.inv();
    }

    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }

    friend std::istream &operator>>(std::istream &in, mint &o) {
        ll a;
        in >> a;
        o = a;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const mint &o) {
        out << o.x;
        return out;
    }

};

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

// 10
// 23
int main() {
    int n;
    cin >> n;

    vector<P> points(n);
    for (P &p: points) cin >> p.first >> p.second;

    Conv conv_y, conv_x;
    for (P p : points) conv_y.cache(p.first), conv_x.cache(p.second);
    conv_y.build();
    conv_x.build();

    for (P &p : points) p.first = conv_y.convert(p.first), p.second = conv_x.convert(p.second);

    sort(points.begin(), points.end());

    vector<vector<int>> counts(n, vector<int>(4, 0));

    {

        auto f = [](int i, int j) { return i + j; };
        SegmentTree<int, decltype(f)> segmentTree(f, 0);
        vector<int> imos(n, 0);
        segmentTree.build(imos);

        for (int i = 0; i < n; i++) {
            P p = points[i];
            int left = segmentTree.query(0, p.second);
            int right = segmentTree.query(p.second + 1, n);
            segmentTree.update(p.second, 1);

            counts[i][1] = left;
            counts[i][0] = right;
        }

    }

    {

        auto f = [](int i, int j) { return i + j; };
        SegmentTree<int, decltype(f)> segmentTree(f, 0);
        vector<int> imos(n, 0);
        segmentTree.build(imos);

        for (int i = n - 1; i >= 0; i--) {
            P p = points[i];
            int left = segmentTree.query(0, p.second);
            int right = segmentTree.query(p.second + 1, n);
            segmentTree.add(p.second, 1);

            counts[i][2] = left;
            counts[i][3] = right;
        }
    }

    mint ans = 0;
    rep(i, n) {

        // urdl
        const int u = 0, r = 1, d = 2, l = 3;


        rep(j, 1 << 4) {
            vector<bool> uses(4, false);
            rep(k, 4) {
                if (!((j >> k) & 1)) continue;
                if (k == 0) uses[u] = true, uses[r] = true;
                if (k == 1) uses[u] = true, uses[l] = true;
                if (k == 2) uses[d] = true, uses[l] = true;
                if (k == 3) uses[d] = true, uses[r] = true;
            }
            if (count(uses.begin(), uses.end(), false) > 0) continue;
            mint now = 1;
            rep(k, 4) {
                if (!((j >> k) & 1)) continue;
                now *= (mint(2).pow(counts[i][k]) - 1);
            }
            ans += now;
        }

        ans += mint(2).pow(n - 1);

    }

    cout << ans << endl;

}
