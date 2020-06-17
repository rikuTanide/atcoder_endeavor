#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

P path(int a, int b) {
    if (b > a) swap(a, b);
    return P(a, b);
}

void dfs1(vector<vector<int>> &edges, int now, int prev, set<P> &tree_edges, vector<bool> &visited) {
    if (visited[now]) return;
    visited[now] = true;

    for (int next : edges[now]) {
        if (next == prev) continue;
        if (visited[next]) continue;
        tree_edges.insert(path(now, next));
        dfs1(edges, next, now, tree_edges, visited);
    }

}

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

    void root(int r, vector<Triangle> &leafs) {
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
    }
};


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n);
    rep(_, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    if (m % 2 == 1) {
        cout << -1 << endl;
        ret();
    }

    set<P> tree_edges;
    {
        vector<bool> visited(n, false);
        dfs1(edges, 0, -1, tree_edges, visited);
    }

    vector<vector<int>> ans_edges(n);

    {
        set<P> other_edges;
        // 木に入らない辺
        rep(i, n) {
            for (int to : edges[i]) {
                if (tree_edges.find(path(i, to)) == tree_edges.end()) {
                    other_edges.insert(path(i, to));
                }
            }
        }

        for (P p : other_edges) {
            ans_edges[p.first].push_back(p.second);
        }
    }

    Tree tree(n);
    for (P p : tree_edges) tree.edge(p.first, p.second);
    vector<Triangle> leafs;
    tree.root(0, leafs);

    for (Triangle &t: leafs) {
        for (int c : t.children) {
            if (ans_edges[c].size() % 2 == 1) ans_edges[c].push_back(t.parent);
            else ans_edges[t.parent].push_back(c);
        }
    }


    rep(i, n) {
        for (int to : ans_edges[i]) {
            cout << i + 1 << ' ' << to + 1 << endl;
        }
    }

}

