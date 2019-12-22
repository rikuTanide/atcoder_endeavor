#include <bits/stdc++.h>
#include <cmath>

#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

class Tree {
    vector<vector<int>> tree;

    bool getRouteRecursive(int start, int end, int before, int now, stack<int> &route) {
        if (now == end) return true;
        for (int i : tree[now]) {
            if (before == i) continue;
            route.push(i);
            bool b = getRouteRecursive(start, end, now, i, route);
            if (b) return true;
            route.pop();
        }
        return false;
    }

public:
    Tree(int n) {
        tree.resize(n);
    }

    void connect(int a, int b) {
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    stack<int> getRoute(int start, int end) {
        stack<int> route;
        route.push(start);

        for (int i : tree[start]) {
            route.push(i);
            bool b = getRouteRecursive(start, end, start, i, route);
            if (b) return route;
            route.pop();
        }
        __throw_runtime_error("konai");
    }


};

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

};

int main() {
    int n;
    cin >> n;

    vector<P> rc;
    Tree tree(n);

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        tree.connect(a, b);
        rc.emplace_back(a, b);
    }

    stack<int> route = tree.getRoute(0, n - 1);
    int *end = &route.top() + 1;
    int *begin = end - route.size();
    std::vector<int> route_v(begin, end);

    int fennec_i = (route_v.size() - 1) / 2;
    int sunuke_i = fennec_i + 1;

    int fennec = route_v[fennec_i];
    int sunuke = route_v[sunuke_i];

    UnionFind uf(n);

    for (auto r : rc) {
        if (r.first == fennec && r.second == sunuke) continue;
        if (r.second == fennec && r.first == sunuke) continue;
        uf.connect(r.first, r.second);
    }

    int fr = uf.root(0);
    int fp = uf.size(fr);

    int sr = uf.root(n - 1);
    int sp = uf.size(sr);

    if (fp > sp) {
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }

}