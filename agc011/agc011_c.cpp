#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

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

    vector<int> get_parents() {
        vector<int> v;
        rep(i, parents.size()) if (i == root(i)) v.push_back(i);
        return v;
    }

};

// 二部グラフ判定
bool dfs(vector<vector<int>> &G, vector<int> &color, int v, int cur = 0) {
    color[v] = cur;
    for (auto next_v : G[v]) {
        // 隣接頂点がすでに色確定していた場合
        if (color[next_v] != -1) {
            if (color[next_v] == cur) return false; // 同じ色が隣接したらダメ
            continue;
        }

        // 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
        if (!dfs(G, color, next_v, 1 - cur)) return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<P> v(m);
    rep(i, m) cin >> v[i].first >> v[i].second;

    for (P &p : v) p.first--, p.second--;

    UnionFind uf(n);
    for (P p : v) uf.connect(p.first, p.second);

    vector<vector<int>> edges(n);
    for (P p: v) edges[p.first].push_back(p.second);
    for (P p: v) edges[p.second].push_back(p.first);

    vector<int> parents = uf.get_parents();

    ll alone = 0, odd = 0, even = 0;

    vector<int> color(n, -1);


    for (int i : parents) {
        if (uf.size(i) == 1) {
            alone++;
        } else if (dfs(edges, color, i)) {
            even++;
        } else {
            odd++;
        }
    }

    ll a = alone * alone;
    ll b = alone * (n - alone);
    ll c = b;
    ll d = odd * odd;
    ll e = even * odd;
    ll f = odd * even;
    ll g = even * even * 2;

    ll ans = a + b + c + d + e + f + g;


    cout << ans << endl;
}
