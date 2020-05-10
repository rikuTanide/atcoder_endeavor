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

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

struct combination {
    vector<mint> fact, ifact;

    combination(int n) : fact(n + 1), ifact(n + 1) {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }

    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
} combination(1000000);

void solve(ll n, ll m, ll k) {
    if (n == 2 && m == 3 && k == 1) {
        cout << endl;
    }
    ll sukima = n - 1;

    mint start = m;
    rep(i, n - 1) start *= (m - 1);

    vector<mint> f(1000000);
    f[0] = m;
    rep(i, 1000000 - 1) f[i + 1] = f[i] * (m - 1);

    mint ans = start;
    rep(i, k) {

        ll block = n - i - 1;

//        mint f = m;
//        rep(j, block - 1) f *= (m - 1);

        mint c = combination(sukima, i + 1);
        mint now = c * f[block - 1];
//        mint now = c * start;
        ans += now;
    }
    cout << ans << endl;

}

void solve2(ll n, ll m, ll k) {
    queue<string> q;
    q.push("");

    vector<string> candidate;

    while (!q.empty()) {
        string t = q.front();
        q.pop();
        rep(i, m) {
            char c = '0' + i;
            string r = t + c;
            if (r.size() > n) continue;
            if (r.size() == n) {
                candidate.push_back(r);
            } else {
                q.push(r);
            }
        }
    }
    int ans = 0;
    for (string s : candidate) {
        int f = 0;
        rep(i, n - 1) {
            if (s[i] == s[i + 1]) f++;
        }
        if (f <= k) ans++;
    }
    cout << ans << endl;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
//    rep(n, 9)
//        rep(m, 9)
//            rep(k, 9) {

//                if (n == 0) continue;
//                if (m == 0) continue;
//                if (k > n - 1) continue;
//
//                printf("%d %d %d\n", n, m, k);
    solve(n, m, k);
//                solve2(n, m, k);
//                cout << endl;
//            }
}
