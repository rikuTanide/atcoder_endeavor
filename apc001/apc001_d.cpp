#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
typedef pair<ll, ll> P;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

    set<int> roots() {
        set<int> res;
        rep(i, parents.size()) if (i == root(i)) res.insert(i);
        return res;
    }

};


int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> values(n);
    rep(i, n)cin >> values[i];
    vector<P> edges(m);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
//        a--;
//        b--;
        edges[i].first = a;
        edges[i].second = b;
    }

    UnionFind uf(n);
    for (P p : edges) uf.connect(p.first, p.second);

    set<int> roots = uf.roots();
    if (roots.size() == 1) {
        cout << 0 << endl;
        ret();
    }

    map<int, vector<int>> children;
    rep(i, n) children[uf.root(i)].push_back(i);

    map<int, ll> min_vv;
    for (int p: roots) min_vv[p] = INF;
    rep(i, n) cmin(min_vv[uf.root(i)], values[i]);

    ll t = 0;
    for (auto e : min_vv) t += e.second;

    map<int, int> min_vi;
    rep(i, n) if (min_vv[uf.root(i)] == values[i]) min_vi[uf.root(i)] = i;

    set<int> min_vis;
    for (auto e : min_vi) min_vis.insert(e.second);

    vector<ll> v;
    rep(i, n) if (min_vis.find(i) == min_vis.end()) v.push_back(values[i]);
    sort(v.begin(), v.end());

    int f = 2 * (n - m - 1) - roots.size();

    if (f > v.size()) {
        cout << "Impossible" << endl;
        ret();
    }

    ll k = accumulate(v.begin(), v.begin() + f, 0ll);

    ll ans = k + t;
    cout << ans << endl;

}

