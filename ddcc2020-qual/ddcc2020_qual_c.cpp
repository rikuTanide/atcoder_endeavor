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

int to_id(int h, int w, int x, int y) {
    return w * y + x;
}

class Conv {
    ll cursor = 0;
    map<ll, ll> to_short; // <original, small >
    map<ll, ll> to_long; // <small, original>
    std::set<ll> tmp;


public:
    void set(ll original) {
        if (to_short.find(original) != to_short.end()) {
            return;
        }
        to_long[cursor] = original;
        to_short[original] = cursor;
        cursor++;
    }

    ll revert(ll after) {
        assert(to_long.find(after) != to_long.end());
        return to_long[after];
    }

    ll convert(ll original) {
        assert(to_short.find(original) != to_short.end());
        return to_short[original];
    }

    ll next() {
        return cursor;
    }

    // 前計算省略のため
    void cache(ll t) {
        tmp.insert(t);
    }

    void build() {
        for (ll t : tmp) {
            set(t);
        }
    }

};


int main() {
    int h, w, k;
    cin >> h >> w >> k;

    UnionFind uf(w * h);

    vector<vector<bool>> cake(h, vector<bool>(w, false));
    rep(y, h) rep(x, w) {
            char c;
            cin >> c;
            cake[y][x] = c == '#';
        }

    vector<bool> has_strawberry(h, false);
    rep(y, h) {
        rep(x, w) has_strawberry[y] = (has_strawberry[y] || cake[y][x]);
    }

    for (int y = 0; y < h; y++) {
        if (!has_strawberry[y]) continue;
        rep(x, w) {
            if (x == 0) continue;
            else if (cake[y][x - 1]) continue;
            else uf.connect(to_id(h, w, x - 1, y), to_id(h, w, x, y));
        }

        int last_s = -1;
        rep(x, w) if (cake[y][x]) last_s = x;
        assert(last_s != -1);
        if (last_s != w - 1) uf.connect(to_id(h, w, last_s + 1, y), to_id(h, w, last_s, y));
    }

    if (!has_strawberry[0]) {
        int ay = 0;
        for (int y = 1; y < h; y++) {
            if (has_strawberry[y]) {
                ay = y;
                break;
            }
        }

        assert(ay != 0);
        rep(x, w) uf.connect(to_id(h, w, x, ay), to_id(h, w, x, 0));
        
    }
    rep(y, h) {
        if (y == 0) continue;
        if (has_strawberry[y]) continue;
        rep(x, w) uf.connect(to_id(h, w, x, y - 1), to_id(h, w, x, y));
    }
    Conv conv;
    rep(y, h) {
        rep(x, w) {
            int k = uf.root(to_id(h, w, x, y));
            conv.cache(k);
        }
    }
    conv.build();

    rep(y, h) {
        rep(x, w) {
            int k = uf.root(to_id(h, w, x, y));
            k = conv.convert(k);
            cout << k + 1 << ' ';
        }
        cout << endl;
    }
}
