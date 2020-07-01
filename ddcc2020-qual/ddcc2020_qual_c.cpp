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
    auto to_id = [&](int y, int x) {
        return y * w + x;
    };

    vector<vector<char>> cake(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> cake[y][x];

    vector<bool> has_row(h);
    rep(y, h) has_row[y] = count(cake[y].begin(), cake[y].end(), '#') > 0;

    UnionFind uf(w * h);

    rep(y, h) rep(x, w) {
            if (has_row[y])continue;
            if (y == 0)continue;
            uf.connect(to_id(y, x), to_id(y - 1, x));
        }

    int first_has_row = distance(has_row.begin(), find(has_row.begin(), has_row.end(), true));
    rep(x, w) {
        uf.connect(to_id(first_has_row, x), to_id(0, x));
    }

    rep(y, h) rep(x, w) {
            if (!has_row[y])continue;
            if (x == w - 1)continue;
            if (cake[y][x] == '#') continue;
            uf.connect(to_id(y, x), to_id(y, x + 1));
        }

    rep(y, h) {
        if (!has_row[y])continue;
        int last_s = 0;
        rep(x, w) {
            if (cake[y][x] == '#') last_s = x;
        }
        uf.connect(to_id(y, last_s), to_id(y, w - 1));
    }


    Conv conv;
    rep(y, h)rep(x, w) conv.cache(uf.root(to_id(y, x)));
    conv.build();

    vector<vector<int>> ans(h, vector<int>(w));
    rep(y, h)rep(x, w) ans[y][x] = conv.convert(uf.root(to_id(y, x))) + 1;

    rep(y, h) {
        rep(x, w) {
            cout << ans[y][x] << ' ';
        }
        cout << endl;
    }

    cout << endl;

}
