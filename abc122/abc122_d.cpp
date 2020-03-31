#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;


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


bool check(string &s) {
    {
        string u = s.substr(0, 3);
        string v = s.substr(1, 3);
        if (u == "AGC") return false;
        if (v == "AGC") return false;
    }
    for (int i = 0; i < s.size() - 1; i++) {
        string t = s;
        swap(t[i], t[i + 1]);
        string u = t.substr(0, 3);
        string v = t.substr(1, 3);
        if (u == "AGC") return false;
        if (v == "AGC") return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    n -= 4;
    vector<map<string, mint>> dp(n + 1);

    vector<char> agct = {'A', 'G', 'C', 'T'};

    for (char c : agct) {
        for (char d : agct) {
            for (char e : agct) {
                for (char f : agct) {
                    string k = "";
                    k += c;
                    k += d;
                    k += e;
                    k += f;
                    if (!check(k)) continue;
                    dp[0][k] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (auto &e : dp[i]) {
            string s = e.first;
            mint k = e.second;
            string t = s.substr(1);
            for (char c : agct) {
                string f = t + c;
                if (!check(f)) continue;
                dp[i + 1][f] += k;
            }
        }
    }

    mint ans = 0;
    for (auto &e : dp.back()) {
        ans += e.second;
    }
    cout << ans << endl;

}
