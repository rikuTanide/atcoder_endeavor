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

vector<vector<int>> knapsack(int n, int p, vector<P> &v) {
    vector<vector<int>> dp(n + 1, vector<int>(p + 1, -1));
    dp[0][0] = 0;

    auto get = [&](int i, int j) -> int {
        return dp[i][j];
    };

    auto set = [&](int i, int j, int value) {
        if (j > p) return;
        cmax(dp[i][j], value);
    };

    rep(i, n) {
        rep(j, p + 1) {
            int now = get(i, j);
            if (now == -1) continue;
            P o = v[i];
            set(i + 1, j, now);
            set(i + 1, j + o.first, now + o.second);
        }
    }

    rep(i, n) {
        rep(j, p) {
            cmax(dp[i][j + 1], dp[i][j]);
        }
    }

    return dp;
}

int main() {
    int n, p;
    cin >> n >> p;

    vector<P> v(n);
    for (P &o:v) cin >> o.first >> o.second;

    sort(v.rbegin(), v.rend());

    auto dp = knapsack(n, p, v);

    int ans = -1;

    rep(i, n) {
        int now = dp[i][p];
        cmax(ans, now);
    }


    vector<P> u = v;
    rep(i, n) {
        P o = v[i];
        rep(j, i) {
            int now = dp[j + 1][p];
            int next = now + o.second;
            cmax(ans, next);
        }
    }

    cout << ans << endl;
}
