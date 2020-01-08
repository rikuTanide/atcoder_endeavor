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
const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
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
    ll n, k;
    cin >> n >> k;
    vector<ll> numbers(n);
    rep(i, n) {
        ll a;
        cin >> a;
        if (a == 0) {
            cout << n << endl;
            return 0;
        }
        numbers[i] = a;
    }


    queue<ll> use;
    queue<ll> staging;
    for (ll a : numbers) {
        staging.push(a);
    }

    ll products = 1;
    ll ans = 0;
    while (!staging.empty()) {
        ll staging_front = staging.front();
        if (products * staging_front <= k) {
            products *= staging_front;
            use.push(staging_front);
            cmax(ans, (ll) use.size());
            staging.pop();
        } else if (use.empty()) {
            staging.pop();
        } else {
            ll use_front = use.front();
            use.pop();
            products /= use_front;
        }
    }
    cout << ans << endl;
}
