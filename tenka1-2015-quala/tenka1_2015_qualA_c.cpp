#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

struct BipartiteMatching {
    vector<vector<int> > graph;
    vector<int> match, alive, used;
    int timestamp;

    BipartiteMatching(int n) : graph(n), alive(n, 1), used(n, 0), match(n, -1), timestamp(0) {}

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool dfs(int idx) {
        used[idx] = timestamp;
        for (auto &to : graph[idx]) {
            int to_match = match[to];
            if (alive[to] == 0) continue;
            if (to_match == -1 || (used[to_match] != timestamp && dfs(to_match))) {
                match[idx] = to;
                match[to] = idx;
                return true;
            }
        }
        return false;
    }

    int bipartite_matching() {
        int ret = 0;
        for (int i = 0; i < graph.size(); i++) {
            if (alive[i] == 0) continue;
            if (match[i] == -1) {
                ++timestamp;
                ret += dfs(i);
            }
        }
        return ret;
    }

    void output() {
        for (int i = 0; i < graph.size(); i++) {
            if (i < match[i]) {
                cout << i << "-" << match[i] << endl;
            }
        }
    }
};

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> a(h, vector<char>(w)), b(h, vector<char>(w));

    rep(y, h) rep(x, w) cin >> a[y][x];
    rep(y, h) rep(x, w) cin >> b[y][x];

    BipartiteMatching bm(h * w);


    auto to_id = [&](int y, int x) {
        return y * w + x;
    };

    struct Direction {
        int y, x;
    };

    vector<Direction> directions = {
            {0, 1},
            {1, 0},
    };

    int all_change = [&]() -> int {
        int ans = 0;
        rep(y, h) rep(x, w) {
                if (a[y][x] != b[y][x]) ans++;
            }
        return ans;
    }();

    rep(y, h) rep(x, w) {


            auto reachable = [&](int y, int x) {
                if (x == -1 || x == w || y == -1 || y == h) return false;
                return true;
            };


            char pa = a[y][x];
            char pb = b[y][x];

            for (Direction d : directions) {
                int ny = y + d.y;
                int nx = x + d.x;
                if (!reachable(ny, nx)) {
                    continue;
                }

                char qa = a[ny][nx];
                char qb = b[ny][nx];

                if (pa == qa || pb == qb) {
                    continue;
                }

                if (pa == qb && pb == qa) {
                    bm.add_edge(to_id(y, x), to_id(ny, nx));
                }

            }

        }

    int sp = bm.bipartite_matching();

    int c = all_change - (sp * 2);

    int ans = sp + c;


    cout << ans << endl;


}
