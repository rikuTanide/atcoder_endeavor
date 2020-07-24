#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair <ll, ll> P;
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

typedef priority_queue <ll, vector<ll>, greater<ll>> PQ_ASK;


ll tsum(ll k) {
    return k * (k + 1) / 2;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ss = s.size();
    if (count(s.begin(), s.end(), 'A') == ss) {
        ll t = ll(ss) * n;
        cout << tsum(t) << endl;
        ret();
    }
    if (count(s.begin(), s.end(), 'B') == ss) {
        cout << 0 << endl;
        ret();
    }

    ll prefix = [&] {
        rep(i, ss) {
            if (s[i] == 'B') return i;
        }
        assert(false);
    }();
    ll la = [&] {
        for (int i = ss - 1; i >= 0; i--) {
            if (s[i] == 'B') return i;
        }
        assert(false);
    }();

    ll suffix = ss - la - 1;
    ll body = [&] {
        vector <ll> dp(ss, 0);
        rep(i, ss) {
            if (i < prefix) continue;
            if (la < i) continue;
            if (s[i] == 'B') continue;
            dp[i] = i == 0 ? 1 : dp[i - 1] + 1;
        }
        ll ans = accumulate(dp.begin(), dp.end(), 0ll);
        return ans;
    }();

    ll connect_len = (prefix + suffix);
    ll connect = tsum(connect_len);

    ll ans = tsum(prefix) + tsum(suffix) + (body * n) + connect * (n - 1);
    cout << ans << endl;

}
