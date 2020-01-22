#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

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

vector<int> amida_simulator(vector<int> &horizontal, int width) {
    vector<int> currents(width);
    vector<int> current_indexes(width);
    rep(i, width) currents[i] = i;
    rep(i, width) current_indexes[i] = i;

    for (int h : horizontal) {
        int h1 = currents[h];
        int h2 = currents[h + 1];

        swap(current_indexes[h1], current_indexes[h2]);
        currents[h] = h2;
        currents[h + 1] = h1;

    }
    return current_indexes;
}

struct Doubling {
    const int LOG;
    vector<vector<int> > table;

    Doubling(int sz, int64_t lim_t) : LOG(64 - __builtin_clzll(lim_t)) {
        table.assign(LOG, vector<int>(sz, -1));
    }

    void set_next(int k, int x) {
        table[0][k] = x;
    }

    void build() {
        for (int k = 0; k + 1 < LOG; k++) {
            for (int i = 0; i < table[k].size(); i++) {
                if (table[k][i] == -1) table[k + 1][i] = -1;
                else table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    int query(int k, int64_t t) {
        for (int i = LOG - 1; i >= 0; i--) {
            if ((t >> i) & 1) k = table[i][k];
        }
        return k;
    }
};

int main() {

    int n, m, d;
    cin >> n >> m >> d;

//    assert(n <= 8);

    vector<int> horizontal(m);
    rep(i, m) {
        int a;
        cin >> a;
        a--;
        horizontal[i] = a;
    }
    vector<int> move_table = amida_simulator(horizontal, n);

    UnionFind uf(n);
    rep(i, n) uf.connect(i, move_table[i]);

    Doubling doubling(n, d);
    rep(i, n) doubling.set_next(i, move_table[i]);
    doubling.build();

    rep(i, n) {
        cout << doubling.query(i, d) + 1 << endl;
    }


}