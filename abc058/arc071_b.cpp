#include <bits/stdc++.h>
#include <cmath>

#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};


int main() {
    ll n, m;
    cin >> n >> m;

    n--;
    m--;


    vector<ll> x_s(n, 0);
    vector<ll> y_s(m, 0);

    {
        {
            ll before_x;
            cin >> before_x;
            for (ll x = 0; x < n; x++) {
                ll next_x;
                cin >> next_x;
                x_s[x] = next_x - before_x;
                before_x = next_x;
            }
        }
        {
            ll before_y;
            cin >> before_y;
            for (ll y = 0; y < m; y++) {
                ll next_y;
                cin >> next_y;
                y_s[y] = next_y - before_y;
                before_y = next_y;
            }
        }
    }

    mint x_sum = 0;

    for (ll x = 0; x < n; x++) {
        ll left = x + 1;
        ll right = n - x;
        ll k = left * right;
        ll s = x_s[x] * k;
        x_sum += s;
    }

    mint y_sum = 0;
    for (ll y = 0; y < m; y++) {
        ll left = y + 1;
        ll right = m - y;
        ll k = left * right;
        ll s = y_s[y] * k;
        y_sum += s;
    }

    mint sum = x_sum * y_sum;

    cout << sum.x << endl;
}

