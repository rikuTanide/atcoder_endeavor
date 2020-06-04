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


int solve(vector<ll> &hotels, ll l) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;

    if (!(a < b)) swap(a, b);

    vector<vector<ll>> dp(b - a + 1, vector<ll>(b - a + 1, -1));
    dp[0][0] = 0;

    auto set = [&](int i, int j, ll v) {
        if (v > l) return;
        if (dp[i][j] == -1) dp[i][j] = v;
        else {
            cmin(dp[i][j], v);
        }
    };

    rep(i, b - a) {
        ll dis = hotels[a + i + 1] - hotels[a + i];
        rep(j, b - a) {
            if (dp[i][j] == -1) continue;
            // 泊まる
            set(i + 1, j + 1, dis);
            // 今日行く
            set(i + 1, j, dp[i][j] + dis);
        }
    }

    rep(i, b - a + 1) {
        if (dp.back()[i] != -1) {
            return i;
        }
    }
    __throw_runtime_error("nai");
}

int main() {
    int n;
    cin >> n;

    vector<ll> hotels(n);
    rep(i, n) cin >> hotels[i];

    ll l, q;
    cin >> l >> q;
    assert(n <= 10e2 && q <= 10e2);

    rep(_, q) {
        cout << solve(hotels, l) + 1 << endl;
    }
}