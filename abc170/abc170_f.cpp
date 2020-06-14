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

int main() {


    int h, w, k;
    cin >> h >> w >> k;

    int sx, sy, gx, gy;
    cin >> sy >> sx >> gy >> gx;
    sx--;
    sy--;
    gx--;
    gy--;

    vector<vector<char>> lake(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> lake[y][x];

    vector<vector<ll>> costs(h, vector<ll>(w, INF));

    costs[sy][sx] = 0;
    struct Point {
        ll y, x, cost;
    };

    queue<Point> q;
    q.push({sy, sx, 0});

    struct Direction {
        int y, x;
    };

    vector<Direction> directions = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0},
    };


    auto reachable = [&](int y, int x, ll distance) {
        if (x == -1 || x == w || y == -1 || y == h) return false;
        if (lake[y][x] == '@') {
            return false;
        }
        if (costs[y][x] <= distance) {
            return false;
        }
        return true;
    };


    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        for (Direction d : directions) {
            for (int f = 1; f <= k; f++) {
                int nx = p.x + (d.x * f);
                int ny = p.y + (d.y * f);
                ll nd = p.cost + 1;
                if (reachable(ny, nx, nd)) {
                    if (ny == 3) {
                        cout << endl;
                    }
                    costs[ny][nx] = nd;
                    q.push({ny, nx, nd});
                } else {
                    if (nx == -1 || nx == w || ny == -1 || ny == h) break;
                    if (lake[ny][nx] == '@') break;
                }
            }
        }
    }


    cout << (costs[gy][gx] >= INF ? -1 : costs[gy][gx]) << endl;
}
