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

vector<mint> dfs(int v, int p, vector<vector<int>> &g, int k) {
    vector<mint> res(1, 1);
    for (int ch : g[v]) {
        if (ch == p) continue;
        vector<mint> tmp = dfs(ch, v, g, k);
        int n = res.size(), m = tmp.size();
        vector<mint> nret(n + m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nret[i + j] += res[i] * tmp[j];
            }
        }
        res = nret;
    }

    vector<mint> x = res;
    res.push_back(0);
    res.push_back(0);
    fill(res.begin(), res.end(), 0);
    for (int i = 0; i < (int) (x.size()); i++) {
        res[i] += x[i];
        res[i + 1] += x[i] * 2;
        res[i + 2] += x[i];
    }
    int n = res.size();
    n--;
    for (int b = 0; b <= n; b++) {
        int r = n - b;
        if (abs(r - b) > k) res[b] = 0;
    }
    return res;


}

int main() {
    string s;
    int k;
    cin >> s >> k;

    stack<pair<char, int>> st;
    int n = s.size();

    vector<int> to(n);


    rep(i, n) {
        if (s[i] == '(') st.push(make_pair(s[i], i));
        else {
            auto p = st.top();
            st.pop();
            to[p.second] = i;
        }
    }

    map<P, int> mp;
    int size = 0;
    rep(i, n) {
        if (i < to[i])mp.insert(make_pair(P(i, to[i]), size++));
    }

    vector<vector<int>> g(n);

    rep(l, n) {
        int r = to[l];
        if (r - l) continue;
        int index = mp[P(l, r)];
        for (int nl = l + 1; nl < r; nl++) {
            g[index].push_back(mp[P(nl, to[nl])]);
            nl = to[nl];
        }
    }

    mint ans = 1;

    for (int l = 0; l < n; l++) {
        int index = mp[P(l, to[l])];
        vector<mint> tmp = dfs(index, -1, g, k);
        mint mult = 0;
        for (mint el : tmp) mult += el;
        ans *= mult;
        l = to[l];
    }

    cout << ans << endl;


}
