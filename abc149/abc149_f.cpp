#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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

//const ll mod = 1e10;
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

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

ll rec(int now,
       vector<vector<int>> &edges,
       vector<ll> &cnt,
       vector<bool> &ch,
       vector<ll> &par) {
    ll res = 0;
    for (auto nextp : edges[now]) {
        if (!ch[nextp]) {
            ch[nextp] = 1;
            par[nextp] = now;
            res += rec(nextp, edges, cnt, ch, par);
        }
    }
    return cnt[now] = res + 1;
}


mint solve(int n, vector<vector<int>> &edges) {
    mint res, two = 2;

    vector<ll> cnt(n, 0);
    vector<bool> ch(n, false);
    vector<ll> par(n, -1);

    ch[0] = 1;
    rec(0, edges, cnt, ch, par);
    for (int i = 0; i < n; ++i) {
        mint now = 0;
        long long sum = 0;
        for (auto nowp : edges[i])
            if (par[i] != nowp) {
                sum += cnt[nowp];
                now += two.pow(cnt[nowp]) - 1;
            }
        if (par[i] != -1) now += two.pow(n - sum - 1) - 1;
        res += two.pow(n - 1) - 1 - now;
    }
    return res / two.pow(n);
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> edges(n);

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    cout << solve(n, edges) << endl;
    return 0;
}



