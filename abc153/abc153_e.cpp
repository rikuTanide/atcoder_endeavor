#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct Attack {
    ll a;
    ll mp;
};

int main() {

    ll h, n;
    cin >> h >> n;

    vector<Attack> attacks(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        attacks[i].a = a;
        attacks[i].mp = b;
    };

    map<ll, ll> dp;

    auto ecmin = [&](ll next_damage, ll next_use_mp) {
        if (dp.find(next_damage) == dp.end()) {
            dp[next_damage] = next_use_mp;
        } else {
            cmin(dp[next_damage], next_use_mp);
        }
    };

    dp[0] = 0;
    for (auto e : dp) {
        ll current = e.first;
        ll use_mp = e.second;

        if (current > h) continue;

        for (Attack &a : attacks) {
            ll next_use_mp = use_mp + a.mp;
            ll next_damage = current + a.a;

            ecmin(next_damage, next_use_mp);
        }
    }

    ll ans = INF;
    for (auto e : dp) {
        if (e.first < h) continue;
        cmin(ans, e.second);
    }
    cout << ans << endl;
}
