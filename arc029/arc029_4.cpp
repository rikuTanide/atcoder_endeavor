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

int size_dfs(int i, vector<vector<int>> &edges, vector<int> &sizes) {
    int size = 1;
    for (int j : edges[i]) size += size_dfs(j, edges, sizes);

    sizes[i] = size;
    return size;

}

ll min_t(vector<ll> &dp, vector<ll> &tmp, int k) {
    assert(tmp.size() <= dp.size());
    ll ans = INF;
    for (int i = 0; i <= tmp.size() && k - i >= 0; i++) {
        int j = k - i;

        ll
                t = i == 0 ? 0 : tmp[i - 1],
                d = j == 0 ? 0 : dp[j - 1];

        ll now = t + d;
        cmin(ans, now);
    }
    return ans;
}

vector<ll> dfs(int i, vector<vector<int>> &edges, vector<ll> &tree, vector<int> &sizes) {
    vector<ll> dp(sizes[i] - 1, INF);

    for (int j : edges[i]) {
        vector<ll> tmp = dfs(j, edges, tree, sizes);
        vector<ll> next(sizes[i] - 1, INF);

        for (int k = 1; k < sizes[i]; k++) {
            ll res = min_t(dp, tmp, k);
            next[k - 1] = res;
        }

        dp = next;
    }
    dp.insert(dp.begin(), 0);
    rep(j, dp.size()) dp[j] += tree[i];
    return dp;
}

int main() {
    int n;
    cin >> n;

    vector<ll> tree(n);
    rep(i, n) cin >> tree[i];

    vector<vector<int>> edges(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        edges[a].push_back(b);
    }

    vector<int> sizes(n);


    size_dfs(0, edges, sizes);

    vector<ll> dp = dfs(0, edges, tree, sizes);
    dp.insert(dp.begin(), 0);

    int m;
    cin >> m;
    vector<ll> methods(m);
    rep(i, m) cin >> methods[i];
    sort(methods.rbegin(), methods.rend());

    ll org_all = accumulate(tree.begin(), tree.end(), 0ll);

    ll ans = 0;
    for (int i = 0; i <= n && i < methods.size(); i++) {
        ll sum = accumulate(methods.begin(), methods.begin() + i, 0ll);
        ll now = org_all - dp[i] + sum;
        cmax(ans, now);
    }


    cout << ans << endl;
}
