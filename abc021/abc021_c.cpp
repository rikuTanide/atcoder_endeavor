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

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int m;
    cin >> m;

    a--;
    b--;

    vector<vector<int>> routes(n);

    rep(i, m) {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        routes[x].push_back(y);
        routes[y].push_back(x);

    }

    vector<int> min_distances(n, INT_MAX);
    min_distances[a] = 0;
    {

        struct Move {
            int from;
            int depth;
        };

        queue<Move> q;
        q.push({a, 0});
        while (!q.empty()) {
            Move p = q.front();
            q.pop();
            for (int to : routes[p.from]) {
                int next_depth = p.depth + 1;
                if (min_distances[to] > next_depth) {
                    min_distances[to] = next_depth;
                    q.push({to, next_depth});
                }
            }
        }
    }

    vector<mint> patterns(n, 0);
    patterns[a] = 1;
    {

        struct Move {
            int from;
            int depth;
        };
        vector<bool> visited(n, false);
        queue<Move> q;
        q.push({a, 0});
        while (!q.empty()) {
            Move p = q.front();
            q.pop();
            for (int to : routes[p.from]) {
                int next_depth = p.depth + 1;
                if (min_distances[to] != next_depth) {
                    continue;
                }
                patterns[to] += patterns[p.from];
                if (!visited[to]) {
                    q.push({to, next_depth});
                    visited[to] = true;
                }
            }
        }
    }
    cout << patterns[b] << endl;
}
