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


int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<char>> grid(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> grid[y][x];

    rep(_, q) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        x1--;
        y1--;
        x2--;
        y2--;

        UnionFind uf(h * w);

        auto to_id = [&](int y, int x) {
            return y * w + x;
        };

        struct Direction {
            int y, x;
        };

        vector<Direction> directions = {
                {0,  1},
                {1,  0},
                {0,  -1},
                {-1, 0},
        };

        auto reachable = [&](int y, int x) {
            if (x < x1 || x2 < x || y < y1 || y2 < y) return false;
            if (grid[y][x] == '0') {
                return false;
            }
            return true;
        };

        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++) {
                if (grid[y][x] == '0') continue;
                for (Direction d : directions) {
                    int ny = y + d.y;
                    int nx = x + d.x;

                    if (!reachable(ny, nx)) continue;
                    int from_id = to_id(y, x);
                    int next_id = to_id(ny, nx);
                    uf.connect(from_id, next_id);
                }
            }
        }

        set<int> p;
        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++) {
                if (grid[y][x] == '0') continue;
                int from_id = to_id(y, x);
                p.insert(uf.root(from_id));
            }
        }

        cout << p.size() << endl;
    }
}
