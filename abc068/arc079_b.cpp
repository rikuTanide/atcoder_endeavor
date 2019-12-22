#include <bits/stdc++.h>
#include <cmath>

#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;


int main() {
    int k;
    cin >> k;

    int n = 50;

    vector<int> dp(n, n - 1);
    for (int s = 0; s < k; s++) {
        for (int i = 0; i < n; i++) dp[i]--;
        (*min_element(dp.begin(), dp.end())) += (n + 1);

    }

    cout << n << endl;
    for (int i = 0; i < n; i++) cout << dp[i] << ' ';
    cout << endl;

    for (int i = 0; i < 50; i++) {
        cout << ((n + 1) * ((k + n - 1 - i) / n) - k + 49) << ' ';
    }
}