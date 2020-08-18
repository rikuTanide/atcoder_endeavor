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
//すべてのチェック
    int n, m;
    cin >> n >> m;

    vector<string> strs(n);
    rep(i, n) cin >> strs[i];

    auto is_match = [](char a, char b) -> bool {
        return a == '*' || b == '*' || a == b;
    };

    auto check = [&](int i, int j) -> bool {
        string a = strs[i], b = strs[j];
        rep(k, m) if (!is_match(a[k], b[k])) return false;
        return true;
    };

    vector<vector<bool>> checked(n, vector<bool>(n));
    rep(i, n) rep(j, n) checked[i][j] = check(i, j);


    vector<int> dp(1 << n, n);
    for (int i = 1; i < (1 << n); i = (i << 1)) {
        dp[i] = 1;
    }


    auto can_one = [&](int i) -> bool {
        vector<int> v;
        rep(j, n) if ((i >> j) & 1) v.push_back(j);

        for (int a : v) {
            for (int b : v) {
                if (!checked[a][b]) return false;
            }
        }
        return true;
    };


    auto get_min = [&](int i) -> int {
        int ans = n;
        for (int s = (i - 1) & i; s > 0; s = (s - 1) & i) {
            int t = i ^s;

//            cout << bitset<4>(i) << endl << bitset<4>(s) << endl << bitset<4>(t) << endl << endl;


            int now = dp[s] + dp[t];
            cmin(ans, now);
        }
        return ans;
    };

    rep(i, 1 << n) {
        if (i == 0) continue;
        if (__builtin_popcount(i) == 1) continue;
        if (can_one(i)) dp[i] = 1;
        else dp[i] = get_min(i);
    }

    cout << dp[(1 << n) - 1] << endl;

}
