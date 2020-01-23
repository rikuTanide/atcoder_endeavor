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

ll count(vector<ll> &indexes, vector<ll> &coins, ll n) {
    vector<ll> ordered_coins(n);
    rep(i, n) ordered_coins[i] = coins[indexes[i]];
    vector<bool> flips(n, true);
    rep(i, n) {
        for (ll j = i + 1; j < n; j++) {
            if (ordered_coins[j] % ordered_coins[i] == 0) {
                flips[j] = !flips[j];
            }
        }
    }

    ll ans = 0;
    rep(i, n) if (flips[i]) ans++;
    return ans;
}

ll fac(ll n) {
    ll i = 1;
    for (ll j = 1; j <= n; j++) {
        i *= j;
    }
    return i;
}

int main() {
    ll n;
    cin >> n;
    assert(n <= 8);
    vector<ll> coins(n);
    rep(i, n)cin >> coins[i];

    vector<ll> indexes(n);
    rep(i, n) indexes[i] = i;
    ll ans = 0;
    do {
        ans += count(indexes, coins, n);
    } while (next_permutation(indexes.begin(), indexes.end()));

    ll f = fac(n);
    printf("%.20f\n", (double) ans / f);
}
