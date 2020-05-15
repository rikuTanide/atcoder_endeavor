#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
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
    int n, m;
    cin >> n >> m;
    vector<int> as(n), bs(m);
    rep(i, n) cin >> as[i];
    rep(i, m) cin >> bs[i];
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());

    rep(i, n - 1) {
        if (as[i] == as[i + 1]) {
            cout << 0 << endl;
            ret();
        }
    }
    rep(i, m - 1) {
        if (bs[i] == bs[i + 1]) {
            cout << 0 << endl;
            ret();
        }
    }

    mint ans = 1;

    rep(_i, n * m) {
        int i = _i + 1;

        auto
                it_a = lower_bound(as.begin(), as.end(), i),
                it_b = lower_bound(bs.begin(), bs.end(), i);

        bool
                in_a = (*it_a) == i,
                in_b = (*it_b) == i;

        if (in_a && in_b) {
            continue;
        }

        if (in_a & (!in_b)) {
            int k = distance(it_b, bs.end());
            ans *= k;
            continue;
        }

        if ((!in_a) && in_b) {
            int k = distance(it_a, as.end());
            ans *= k;
            continue;
        }
        int k = distance(it_a, as.end());
        int l = distance(it_b, bs.end());

        ll t = k * l;
        ll f = n * m - i;

        ll now = t - f;

        ans *= now;
    }

    cout << ans << endl;
}