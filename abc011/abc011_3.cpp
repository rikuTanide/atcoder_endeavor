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


int main() {
    int n, n1, n2, n3;
    cin >> n >> n1 >> n2 >> n3;

    set<int> ng;
    ng.insert(n1);
    ng.insert(n2);
    ng.insert(n3);

    if (contain(ng, n)) {
        cout << "NO" << endl;
        ret();
    }
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    auto set = [&](int i, int v) {
        if (i > n) return;
        if (dp[i] == -1) dp[i] = v;
        else
            cmin(dp[i], v);
    };

    rep(i, n + 1) {
        if (dp[i] == -1) continue;
        if (!contain(ng, i + 1)) set(i + 1, dp[i] + 1);
        if (!contain(ng, i + 2)) set(i + 2, dp[i] + 1);
        if (!contain(ng, i + 3)) set(i + 3, dp[i] + 1);
    }

    string ans = dp[n] != -1 && dp[n] <= 100 ? "YES" : "NO";
    cout << ans << endl;
}
