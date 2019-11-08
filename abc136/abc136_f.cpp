#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
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
};

template<typename T>
struct BIT {
    int n;
    vector<T> d;

    BIT(int n = 0) : n(n), d(n + 1) {}

    void add(int i, T x = 1) {
        for (i++; i <= n; i += i & -i) {
            d[i] += x;
        }
    }

    T some(int i) {
        T x = 0;
        for (i++; i; i -= i & -i) {
            x += d[i];
        }
        return x;
    }

};

mint f(int a, int b, int c, int d) {
    mint res = 0;
    vector<int> num = {a, b, c, d};
    vector<mint> o(4), ox(4);
    rep(i, 4) {
        ox[i] = mint(2).pow(num[i]);
        o[i] = ox[i] - 1;
    }
    res += ox[0] * o[1] * o[2] * ox[3];
    res += o[0] * ox[1] * ox[2] * o[3];
    res -= o[0] * o[1] * o[2] * o[3];
    res += ox[0] * ox[1] * ox[2] * ox[3];
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<P> p(n);
    rep(i, n)cin >> p[i].first >> p[i].second;

    {
        map<int, int> mp;
        rep(i, n)mp[p[i].first] = 0;
        int j = 0;
        for (auto &&x :mp) x.second = j++;
        rep(i, n) p[i].first = mp[p[i].first];
    }
    {
        map<int, int> mp;
        rep(i, n)mp[p[i].second] = 0;
        int j = 0;
        for (auto &&x :mp) x.second = j++;
        rep(i, n) p[i].second = mp[p[i].second];
    }

    sort(p.begin(), p.end());

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    vector<int> d(n);

    rep(_, 2) {
        {
            BIT<int> bit(n);
            rep(i, n) {
                a[i] = bit.some(p[i].second);
                b[i] = i - a[i];
                bit.add(p[i].second);
            }
        }

        reverse(p.begin(), p.end());
        swap(a, c);
        swap(b, d);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(c.begin(), c.end());
        reverse(d.begin(), d.end());
    }

    mint ans = 0;
    rep(i, n) {
        ans += f(a[i], b[i], c[i], d[i]);
    }
    cout << ans.x << endl;


}
