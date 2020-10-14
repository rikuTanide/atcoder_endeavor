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

class MatrixSum {
    vector<vector<ll>> sum;
    bool build_end = false;
public:
    MatrixSum(ll h, ll w) {
        sum = vector<vector<ll>>(h, vector<ll>(w));
    }

    void add(ll y, ll x, ll value) {
        assert(!build_end);
        sum[y][x] += value;
    }

    ll get(ll y, ll x) {
        assert(build_end);
        if (x == -1 || y == -1) {
            return 0;
        }
        if (y == sum.size() || x == sum[y].size()) {
            return 0;
        }
        return sum[y][x];
    }

    void setUp() {
        assert(!build_end);
        build_end = true;
        for (ll y = 0; y < sum.size(); y++) {
            for (ll x = 0; x < sum[y].size(); x++) {
                sum[y][x] += get(y - 1, x) + get(y, x - 1) - get(y - 1, x - 1);
            }
        }
    }

    ll getSum(ll ys, ll xs, ll ye, ll xe) {
        assert(build_end);
        return get(ye, xe) - get(ys - 1, xe) - get(ye, xs - 1) + get(ys - 1, xs - 1);
    }

};

// グラフ、頂点の入次数、頂点数を受け取り、そのトポロジカルソートを記録した配列を返す関数
vector<int> topological_sort(vector<vector<int>> &G, vector<int> indegree, int V) {
    // トポロジカルソートを記録する配列
    vector<int> sorted_vertices;

    // 入次数が0の頂点を発見したら、処理待ち頂点としてキューに追加する
    queue<int> que;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }

    // キューが空になるまで、操作1~3を繰り返す
    while (que.empty() == false) {
        // キューの先頭の頂点を取り出す
        int v = que.front();
        que.pop();

        // その頂点と隣接している頂点の入次数を減らし、0になればキューに追加
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i];
            indegree[u] -= 1;
            if (indegree[u] == 0) que.push(u);
        }
        // 頂点vを配列の末尾に追加する
        sorted_vertices.push_back(v);
    }

    // トポロジカルソートを返す
    return sorted_vertices;
}


int main() {
    int n, w, h;
    cin >> n >> w >> h;

    vector<vector<int>> board(h, vector<int>(w));
    rep(y, h) rep (x, h) cin >> board[y][x];

    vector<int> l(n + 1, w - 1), r(n + 1), t(n + 1, h - 1), b(n + 1);
    rep(y, h) rep (x, h) {
            int a = board[y][x];
            cmin(l[a], x);
            cmax(r[a], x);
            cmin(t[a], y);
            cmax(b[a], y);
        }

    vector<MatrixSum> mss(n + 1, MatrixSum(h, w));
    rep(y, h) rep (x, h) {
            int a = board[y][x];
            mss[a].add(y, x, 1);
        }
    rep(i, n + 1) mss[i].setUp();

    vector<vector<int>> g(n + 1);
    vector<int> indegree(n + 1);

    rep(i, n + 1) {
        rep(j, n + 1) {
            if (i == j) continue;
            int k = mss[j].getSum(t[i], l[i], b[i], r[i]);
            if (k > 0) {
                g[i].push_back(j);
                indegree[j]++;
            }
        }
    }

    vector<int> ans = topological_sort(g, indegree, n + 1);
    ans.erase(find(ans.begin(), ans.end(), 0));

    rep(i, n) {
        cout << ans[i];
        if (i == n - 1)cout << '\n';
        else cout << ' ';
    }

}
