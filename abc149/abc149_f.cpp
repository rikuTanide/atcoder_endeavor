#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
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
};


ll dfs(ll from, ll parent, vector<vector<ll>> &tos, vector<ll> &child_count) {

    ll total = 1;
    for (ll next : tos[from]) {
        if (next == parent) continue;
        ll count = dfs(next, from, tos, child_count);
        total += count;
    }
    child_count[from] = total;
    return total;
}

int main() {
    ll n;
    cin >> n;
    vector<P> edges;

    vector<vector<ll>> tos(n);
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges.emplace_back(a, b);
        tos[a].push_back(b);
        tos[b].push_back(a);
    }

    vector<ll> child_count(n);
    dfs(0, -1, tos, child_count);

    vector<mint> pow(n + 1), inv(n + 1);
    pow[0] = 1;
    inv[0] = 1;
    rep(i, n) {
        pow[i + 1] = pow[i] * 2;
        inv[i + 1] = pow[i + 1].inv();
    }

    mint ev = 1;
    for (P p : edges) {
        ll a = p.first;
        ll b = p.second;

        ll na = min(child_count[a], child_count[b]);
        ll nb = n - na;

        ev += (mint(1) - inv[na]) * (mint(1) - inv[nb]);

    }

    mint ans = ev - inv[1] * n - inv[n];
    cout << ans.x << endl;
}
