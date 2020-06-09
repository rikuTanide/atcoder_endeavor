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

P knapsack(int k, vector<P> &tree_dp, vector<int> &children) {
    int n = children.size();
    vector<vector<P>> dp(n + 1, vector<P>(k + 1, P(-1, -1)));

    dp[0][0] = P(0, 0);

    auto set = [&](int i, P next) {
        if (next.first > k) return;
        if (dp[i][next.first] == P(-1, -1)) dp[i][next.first] = next;
        else if (dp[i][next.first].second > next.second) dp[i][next.first] = next;
    };

    rep(i, n) {
        rep(j, k + 1) {
            if (dp[i][j] == P(-1, -1)) continue;
            int cid = children[i];
            P next = tree_dp[cid];
            P from = dp[i][j];

            set(i + 1, P(from.first + next.first, from.second + next.second));
            set(i + 1, P(from.first + next.second, from.second + next.first));
        }
    }

    P ans = P(-1, -1);
    rep(i, k + 1) {
        P p = dp[n][i];
        if (p == P(-1, -1)) continue;
        if (ans == P(-1, -1)) ans = p;
        if (p.second < ans.second) ans = p;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    Tree tree(n);

    vector<vector<int>> g(n);
    rep(_, n - 1) {
        int i = _ + 1;
        int j;
        cin >> j;
        j--;

        tree.edge(i, j);
    }

    vector<int> k(n);
    rep(i, n) cin >> k[i];

    vector<P> dp(n, P(-1, -1));

    vector<Triangle> leafs;
    tree.root(0, leafs);

    for (Triangle &t: leafs) {
        P next = knapsack(k[t.parent], dp, t.children);
        if (next == P(-1, -1)) {
            cout << "IMPOSSIBLE" << endl;
            ret();
        }
        dp[t.parent] = P(k[t.parent], next.second);
    }

    cout << "POSSIBLE" << endl;
}