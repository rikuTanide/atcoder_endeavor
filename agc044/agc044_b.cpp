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

const int mod = 1000000007;


struct Direction {
    int y, x;
};

vector<Direction> directions = {
        {0,  1},
        {1,  0},
        {0,  -1},
        {-1, 0},
};


bool reachable(int y, int x, int n) {
    if (x == -1 || x == n || y == -1 || y == n) return false;
    return true;
}


int main() {

    int n;
    cin >> n;

    vector<int> ps(n * n);
    vector<vector<int>> theater(n, vector<int>(n));
    vector<vector<bool>> is_exists(n, vector<bool>(n, true));

    rep(i, n * n) cin >> ps[i], ps[i]--;

    rep(y, n) rep(x, n) theater[y][x] = min({n - 1 - x, x, n - 1 - y, y});

    auto update = [&](int ys, int xs) -> void {
        queue<P> q;
        q.push(make_pair(ys, xs));
        while (!q.empty()) {
            P p = q.front();
            ll y = p.first, x = p.second;
            q.pop();

            for (Direction d : directions) {
                ll ny = y + d.y;
                ll nx = x + d.x;
                if (!reachable(ny, nx, n)) continue;

                if (theater[ny][nx] > theater[y][x] + is_exists[y][x]) {
                    theater[ny][nx] = theater[y][x] + is_exists[y][x];
                    q.push(make_pair(ny, nx));
                }

            }

        }
    };

    int ans = 0;
    rep(k, n * n) {
        int sy = ps[k] / n;
        int sx = ps[k] % n;

        ans += theater[sy][sx];
        is_exists[sy][sx] = false;
        update(sy, sx);
    }
    cout << ans << endl;
}
