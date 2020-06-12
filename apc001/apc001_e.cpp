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

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

struct Triangle {
    int parent;
    vector<int> children;
};

class Tree {
public:
    vector<vector<int>> edges;

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

    int max_v() {
        int v = 0;
        for (auto &e: edges) {
            cmax(v, (int) e.size());
        }
        return v;
    }

    int get_v(int v) {
        rep(i, edges.size()) {
            auto &e = edges[i];
            if (e.size() == v) return i;
        }
        return -1;
    }

};

int main() {
    int n;
    cin >> n;

    Tree tree(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;

        tree.edge(a, b);
    }


    if (tree.max_v() <= 2) {
        cout << 1 << endl;
        ret();
    }

    int root = tree.get_v(tree.max_v());

    vector<Triangle> leafs;
    tree.root(root, leafs);

    vector<int> dp(n, 0);

    for (auto &e : leafs) {

        if (e.children.size() == 0) {
            continue;
        }

        if (e.children.size() == 1) {
            int sum = dp[e.children[0]];
//            if (sum == 0) sum = 1;
            dp[e.parent] = sum;
            continue;
        }

        int sum = 0;

        for (int i : e.children) {
            sum += dp[i];
        }

        if (sum < (e.children.size() - 1)) {
            sum = e.children.size() - 1;
        }

        dp[e.parent] = sum;
    }


    cout << dp[root] << endl;
}