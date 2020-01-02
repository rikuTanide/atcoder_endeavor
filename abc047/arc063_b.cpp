#include <bits/stdc++.h>
#include <cmath>

using namespace std;
//typedef long long ll;
typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;


int main() {
    int n, t;
    cin >> n >> t;

    vector<ll> apples(n);
    rep(i, n) cin >> apples[i];

    ll ans = 0;
    ll max_diff = 0;
    {
        ll min_apple = apples[0];
        for (int i = 1; i < n; i++) {
            ll apple = apples[i];
            cmin(min_apple, apple);

            ll diff = apple - min_apple;
            cmax(max_diff, diff);
        }
    }

    ll min_apple = apples[0];
    for (int i = 1; i < n; i++) {
        ll apple = apples[i];
        cmin(min_apple, apple);

        ll diff = apple - min_apple;
        if (diff == max_diff) ans++;
    }

    cout << ans << endl;
}
