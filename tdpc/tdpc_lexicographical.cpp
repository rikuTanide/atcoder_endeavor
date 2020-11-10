#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

bool equal(double a, double b) {
//    return fabs(a - b) < DBL_EPSILON;
    return fabs(a - b) < EPS;
}

template<class T>
std::istream &operator>>(std::istream &in, set<T> &o) {
    T a;
    in >> a;
    o.insert(a);
    return in;
}

template<class T>
std::istream &operator>>(std::istream &in, queue<T> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {
    string s;
    ll k;
    cin >> s >> k;
    int n = s.size();
    vector<vector<int>> positions(26);

    rep(i, n) {
        char c = s[i];
        int ci = c - 'a';
        positions[ci].push_back(i);
    }

    vector<ll> dp(n, 1);

    for (int i = n - 1; i >= 0; i--) {
        rep(j, 26) {
            auto it = upper_bound(positions[j].begin(), positions[j].end(), i);
            if (it == positions[j].end()) continue;
            int l = *it;
            dp[i] += dp[l];
            if (dp[i] > k) dp[i] = k + 1;
        }
    }

    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        if (positions[i].empty()) continue;
        ans += dp[positions[i][0]];
        if (ans > k) ans = k + 1;
    }

    if (ans < k) {
        cout << "Eel" << endl;
        ret();
    }

    throw_with_nested("mada");

}
