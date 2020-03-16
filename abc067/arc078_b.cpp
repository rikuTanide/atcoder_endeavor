#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e15;
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

vector<int> route(int start, int end, int prev, vector<vector<int>> &edges) {
    if (start == end) return {end};

    for (int next : edges[start]) {
        if (next == prev) continue;
        vector<int> ans = route(next, end, start, edges);
        if (ans.empty()) continue;
        ans.push_back(start);
        return ans;
    }
    return {};
}

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
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> ans = route(0, n - 1, -1, edges);
    reverse(ans.begin(), ans.end());

    int bi = (ans.size() + 1) / 2 - 1;
    int wi = bi + 1;
    int w = ans[wi];
    int b = ans[bi];

    UnionFind uf(n);

    rep(from, n) {
        for (int to : edges[from]) {
            if (from == w && to == b) continue;
            if (from == b && to == w) continue;
            uf.connect(from, to);
        }
    }

    int ws = uf.size(w), bs = uf.size(b);

    if (ws == bs) {
        cout << "Snuke" << endl;
        ret();
    }

    if (ws < bs) {
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }


}

