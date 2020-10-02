#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
#include "atcoder/all"

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

// 各ブロック
struct S {
    mint a;
    int size;
};


struct F {
    int a;
};

vector<mint> ones;

S op(S l, S r) {

    int size = r.size;
    mint move = mint(10).pow(size);
    mint sum = l.a * move + r.a;

    return S{sum, l.size + r.size};
}

// 区間取得演算 op の単位元
S e() { return S{0, 0}; }

// lazyを反映
S mapping(F l, S r) {
    if (l.a == INT_MAX) return r;
    return S{ones[r.size] * l.a, r.size};
}

// lazy上書き
F composition(F l, F r) {
    if (l.a == INT_MAX) return r;
//    assert(l.a != INT_MAX);
    return l;
}

//区間操作演算 mapping における恒等写像
F id() {
    return {INT_MAX};
}


int main() {

    int n, q;
    cin >> n >> q;

    ones.resize(n + 1, 0);
    ones[1] = 1;
    for (int i = 2; i <= n; i++) {
        ones[i] = ones[i - 1] * 10 + 1;
    }

    vector<S> v(n, {1, 1});
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> segment_tree(v);

//    cout << segment_tree.all_prod().a << endl;

    rep(_, q) {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        segment_tree.apply(l, r, {d});
        cout << segment_tree.all_prod().a << endl;
//        cout << segment_tree.all_prod().size << endl;
//        rep(i, n) cout << segment_tree.prod(i, i + 1).a;
//        cout << ' ';
//        rep(i, n) cout << segment_tree.prod(i, i + 1).size;
//        cout << endl;
    }


}
