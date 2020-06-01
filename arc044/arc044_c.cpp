#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

const int MAXT = 100000;

ll calc(ll w, vector<vector<ll>> x) {
    vector<ll> dp(MAXT, 0);
    rep(t, MAXT) {
        sort(x[t].begin(), x[t].end());
        ll n = x[t].size();
        for (ll i = 0; i < n; i++) {
            ll nx = x[t][i] + 1;
            if (nx < w) dp[nx] = min(dp[nx], dp[x[t][i]] + 1);
        }
        for (ll i = n - 1; i >= 0; i--) {
            ll nx = x[t][i] - 1;
            if (nx >= 0) dp[nx] = min(dp[nx], dp[x[t][i]] + 1);
        }
        for (ll i = 0; i < n; i++) dp[x[t][i]] = INF;
    }
    ll ans = *min_element(dp.begin(), dp.begin() + w);
    return ans;
}

int main() {
    ll w, h, q;
    cin >> w >> h >> q;


    vector<vector<ll>> x(MAXT), y(MAXT);

    rep(i, q) {
        ll t, d, a;
        cin >> t >> d >> a;
        t--;
        a--;

        if (d == 0) x[t].push_back(a);
        else y[t].push_back(a);
    }

    ll ans = calc(w, x) + calc(h, y);

    if (ans >= INF) ans = -1;

    cout << ans << endl;

}