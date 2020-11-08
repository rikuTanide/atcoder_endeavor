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
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n)cin >> v[i];

    vector<int> dp(n);
    rep(i, n) {
        if (i == 0 || v[i - 1] == v[i]) dp[i] = 1;
        else dp[i] = dp[i - 1] + 1;
    }


    vector<int> segment_lens;
    rep(i, n) {
        if (i + 1 == n || dp[i + 1] == 1) segment_lens.push_back(dp[i]);
    }


    int ans = 0;
    int m = segment_lens.size();
    rep(i, m - 2) {
        int now = segment_lens[i] + segment_lens[i + 1] + segment_lens[i + 2];
        cmax(ans, now);
    }

    rep(i, m - 1) {
        int now = segment_lens[i] + segment_lens[i + 1];
        cmax(ans, now);
    }


    rep(i, m) {
        int now = segment_lens[i];
        cmax(ans, now);
    }

    cout << ans << endl;
}
