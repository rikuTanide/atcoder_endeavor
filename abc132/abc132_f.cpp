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

    map<ll, int> layer;

    layer[1] = 1;
    for (int i = 1; i < candidate_vec.size(); i++) {
        ll a = n / (candidate_vec[i - 1]);
        ll b = n / candidate_vec[i];

        ll cou = b - a;

        layer[b] = cou;

    }


//    vector<ll> par(n + 1, 0);
//    for (int i = 1; i <= n; i++) {
//        int p = n / i;
//        par[p]++;
//    }
//
//    for (int i = 1; i <= n; i++) {
//        if (par[i] == 0) continue;
//
//        int l = n / i;
//        layer[l] = par[i];
//    }


    vector<map<ll, mint>> dp(k);
    for (auto e : layer) dp[0][e.first] = e.second;
    for (int i = 1; i < k; i++) {

        for (auto ej : layer) {
            for (auto eh : layer) {
                if (ej.first * eh.first <= n) {
                    dp[i][ej.first] += dp[i - 1][eh.first] * ej.second;
                }
            }
        }

    }


    mint ans = 0;
    for (auto e : layer) ans += dp[k - 1][e.first];
    cout << ans << endl;

}
