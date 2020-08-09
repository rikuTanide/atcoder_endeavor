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

// まず因数分解して、modをしたときの答えを出す。
// そこから、何回modを戻さないといけないかを求める
// 全部で何回modされたかを求める
// 各掛け算のmodは最大1回
// 割った数以下の個数が正統なmod
const int mod = 200003;

ll calc_all_mod(vector<ll> v) {
    ll sum = accumulate(v.begin(), v.end(), 0ll);

    ll ans = 0;
    for (ll l : v) {
        sum -= l;
        ll p = sum / mod;
        ll now = sum * l;
        if (now >= mod) p++;
        ans += p;
    }
    return ans;
}

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

ll calc_trad_mod(vector<ll> v) {

    vector<ll> imos(mod + 10);
    for (ll l : v) imos[l]++;

    auto f = [](ll i, ll j) { return i + j; };
    SegmentTree<ll, decltype(f)> segmentTree(f, 0);
    segmentTree.build(imos);

    ll ans = 0;
    for (ll l : v) {
        ll p = segmentTree.query(l, l + 1);
        p--;
        segmentTree.update(l, p);
        if (l == 0) continue;
        ll t = mod / l;
        ll q = segmentTree.query(t, mod + t);
        ans += q;
    }
    return ans;

}

int main() {

    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    ll sum = accumulate(v.begin(), v.end(), 0ll);

    ll ans = 0;
    for (ll l : v) {
        sum -= l;
        ll now = sum * l;
        now %= mod;
        ans += now;
//        ans %= mod;
    }

    ll am = calc_all_mod(v);

    ll tm = calc_trad_mod(v);

    ll sm = am - tm;

    ans += (mod * sm);

//    ans += mod;


//    cout << ans << endl << am << endl << tm << endl;
    cout << ans << endl;


}
