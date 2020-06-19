#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
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

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


const int mod = 998244353;

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
    string s;
    cin >> n >> s;

    mint ans = 1;

    int r = 0, g = 0, b = 0;

    auto get = [&](char c) -> int {
        if (c == 'R') {
            return r;
        } else if (c == 'G') {
            return g;
        } else {
            return b;
        }
    };

    auto get_other_min = [&](char c) -> int {
        if (c == 'R') {
            return min(g, b);
        } else if (c == 'G') {
            return min(r, b);
        } else {
            return min(r, g);
        }
    };


    auto get_other_max = [&](char c) -> int {
        if (c == 'R') {
            return max(g, b);
        } else if (c == 'G') {
            return max(r, b);
        } else {
            return max(r, g);
        }
    };

    auto increment = [&](char c) {
        if (c == 'R') {
            r++;
        } else if (c == 'G') {
            g++;
        } else {
            b++;
        }
    };

    auto decrement_all = [&](char c) {
        r--;
        g--;
        b--;
    };

    rep(i, 3 * n) {
        char c = s[i];
        int me = get(c);
        int omin = get_other_min(c);
        int omax = get_other_max(c);

        increment(c);

        assert(omin <= omax);

        // 成立
        if (omin > 0 && omax > 0) {
            assert(me == 0);

            ans *= omin;
            decrement_all(c);
            continue;
        }

        if (omin == 0 && omax == 0) {
            continue;
        }

        assert(omin == 0 && omax > 0);

        if (omax > me) {
            ans *= (omax - me);
        }
    }

    rep(i, n) ans *= (i + 1);

    cout << ans << endl;

}