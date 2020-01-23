#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
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

ll divisor_count(vector<ll> &coins, ll number) {
    ll ans = 0;
    for (ll coin : coins) {
        if (number % coin == 0) ans++;
    }
    ans--;
    return ans;
}

int main() {
    ll n;
    cin >> n;

    vector<ll> coins(n);
    rep(i, n)cin >> coins[i];

    double ans = 0;
    for (ll coin : coins) {
        ll div_c = divisor_count(coins, coin);
        if (div_c % 2 == 1) {
            double now = 1.0 / 2;
            ans += now;
        } else {
            double now = ((double) div_c + 2) / (2.0 * div_c + 2);
            ans += now;
        }
    }
    printf("%.20f\n", ans);
}
