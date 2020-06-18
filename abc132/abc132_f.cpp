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

    ll n;
    int k;
    cin >> n >> k;

    set<ll> candidate;
    for (ll i = 1; i * i <= n; i++) {
        candidate.insert(i);
        candidate.insert(n / i);
    }

    vector<ll> candidate_vec;
    for (ll l : candidate) candidate_vec.push_back(l);
    reverse(candidate_vec.begin(), candidate_vec.end());

    unordered_map<ll, ll> conv;
    rep(i, candidate_vec.size()) conv[candidate_vec[i]] = i;

    vector<mint> layer(candidate_vec.size(), 0);

    layer[conv[1]] = 1;
    for (int i = 1; i < candidate_vec.size(); i++) {
        ll a = n / (candidate_vec[i - 1]);
        ll b = n / candidate_vec[i];

        ll cou = b - a;

        layer[conv[b]] = cou;
    }

    vector<mint> prev = layer;
    for (int i = 1; i < k; i++) {

        for (int j = candidate_vec.size() - 2; j >= 0; j--) {
            prev[conv[candidate_vec[j]]] += prev[conv[candidate_vec[j + 1]]];
        }

        vector<mint> next(candidate_vec.size());
        for (ll key : candidate_vec) {
            next[conv[key]] += prev[conv[n / key]] * layer[conv[key]];

        }
        prev = next;
    }
//
//
    mint ans = 0;
    for (auto e : prev) ans += e;
    cout << ans << endl;

}
