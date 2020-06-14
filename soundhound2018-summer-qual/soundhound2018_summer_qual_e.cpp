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

ll n, m, u, v, s, d[100000], color[100000], res_sum;
vector<P> e[100000];

bool dfs(ll num, ll col, ll x) {
    if (color[num] == col) {
        if (d[num] != x) {
            res_sum = 1;
            return true;
        }
        return false;
    }
    if (color[num] == -col) {
        if (color[num] == 1) res_sum = x - d[num];
        else res_sum = d[num] - x;
        return true;
    }
    color[num] = col;
    d[num] = x;
    for (P p : e[num]) {
        if (dfs(p.first, -col, p.second - x)) return true;
    }
    return false;
}

bool check(ll num, ll x) {
    if (x <= 0) return false;
    if (d[num] != 0) {
        return d[num] == x;
    }
    d[num] = x;
    for (P p : e[num]) {
        if (!check(p.first, p.second - x)) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        cin >> u >> v >> s;
        u--;
        v--;
        e[u].push_back(P(v, s));
        e[v].push_back(P(u, s));
    }
    if (dfs(0, 1, 0)) {
        for (ll i = 0; i < n; i++) d[i] = 0;
        if (res_sum % 2 == 0 && check(0, res_sum / 2)) printf("1\n");
        else printf("0\n");
    } else {
        ll lb = 1, ub = 1000000000LL;
        for (ll i = 0; i < n; i++) {
            if (color[i] == 1) {
                lb = max(lb, 1 - d[i]);
            } else {
                ub = min(ub, d[i] - 1);
            }
        }
        printf("%lld\n", max(0LL, ub - lb + 1));
    }
}