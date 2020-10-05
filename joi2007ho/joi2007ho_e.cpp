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
struct Triangle {
    int parent;
    vector<int> children;
};

class Tree {
    vector<vector<int>> edges;
public:
    Tree(int n) : edges(n) {}

    void edge(int i, int j) {
        edges[i].push_back(j);
        edges[j].push_back(i);
    }

    vector<Triangle> root(int r) {
        vector<Triangle> leafs;

        queue<int> vs;
        vs.push(r);
        vector<bool> check(edges.size(), false);
        check[r] = true;
        while (!vs.empty()) {
            int k = vs.front();
            Triangle triangle;
            triangle.parent = k;

            for (int i : edges[k]) {
                if (check[i]) continue;
                check[i] = true;
                triangle.children.push_back(i);
                vs.push(i);
            }
            vs.pop();
            leafs.push_back(triangle);
        }
        reverse(leafs.begin(), leafs.end());
        return leafs;

    }
};

struct Bar {
    ll l_size, r_size;
    int l_to, r_to;
};

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    int m;
    cin >> m;

    vector<Bar> bars(m);
    for (Bar &bar: bars) cin >> bar.l_size >> bar.r_size >> bar.l_to >> bar.r_to;
    for (Bar &bar: bars) {
        int g = __gcd(bar.r_size, bar.l_size);
        bar.r_size /= g;
        bar.l_size /= g;

        bar.l_to--;
        bar.r_to--;
    }


    Tree tree(m);
    rep(i, m) if (bars[i].l_to != -1) tree.edge(i, bars[i].l_to);
    rep(i, m) if (bars[i].r_to != -1) tree.edge(i, bars[i].r_to);

    int root = [&]() -> int {
        vector<bool> v(m, false);
        for (Bar bar : bars) if (bar.l_to != -1) v[bar.l_to] = true;
        for (Bar bar : bars) if (bar.r_to != -1) v[bar.r_to] = true;

        rep(i, m) if (!v[i]) return i;
    }();

    auto leafs = tree.root(root);


    auto calc = [](ll x, ll y) -> ll {
        if (x <= y) return 1;
        return (x + y - 1) / y;
    };


    vector<int> dp(m, 1);
    for (Triangle t : leafs) {
        Bar bar = bars[t.parent];

        ll l = bar.l_to == -1 ? 1 : dp[bar.l_to];
        ll r = bar.r_to == -1 ? 1 : dp[bar.r_to];

        ll lp = l * bar.l_size;
        ll rp = r * bar.r_size;
        ll g = lcm(lp, rp);

        ll y = g / lp;
        ll x = g / rp;

        ll ls = l * y;
        ll rs = r * x;

        ll sum = ls + rs;

        dp[t.parent] = sum;
    }

    cout << dp[root] << endl;


}
