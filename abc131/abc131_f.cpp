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

const int ma = 1e6;

int main() {
    int n;
    cin >> n;
    vector<P> v(n);
    for (P &p:v)cin >> p.first >> p.second;

    UnionFind uf(2 * ma);
    auto connect = [&](int y, int x) {
        uf.connect(y, int(x + ma));
    };

    auto root_y = [&](int i) {
        return uf.root(i);
    };

    auto root_x = [&](int i) {
        return uf.root(i + int(ma));
    };

//    map<int, int> use_horizontal, use_vertical;
//    for (P p : v) use_vertical[p.first]++;
//    for (P p : v) use_horizontal[p.second]++;

    for (P p : v) {
//        if (use_vertical[p.first] > 1 && use_horizontal[p.second] > 1) {
        connect(p.first, p.second);
//        }
    }


    map<int, P> m;
    rep(i, ma) m[root_y(i)].first++;
    rep(i, ma) m[root_x(i)].second++;

    auto is_union = [&](ll y, ll x) -> bool {
        return uf.is_union(y, x + int(ma));
    };

    ll ans = 0;
    for (auto e : m) ans += e.second.first * e.second.second;

//    for (P p: v) if (is_union(p.first, p.second)) ans--;
    ans -= n;
    cout << ans << endl;

}
