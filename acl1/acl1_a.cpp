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


int main() {
    int n;
    cin >> n;
    vector<P> v(n);
    for (P &p:v)cin >> p.first >> p.second;
    vector<P> u = v;

    sort(v.begin(), v.end());

    map<int, int> index;
    rep(i, n) index[v[i].second] = i;

    PQ_ASK q;
    q.push(v.front().second);

    UnionFind uf(n);

    rep(i, n) {
        if (i == 0) continue;

        int now = v[i].second;

        vector<int> mi;
        mi.push_back(now);
        while (!q.empty() && q.top() < now) {
            mi.push_back(q.top());
            q.pop();
        }

        for (int y : mi) uf.connect(index[y], i);
        int p = *min_element(mi.begin(), mi.end());
        q.push(p);
    }

    rep(i, n) {
        int h = u[i].second;
        int vi = index[h];
        cout << uf.size(vi) << endl;
    }

}
