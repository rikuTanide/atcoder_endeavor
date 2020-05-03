#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

typedef pair<ll, ll> P;

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


void raw(vector<ll> &numbers, int n, ll a, ll b) {
    priority_queue<ll> q;
    for (ll l : numbers) q.push(l);
    rep(i, b) {
        ll t = q.top();
        q.pop();
        q.push(t * a);
    }

    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }

}


int main() {
    int n;
    ll a, b;
    cin >> n >> a >> b;


    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];


    if (a == 1) {
        for (ll l : numbers) cout << l << endl;
        ret();
    }

    ll ma = *max_element(numbers.begin(), numbers.end());

    vector<ll> ini_ratio(n, 0);
    vector<ll> ini_ll(n);
    rep(i, n) {
        ini_ll[i] = numbers[i];
        for (ini_ratio[i] = 0; ini_ll[i] < ma; ini_ratio[i]++) {
            ini_ll[i] *= a;
        }
    }

    ll ini_count = accumulate(ini_ratio.begin(), ini_ratio.end(), 0ll);
    ll after = b - ini_count;

    if (after < 0) {
        raw(numbers, n, a, b);
        ret();
    }

    ll cycle = after / n;
    ll md = after % n;

    sort(ini_ll.begin(), ini_ll.end());
    vector<mint> ini_mint(n);

    vector<mint> ans_mint(n);
    rep(i, n) ans_mint[i] = mint(a).pow(cycle) * ini_ll[i];

    rep(i, n) {
        if (i < md) ans_mint[i] *= a;
    }

    rep(i, n) {
        int j = (md + i) % n;
        cout << ans_mint[j] << endl;
    }

}
