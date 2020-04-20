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

const int mod = 1000000007;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}

    mint &operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }

    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }

    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }

    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod - 2);
    }

    mint &operator/=(const mint a) {
        return (*this) *= a.inv();
    }

    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }

    friend std::istream &operator>>(std::istream &in, mint &o) {
        ll a;
        in >> a;
        o = a;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const mint &o) {
        out << o.x;
        return out;
    }

};


mint dfs(vector<vector<int>> &edges, vector<mint> &count, vector<bool> &visited, vector<bool> &calculated, int to) {
    if (visited[to]) {
        if (!calculated[to]) __throw_runtime_error("heiro nai");
        return count[to];
    }
    visited[to] = true;
    mint now = 1;
    for (int next : edges[to]) {
        mint r = dfs(edges, count, visited, calculated, next);
        now += r;
    }
    calculated[to] = true;
    count[to] += now;
    return count[to];
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> grid(h, vector<int>(w, 0));
    rep(y, h) rep(x, w) cin >> grid[y][x];


    struct Direction {
        int x, y;
    };


    auto reachable = [&](int x, int y, int nx, int ny) {
        if (nx == -1 || nx == w || ny == -1 || ny == h) return false;
        return grid[y][x] < grid[ny][nx];
    };

    vector<vector<int>> edges(h * w);

    vector<Direction> directions = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0},
    };

    auto to_id = [&](int y, int x) {
        return y * w + x;
    };

    rep(y, h) rep(x, w) for (Direction d : directions) {
                int ny = y + d.y;
                int nx = x + d.x;
                if (!reachable(x, y, nx, ny)) continue;
                edges[to_id(y, x)].push_back(to_id(ny, nx));
            }

    mint ans = 0;
    vector<mint> count(edges.size(), 0);
    vector<bool> visited(edges.size(), false);
    vector<bool> calculated(edges.size(), false);
    rep(i, edges.size()) {
        mint t = dfs(edges, count, visited, calculated, i);
        ans += t;
    }
    cout << ans << endl;
}
