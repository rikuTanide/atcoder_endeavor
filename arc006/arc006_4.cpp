#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
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

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

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

int pow2(int a, int b) {
    ll res = a;
    for (ll i = 1; i < b; i++) {
        res *= a;
    }
    return res;
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w, ' '));
    rep(y, h) rep(x, w) cin >> grid[y][x];

    auto _get_multi = [&](int seed) {
        set<int> ans;
        for (int i = 1; seed * i * i <= h * w; i++) {
            ans.insert(seed * i * i);
        }
        return ans;
    };

    auto get_multi = [&]() {
        vector<set<int>> res = {
                _get_multi(12),
                _get_multi(16),
                _get_multi(11),
        };
        return res;
    };

    vector<set<int>> multis = get_multi();

    UnionFind uf(h * w);

    struct Direction {
        int x, y;
    };


    vector<Direction> directions = {
            {0,  1},
            {1,  1},
            {1,  0},
            {1,  -1},
            {0,  -1},
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0,  0},
    };

    auto reachable = [&](int y, int x) {
        if (x == -1 || x == w || y == -1 || y == h) return false;
        return grid[y][x] == 'o';
    };

    auto to_id = [&](int y, int x) {
        return y * w + x;
    };

    rep(y, h) rep(x, w) {
            if (grid[y][x] == '.') continue;
            for (Direction d : directions) {
                int ny = y + d.y;
                int nx = x + d.x;
                if (!reachable(ny, nx)) {
                    continue;
                }
                uf.connect(to_id(y, x), to_id(ny, nx));
            }
        }
    map<char, int> ans;

    auto get_type = [&](int size) {
        if (multis[0].find(size) != multis[0].end()) {
            return 'a';
        }
        if (multis[1].find(size) != multis[1].end()) {
            return 'b';
        }
        if (multis[2].find(size) != multis[2].end()) {
            return 'c';
        }
        __throw_runtime_error("konai");
    };

    rep(y, h) rep(x, w) {
            if (grid[y][x] == '.') continue;
            int r = to_id(y, x);
            if (uf.root(r) != r) continue;
            int size = uf.size(r);
            char t = get_type(size);
            ans[t]++;
        }

    printf("%d %d %d\n", ans['a'], ans['b'], ans['c']);

}

