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
struct Bridge {
    int from, to;
    ll cost;
};
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
            return leafs;
        }
//        reverse(leafs.begin(), leafs.end());
    }
};

void rec(vector<ll> &xo_sum, int from, int back, vector<vector<Bridge>> &g, ll sum) {
    xo_sum[from] = sum;

    for (Bridge b : g[from]) {
        int to = b.to;
        if (to == back) continue;
        rec(xo_sum, to, from, g, sum ^ b.cost);
    }
}

int main() {

    int n;
    ll x;
    cin >> n >> x;
    vector<Bridge> bridges(n - 1);
    for (Bridge &b: bridges) cin >> b.from >> b.to >> b.cost, b.from--, b.to--;

    vector<vector<Bridge>> g(n);
    for (Bridge &b: bridges) g[b.from].push_back(b);
    for (Bridge &b: bridges) g[b.to].push_back({b.to, b.from, b.cost});

    vector<ll> xo_sum(n, -1);
    xo_sum[0] = 0;
    rep(i, n) rec(xo_sum, 0, -1, g, 0);


    map<ll, ll> xo;
    rep(i, n) xo[xo_sum[i]]++;

    ll ans = 0;
    rep(i, n) {
        ll me = xo_sum[i];
        xo[me]--;
        ll pair = x ^me;

        ll now = xo[pair];
        ans += now;
    }
    cout << ans << endl;


}
