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
    vector<int> befores;

    deque<int> q;


    void insertTask(int now) {
        for (int i : tree[now]) {
            if (befores[now] == i) continue;
            befores[i] = now;
            q.push_back({i});
        }
    }

    vector<int> routeFrom(int start, int end) {
        int now = end;
        vector<int> route;
        route.push_back(end);
        while (now != start) {
            now = befores[now];
            route.push_back(now);
        }
        reverse(route.begin(), route.end());
        return route;
    }

    vector<int> dfs(int start, int end) {

        q.push_back({start});

        while (!q.empty()) {
            int t = q.front();
            if (t == end) {
                return routeFrom(start, end);
            }
            q.pop_front();
            insertTask(t);
        }
        __throw_runtime_error("korenai");
    }

public:
    Tree(int n) {
        tree.resize(n);
        befores.resize(n, -1);
    }

    void connect(int a, int b) {
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> getRoute(int start, int end) {
        return dfs(start, end);
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

//    ifstream myfile("C:\\Users\\riku\\Downloads\\08.txt");

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

    vector<int> route = tree.getRoute(0, n - 1);

    int fennec_i = (route.size() - 1) / 2;
    int sunuke_i = fennec_i + 1;

    int fennec = route[fennec_i];
    int sunuke = route[sunuke_i];

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