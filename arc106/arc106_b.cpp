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


class UnionFind {
public:
    // 親の番号を格納する。親だった場合-size
    vector<int> parents;
    int n;

    UnionFind(int n) : n(n) {
        parents = vector<int>(n, -1);
    }

    // aがどのグループに属しているか
    int root(int a) {
        if (parents[a] < 0) {
            return a;
        }
        return parents[a] = root(parents[a]);
    }

    int size(int a) {
        return -parents[root(a)];
    }

    // aとbをくっつける
    bool connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra == rb) {
            return false;
        }
        // 大きいほうにA
        if (size(ra) < size(rb)) {
            swap(ra, rb);
        }
        parents[ra] += parents[rb];
        parents[rb] = ra;
        return true;
    }

    bool is_union(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        return ra == rb;
    }

    int parent_count() {
        int ans = 0;
        rep(i, n) {
            if (root(i) == i) ans++;
        }
        return ans;
    }

};


bool solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> as(n), bs(n);
    rep(i, n) cin >> as[i];
    rep(i, n) cin >> bs[i];

    vector<P> edges(m);
    for (P &p:edges)cin >> p.first >> p.second, p.first--, p.second--;

    // 合計が合わなければダメ
    ll asum = accumulate(as.begin(), as.end(), 0ll);
    ll bsum = accumulate(bs.begin(), bs.end(), 0ll);
    if (asum != bsum) return false;


    UnionFind uf(n);
    for (P p : edges) uf.connect(p.first, p.second);

    if (uf.parent_count() != 1) {
        throw_with_nested("mada");
    }

    return true;

    // 隣り合う辺の偶奇が会わなければダメ

}

int main() {
    cout << (solve() ? "Yes" : "No") << endl;

}
