#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, int> P;
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
    int n;
    cin >> n;

    vector<ll> ths(n), ahs(n);
    rep(i, n)cin >> ths[i];
    rep(i, n) cin >> ahs[i];


    vector<bool> determinate(n);
    determinate.front() = true;
    determinate.back() = true;

    vector<ll> min_heights(n);
    rep(i, n) min_heights[i] = min(ths[i], ahs[i]);

    for (int i = 1; i < n; i++) {
        if (ths[i - 1] < ths[i]) {
            if (ahs[i] < ths[i]) {
                cout << 0 << endl;
                ret();
            }
        }
    }

    for (int i = n - 1 - 1; i >= 0; i--) {
        if (ahs[i] > ahs[i + 1]) {
            if (ths[i] < ahs[i]) {
                cout << 0 << endl;
                ret();
            }
        }
    }


    for (int i = 1; i < n; i++) {
        if (ths[i - 1] < ths[i]) determinate[i] = true;
    }
    for (int i = n - 1 - 1; i >= 0; i--) {
        if (ahs[i] > ahs[i + 1]) determinate[i] = true;
    }

    mint ans = 1;
    rep(i, n) {
        if (determinate[i]) continue;
        ans *= min_heights[i];
    }
    cout << ans << endl;

}