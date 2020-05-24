#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
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

ll gcd(ll x, ll y) {
    x = abs(x);
    y = abs(y);
    if (x > y) swap(x, y);
    ll m = 1;
    while (m != 0) {
        m = y % x;
        y = x;
        x = m;
    }
    return y;
}

mint cou(vector<P> ps) {
    map<P, int> m;
    for (P p : ps) m[p]++;

    vector<int> c;
    for (auto &e : m) c.push_back(e.second);
    if (c.size() == 1) {
        return mint(2).pow(c.front());
    } else {
        assert(c.size() == 2);
        return mint(2).pow(c.front()) + mint(2).pow(c.back()) - 1;
    }

}

mint couzz(vector<P> ps) {
    int ans = 0;
    for (P p : ps) {
        if (p == P(0, 0)) ans++;
    }
    return ans;
}

mint couzo(vector<P> ps) {
    vector<P> tmp;
    for (P p : ps) {
        if (p == P(0, 0)) continue;
        if (p.first == 0 || p.second == 0) tmp.push_back(p);
    }
    if (tmp.empty()) return 1;
    return cou(tmp);
}

vector<P> filter_zero(vector<P> ps) {
    vector<P> tmp;
    for (P p : ps) {
        if (p.first == 0 || p.second == 0) continue;
        tmp.push_back(p);
    }
    return tmp;
}

int main() {
    int n;
    cin >> n;

    vector<P> sardines(n);
    rep(i, n) cin >> sardines[i].first >> sardines[i].second;

    mint zz = couzz(sardines);
    mint zo = couzo(sardines);

    sardines = filter_zero(sardines);

    n = sardines.size();
    rep(i, n) {
        ll g = gcd(sardines[i].first, sardines[i].second);
        sardines[i].first /= g;
        sardines[i].second /= g;

        if (sardines[i].first < 0 && sardines[i].second < 0) {
            sardines[i].first = -sardines[i].first;
            sardines[i].second = -sardines[i].second;
        } else if (sardines[i].first > 0 && sardines[i].second < 0) {
            sardines[i].first = -sardines[i].first;
            sardines[i].second = -sardines[i].second;
        }
    }

    for (P p : sardines) assert(p.first > 0 && p.second > 0 || p.first < 0 && p.second > 0);

    map<P, vector<P>> m;

    auto norm = [](P p) {
        if (p.first >= 0 && p.second >= 0) return p;
        else {
            P q(p.second, -p.first);
            assert(p.first * q.first + p.second * q.second == 0);
            return q;
        }
    };

    for (P p : sardines) {
        P r = norm(p);
        if (m.find(p) != m.end()) m[p].push_back(p);
        else if (m.find(r) != m.end()) m[r].push_back(p);
        else m[r].push_back(p);
    }

    mint ans = zo;
    for (auto &e : m) {
        mint now = cou(e.second);
        ans *= now;
    }
    ans = ans + zz;
    ans = ans - 1;
    cout << ans << endl;

}
