#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;


void knapsack(vector<ll> &numbers, vector<ll> &ans) {


    vector<vector<ll>> dp(60, vector<ll>(60 * 60, 0));
    dp[0][0] = 1;

    for (ll i = 0; i < numbers.size(); ++i) {
        for (ll j = 0; j < 60 * 60; ++j) {
            dp[i + 1][j] += dp[i][j];
            if (j >= numbers[i]) {
                dp[i + 1][j] += dp[i][j - numbers[i]];
            }
        }
    }

    for (ll i = 0; i < ans.size(); i++) {
        ans[i] = dp[numbers.size()][i];
    }

}


int main() {

    ll n, a;
    cin >> n >> a;
    vector<ll> plus;
    vector<ll> minus;
    ll equal = 0;
    rep(i, n) {
        ll x;
        cin >> x;
        if (x > a) {
            plus.push_back(x - a);
        } else if (x == a) {
            equal++;
        } else {
            minus.push_back(a - x);
        }
    }
//
    vector<ll> ps(60 * 60);
    vector<ll> ms(60 * 60);
//    knapsack(plus);
    knapsack(plus, ps);
//    knapsack(minus);
    knapsack(minus, ms);


    ll ans = -1;
    for (ll i = 0; i < 60 * 60; i++) {
        ans += ps[i] * ms[i];
    }

    for (ll k = 0; k < equal; k++) {
        ans *= 2;
    }

    ll eq_ans = 1;
    for (ll k = 0; k < equal; k++) {
        eq_ans *= 2;
    }

    cout << ans + eq_ans - 1 << endl;

}