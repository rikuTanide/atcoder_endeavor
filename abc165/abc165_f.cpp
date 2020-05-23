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

void dfs(int from, vector<vector<int>> &edges, vector<int> &a, vector<int> &ans, vector<int> &dp, int prev = -1) {

    int i = lower_bound(dp.begin(), dp.end(), a[from]) - dp.begin();
    int old = dp[i];
    dp[i] = a[from];

    ans[from] = i;
    if (prev != -1) ans[from] = max(ans[from], ans[prev]);

    for (int next : edges[from]) {
        if (next == prev) continue;
        dfs(next, edges, a, ans, dp, from);
    }
    dp[i] = old;
}

int main() {

    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<int>> edges(n);

    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<int> dp(n, INT_MAX);
    vector<int> ans(n);
    dp[0] = INT_MIN;

    dfs(0, edges, a, ans, dp);
    for (int now : ans) cout << now << endl;

}
