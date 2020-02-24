#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
const ll INF = 1e15;
//const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;
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
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

bool checkEven(vector<int> &numbers, int n) {
    for (int i = 0; i < numbers.size(); i++) {
        if (i % 2 == 0 && numbers[i] != 0) return false;
        if (i % 2 == 1 && numbers[i] != 2) return false;
    }
    return true;
}

bool checkOdd(vector<int> &numbers, int n) {
    if (numbers[0] != 1)return false;
    for (int i = 1; i < numbers.size(); i++) {
        if (i % 2 == 0 && numbers[i] != 2) return false;
        if (i % 2 == 1 && numbers[i] != 0) return false;
    }
    return true;
}

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

vector<pair<ll, int >> factorize(ll n) {
    vector<pair<ll, int >> res;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        res.emplace_back(i, 0);
        while (n % i == 0) {
            n /= i;
            res.back().second++;
        }
    }

    if (n != 1) res.emplace_back(n, 1);
    return res;

}


int main() {
    map<ll, ll> fac;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        auto f = factorize(i);
        for (auto p : f) {
            fac[p.first] += p.second;
        }
    }

    mint ans = 1;
    for (auto e : fac) {
        ans *= (e.second + 1);
    }

    cout << ans << endl;
}