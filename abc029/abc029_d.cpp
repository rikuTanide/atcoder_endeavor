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


vector<vector<ll>> create_counts_dp(int l, vector<int> &digits) {
    vector<vector<ll>> counts_dp(l, vector<ll>(2, 0));

    auto get = [&](int i, bool small) -> ll {
        if (i == -1) return 0;
        return counts_dp[i][small];
    };

    rep(i, l) {

        for (int x = 1; x <= (i == 0 ? digits[0] : 9); x++) {
            counts_dp[i][i == 0 ? (x < digits[0]) : true]++;
        }

        rep(x, 10) {
            counts_dp[i][true] += get(i - 1, true);
        }

        rep(x, digits[i]) {
            counts_dp[i][true] += get(i - 1, false);
        }
        counts_dp[i][false] += get(i - 1, false);
    }
    return counts_dp;
}


vector<vector<ll>> create_dp(int l, vector<int> &digits, vector<vector<ll>> &counts_dp) {
    vector<vector<ll>> dp(l, vector<ll>(2, 0));

    auto get = [&](int i, bool small) -> ll {
        if (i == -1) return 0;
        return dp[i][small];
    };

    auto get_c = [&](int i, bool small) -> ll {
        if (i == -1) return 0;
        return counts_dp[i][small];
    };

    rep(i, l) {

        for (int x = 1; x <= (i == 0 ? digits[0] : 9); x++) {
            if (x == 1) dp[i][i == 0 ? (x < digits[0]) : true]++;
        }

        rep(x, 10) {
            dp[i][true] += get(i - 1, true);
            if (x == 1) dp[i][true] += get_c(i - 1, true);
        }

        rep(x, digits[i]) {
            dp[i][true] += get(i - 1, false);
            if (x == 1) dp[i][true] += get_c(i - 1, false);
        }
        dp[i][false] += get(i - 1, false);
        if (digits[i] == 1) dp[i][false] += get_c(i - 1, false);
    }
    return dp;
}


int main() {
    string s;
    cin >> s;
    vector<int> digits;
    //ベクターnを構成
    for (auto a : s) {
        digits.push_back(a - '0');
    }
    int l = s.size();

    auto counts_dp = create_counts_dp(l, digits);
    auto dp = create_dp(l, digits, counts_dp);

    cout << dp[l - 1][0] + dp[l - 1][1] << endl;

}
