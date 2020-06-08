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


struct Seg {
    int min_value, left, right;
};

bool operator<(Seg s1, Seg s2) {
    return s1.min_value < s2.min_value;
}

bool operator>(Seg s1, Seg s2) {
    return s1.min_value > s2.min_value;
}

typedef priority_queue<Seg, vector<Seg>, greater<Seg> > PQ_ASK;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];


    auto f = [](ll i, ll j) { return min(i, j); };
    SegmentTree<ll, decltype(f)> odd_min_st(f, INF), even_min_st(f, INF);
    {
        vector<ll> u1(n), u2(n);
        rep(i, n) {
            if (i % 2 == 0) u1[i] = v[i], u2[i] = INF;
            else u1[i] = INF, u2[i] = v[i];
        }
        even_min_st.build(u1);
        odd_min_st.build(u2);
    }

    auto get_even_tree = [&](int l) -> SegmentTree<ll, decltype(f)> & {
        if (l % 2 == 0) return even_min_st;
        return odd_min_st;
    };

    auto get_odd_tree = [&](int l) -> SegmentTree<ll, decltype(f)> & {
        if (l % 2 == 1) return even_min_st;
        return odd_min_st;
    };

    map<int, int> m;
    rep(i, n) m[v[i]] = i;
    auto get_mi_index = [&](int vi) {
        return m[vi];
    };

    PQ_ASK q;

    auto push = [&](int l, int r) {
        assert(l <= r);
        assert((r - l) % 2 == 0);
        if (l == r) return;

        SegmentTree<ll, decltype(f)> &even_st = get_even_tree(l);
        int mi = even_st.query(l, r);

        q.push(Seg{mi, l, r});
    };

    push(0, n);

    while (!q.empty()) {
        Seg top = q.top();
        q.pop();

        cout << top.min_value << endl;
        int mi_i = get_mi_index(top.min_value);

        SegmentTree<ll, decltype(f)> &st = get_odd_tree(top.left);
        int mi2 = st.query(mi_i + 1, top.right);
        cout << mi2 << endl;

        int mi2_i = get_mi_index(mi2);

        push(top.left, mi_i);
        push(mi_i + 1, mi2_i);
        push(mi2_i + 1, top.right);

    }

    cout << endl;

}
