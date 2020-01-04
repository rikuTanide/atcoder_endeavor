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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;


int main() {
    int n;
    cin >> n;
    vector<ll> pillars(n);
    rep(i, n) cin >> pillars[i];
    vector<ll> dp(n, 0);
    dp[1] = abs(pillars[0] - pillars[1]);
    for (int i = 2; i < n; i++) {
        ll back2 = pillars[i - 2];
        ll back1 = pillars[i - 1];
        ll now = pillars[i];

        ll from_back2 = abs(now - back2);
        ll from_back1 = abs(now - back1);

        ll from_back2_total = dp[i - 2] + from_back2;
        ll from_back1_total = dp[i - 1] + from_back1;

        dp[i] = min(from_back2_total, from_back1_total);

    }

    cout << dp.back() << endl;


}