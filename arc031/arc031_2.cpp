#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<int, int> P;
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


int main() {

    vector<vector<char>> islands(10, vector<char>(10));
    rep(y, 10)rep(x, 10) cin >> islands[y][x];

    UnionFind uf(100);

    struct Direction {
        int x, y;
    };

    vector<Direction> directions = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1},
    };

    auto is_islands = [&](int x, int y) {
        if (x == -1 || x == 10 || y == -1 || y == 10) return false;
        return islands[y][x] == 'o';
    };

    rep(y, 10) {
        rep(x, 10) {
            if (!is_islands(x, y)) continue;
            for (Direction d : directions) {
                int nx = x + d.x;
                int ny = y + d.y;
                if (is_islands(nx, ny)) uf.connect(10 * y + x, 10 * ny + nx);

            }
        }
    }

    int island_size = 0;
    rep(y, 10) {
        rep(x, 10) {
            if (!is_islands(x, y)) continue;
            island_size++;
        }
    }

    vector<int> cache = uf.parents;

    rep(y, 10) {
        rep(x, 10) {
            if (is_islands(x, y)) continue;
            if (uf.size(10 * y + x) == island_size) {
                cout << "YES" << endl;
                ret();
            }
        }
    }

    rep(y, 10) {
        rep(x, 10) {
            if (!is_islands(x, y)) continue;
            uf.parents = cache;
            for (Direction d : directions) {
                int nx = x + d.x;
                int ny = y + d.y;
                if (nx == -1 || nx == 10 || ny == -1 || ny == 10) continue;
                if (!is_islands(ny, nx)) continue;
                uf.connect(10 * y + x, 10 * ny + nx);
            }
            int size = uf.size(10 * y + x);
            if (size > island_size) {
                cout << "YES" << endl;
                ret();
            }
        }
    }
    cout << "NO" << endl;

}
