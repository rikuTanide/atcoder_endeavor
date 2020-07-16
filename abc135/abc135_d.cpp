#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
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


bool dfs(int now,
         int prev,
         int k,
         int grand_parent_pattern,
         int parent_pattern,
         int elder_brother_count,
         vector<vector<int>> &edges,
         vector<int> &ans) {

    int t = k - grand_parent_pattern - parent_pattern - elder_brother_count;
    if (t <= 0) return false;

    int i = 0;
    for (int next : edges[now]) {
        if (next == prev) continue;
        int ok = dfs(next, now, k, parent_pattern, 1, i, edges, ans);
        if (ok == -1) return false;
        i++;
    }

    ans[now] = t;
    return true;
}

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


int main() {
    string s;
    cin >> s;
    vector<mint> prev(13, 0);
    prev[0] = 1;

    for (char c : s) {
        if (c == '?') {
            vector<mint> next(13);
            rep(i, 10) {
                rep(j, 13) {
                    int ni = (j * 10 + i) % 13;
                    next[ni] += prev[j];
                }
            }
            prev = next;
        } else {
            int i = c - '0';


            vector<mint> next(13);
            rep(j, 13) {
                int ni = (j * 10 + i) % 13;
                next[ni] += prev[j];
            }
            prev = next;

        }
    }

    cout << prev[5] << endl;

}