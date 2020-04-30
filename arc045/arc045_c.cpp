#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

typedef pair<int, int> P;

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
//        reverse(leafs.begin(), leafs.end());
    }
};


int main() {
    ll n, x;
    cin >> n >> x;
    map<int, map<int, ll>> costs;

    Tree tree(n);

    rep(i, n - 1) {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        a--;
        b--;
        costs[a][b] = c;
        costs[b][a] = c;
        tree.edge(a, b);
    }

    vector<Triangle> leafs;
    tree.root(0, leafs);

    vector<ll> dp(n, 0);
    for (Triangle &triangle : leafs) {
        for (int child : triangle.children) {
            dp[child] = dp[triangle.parent] ^ costs[triangle.parent][child];
        }
    }

    map<ll, ll> m;
    for (ll l : dp) m[l]++;

    ll ans = 0;

    for (ll l : dp) {
        ll tar = l ^x;
        if (tar != l) ans += m[tar];
        else ans += m[tar] - 1;
    }
    cout << ans / 2 << endl;
}
