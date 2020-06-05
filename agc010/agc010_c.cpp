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
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

bool solve(int n, vector<int> &a, vector<vector<int> > &g) {
    vector<int> dp(n);
    auto is_leaf = [&](int i) { return g[i].size() == 1; };
    function<bool(int, int)> go = [&](int i, int parent) {
        if (is_leaf(i)) {
            dp[i] = a[i];
        } else {
            ll sum_dp = 0;
            for (int j : g[i])
                if (j != parent) {
                    if (not go(j, i)) return false;
                    sum_dp += dp[j];
                }
            ll b = sum_dp - a[i];
            ll c = a[i] - b;
            if (b < 0 or c < 0) return false;
            int argmax_dp = *whole(max_element, g[i],
                                   [&](int j, int k) { return make_pair(j != i, dp[j]) < make_pair(k != i, dp[k]); });
            ll max_dp = dp[argmax_dp];
            if (max_dp > sum_dp / 2) {
                if (sum_dp - max_dp < b) return false;
            } else {
                if (sum_dp / 2 < b) return false;
            }
            dp[i] = c;
        }
        return true;
    };
    assert (n >= 2);
    if (n == 2) {
        return a[0] == a[1];
    } else {
        int i = 0;
        while (is_leaf(i)) ++i;
        if (not go(i, -1)) return false;
        return dp[i] == 0;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout << (solve(n, a, g) ? "YES" : "NO") << endl;
}
