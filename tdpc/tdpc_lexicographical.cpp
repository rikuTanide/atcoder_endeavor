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

int search_next(int x, int c, vector<vector<int>> &positions) {
    auto it = upper_bound(positions[c].begin(), positions[c].end(), x);
    if (it == positions[c].end()) return -1;
    return *it;
}

void rebuild(ll k, vector<ll> &dp, string &ans, ll now, int x, vector<vector<int>> &positions) {
    rep(c, 26) {
        int nx = search_next(x, c, positions);
        if (nx == -1) continue;
        ll d = dp[nx];
        if (now + d >= k) {
            ans.push_back('a' + c);
            if (now + 1 == k) return;
            else return rebuild(k, dp, ans, now + 1, nx, positions);
        } else {
            now += d;
        }
    }
}

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
            int l = search_next(i, j, positions);
            if (l == -1) continue;
            dp[i] += dp[l];
            if (dp[i] > k) dp[i] = k + 1;
        }
    }

    ll count = 0;
    for (int i = 0; i < 26; i++) {
        if (positions[i].empty()) continue;
        count += dp[positions[i][0]];
        if (count > k) count = k + 1;
    }

    if (count < k) {
        cout << "Eel" << endl;
        ret();
    }

    string ans;
    rebuild(k, dp, ans, 0, -1, positions);
    cout << ans << endl;


}
