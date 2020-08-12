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

const int A = 12, B = 16, C = 11;

bool is_a(int g) {
    while (g % 9 == 0) g /= 9;
    return g % 3 == 0;
}

bool is_c(int g) {
    while (g % 9 == 0) g /= 9;
    return g % 11 == 0;
}

bool is_b(int g) {
    return !is_a(g) && !is_c(g);
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
    int h, w;
    cin >> h >> w;

    vector<vector<char>> board(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> board[y][x];

    UnionFind uf(h * w);

    rep(y, h) rep(x, w) {

            if (board[y][x] == '.')continue;

            auto to_id = [&](int y, int x) {
                return y * w + x;
            };

            struct Direction {
                int y, x;
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
                return true;
            };

            for (Direction d : directions) {
                int ny = y + d.y;
                int nx = x + d.x;

                if (!reachable(ny, nx)) continue;

                if (board[ny][nx] == 'o') {
                    uf.connect(to_id(y, x), to_id(ny, nx));
                }

            }

        }


    vector<int> groups;
    rep(i, h * w) {
        if (uf.root(i) != i || uf.size(i) == 1) continue;
        groups.push_back(uf.size(i));
    }
    int a = 0, b = 0, c = 0;
    for (int g : groups) {
        if (is_a(g)) a++;
        if (is_b(g)) b++;
        if (is_c(g)) c++;
    }
    printf("%d %d %d\n", a, b, c);

}
