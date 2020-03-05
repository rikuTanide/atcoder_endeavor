#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
const ll INF = 1e15;
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
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

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
    int n;
    cin >> n;

    Tree tree(n);
    vector<P> edges(n - 1);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tree.edge(a, b);
        edges[i].first = a;
        edges[i].second = b;
    }


    vector<int> parent_colors(n, -1);
    map<int, map<int, int>> edge_colors;

    vector<Triangle> leafs;
    tree.root(0, leafs);


    for (Triangle &t : leafs) {
        int color = 0;
        for (int child : t.children) {
            if (color == parent_colors[t.parent]) color++;
            parent_colors[child] = color;
            edge_colors[t.parent][child] = color;
            edge_colors[child][t.parent] = color;
            color++;
        }
    }

    int cc = *max_element(parent_colors.begin(), parent_colors.end());
    cc++;
    cout << cc << endl;

    for (P p : edges) {
        cout << edge_colors[p.first][p.second] + 1 << endl;
    }

}
