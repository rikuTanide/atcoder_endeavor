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

int main() {

    int n;
    cin >> n;


    vector<ll> as(n);
    rep(i, n) cin >> as[i];

    int skip = (n % 2) + 1;


    vector<vector<ll>> dp(n + 1, vector<ll>(skip + 1, -INF));

    auto set = [&](int i, int j, ll value) {
        if (i > n) return;
        if (j > skip) return;
        cmax(dp[i][j], value);
    };

    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= skip; j++) {
            // 飛ばす
            set(i + 1, j + 1, dp[i][j]);

            // 飛ばさない
            // 〇なら足す
            // ×なら足さない

            bool b = (i + j) % 2 == 0;
            ll now = b ? as[i] : 0;
            set(i + 1, j, dp[i][j] + now);

        }
    }

    cout << dp.back().back() << endl;
}
