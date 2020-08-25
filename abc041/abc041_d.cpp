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


int bit_rev(int n, int st, int i) {
    assert((st >> i) & 1);
    return st - (1 << i);
}

ll recursive(int n, vector<vector<int>> &g, int st, map<int, ll> &memo) {
    if (__builtin_popcount(st) == 1) return 1;
    if (memo.find(st) != memo.end())return memo[st];
    ll ans = 0;

    vector<bool> is_terminate(n, true);
    rep(i, n) {
        if (!((st >> i) & 1)) continue;
        for (int to : g[i]) {
            if (!((st >> to) & 1)) continue;
            is_terminate[i] = false;
        }
    }

    rep(i, n) {
        if ((st >> i) & 1) {
            if (is_terminate[i]) {
                int next_st = bit_rev(n, st, i);
                ll now = recursive(n, g, next_st, memo);
                ans += now;
            }
        }
    }
    memo[st] = ans;
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<P> v(m);
    for (P &p:v) cin >> p.first >> p.second, p.first--, p.second--;
    vector<vector<int>> g(n);
    for (P p : v) g[p.first].push_back(p.second);

    map<int, ll> memo;
    ll ans = recursive(n, g, (1 << n) - 1, memo);
    cout << ans << endl;
}
