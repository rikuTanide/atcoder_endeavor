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

class UnionFind {
public:
    // 親の番号を格納する。親だった場合-size
    vector<int> parents;

    UnionFind(int n) {
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
};

bool is_possible(int n, vector<P> &edges) {
    UnionFind uf(n);
    for (P p:edges)uf.connect(p.first, p.second);
    int island = 0;
    rep(i, n) if (uf.root(i) == i) island++;
    int need = (island - 1) * 2;
    return n >= need;
}

ll solve(int n, vector<ll> &values, vector<P> &edges) {
    UnionFind uf(n);
    for (P p:edges)uf.connect(p.first, p.second);

    if (uf.size(0) == n) {
        return 0;
    }

    set<int> needs = [&]() -> set<int> {
        map<int, ll> m;// m[parent] = min

        rep(i, n) {
            int parent = uf.root(i);
            if (m.find(parent) == m.end()) {
                m[parent] = values[i];
            } else {
                cmin(m[parent], values[i]);
            }
        }

        map<int, ll> a;
        rep(i, n) {
            int parent = uf.root(i);
            if (m[parent] == values[i]) a[parent] = i;
        }

        set<int> s;
        for (auto e : a) {
            s.insert(e.second);
        }
        return s;
    }();

    vector<int> t(n);
    rep(i, n) t[i] = i;

    auto mkp = [&](int i) -> P {
        int is_primary = needs.find(i) != needs.end() ? 0 : 1;// trueならzero
        ll value = values[i];
        return P(is_primary, value);
    };

    sort(t.begin(), t.end(), [&](int i, int j) {
        P a = mkp(i);
        P b = mkp(j);
        return a < b;
    });

    int island = 0;
    rep(i, n) if (uf.root(i) == i) island++;

    ll ans = 0;
    rep(i, 2 * (island - 1)) ans += values[t[i]];
    return ans;

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> values(n);
    rep(i, n) cin >> values[i];
    vector<P> edges(m);
    for (P &p: edges)cin >> p.first >> p.second;

    bool possible = is_possible(n, edges);
    if (!possible) {
        cout << "Impossible" << endl;
        ret();
    }

    ll ans = solve(n, values, edges);
    cout << ans << endl;
}
