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


int main() {

    ifstream cin("C:\\Users\\riku\\Downloads\\hand_02.txt");

    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    vector<ll> plus, minus;
    int zero = 0;

    for (ll l : v) {
        if (l > 0) plus.push_back(l);
        else if (l < 0) minus.push_back(l);
        else zero++;
    }

    sort(plus.rbegin(), plus.rend());
    sort(minus.rbegin(), minus.rend());

    if ((n - zero) < k) {
        cout << 0 << endl;
        ret();
    }

    // 必ずプラス
    int mim = max<ll>(k - plus.size(), 0);
    if (mim % 2 == 0 || (plus.size() > 0 && minus.size() - mim > 0)) {
        vector<ll> abs_sort = v;
        sort(abs_sort.rbegin(), abs_sort.rend(), [](ll a, ll b) {
            return abs(a) < abs(b);
        });
        assert(count(abs_sort.begin(), abs_sort.begin() + k, 0) == 0);

        int m = 0;
        rep(i, k) if (abs_sort[i] < 0) m++;

        if (m % 2 == 0) {
            mint ans = 1;
            rep(i, k) ans *= abs_sort[i];
            cout << ans << endl;
            ret();
        }


        int first_m_i = [&] {
            rep(i, n) {
                if (i < k) continue;
                if (abs_sort[i] < 0) return i;
            }
            __throw_runtime_error("dame");
        }();

        int last_m_i = [&] {
            int ans = -1;
            rep(i, k) {
                if (abs_sort[i] < 0) ans = i;
            }
            assert(ans > -1);
            return ans;
        }();

        int first_p_i = [&] {
            rep(i, n) {
                if (i < k) continue;
                if (abs_sort[i] > 0) return i;
            }
            return -1;
        }();

        int last_p_i = [&] {
            int ans = -1;
            rep(i, k) {
                if (abs_sort[i] > 0) ans = i;
            }
            assert(ans > -1);
            return ans;
        }();

        if (first_p_i == -1) {
            mint ans = 1;
            rep(i, k) if (i != last_p_i) ans *= abs_sort[i];
            ans *= abs_sort[first_m_i];
            cout << ans << endl;
            ret();
        }

        if (abs(abs_sort[first_p_i] * abs_sort[last_p_i]) > abs(abs_sort[first_m_i] * abs_sort[last_m_i])) {
            mint ans = 1;
            rep(i, k) if (i != last_m_i) ans *= abs_sort[i];
            ans *= abs_sort[first_p_i];
            cout << ans << endl;
        } else {
            mint ans = 1;
            rep(i, k) if (i != last_p_i) ans *= abs_sort[i];
            ans *= abs_sort[first_m_i];
            cout << ans << endl;
        }
        ret();
    }

    if (zero > 0) {
        cout << 0 << endl;
        ret();
    }


    vector<ll> abs_sort = v;
    sort(abs_sort.begin(), abs_sort.end(), [](ll a, ll b) {
        return abs(a) < abs(b);
    });
    mint ans = 1;
    rep(i, k) ans *= abs_sort[i];
    cout << ans << endl;

}
