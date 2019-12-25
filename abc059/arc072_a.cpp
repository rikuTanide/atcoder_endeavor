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
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

ll to(ll target, ll now_sum, ll n) {

    ll next_sum = now_sum + n;
    if (target == -1 && next_sum <= -1) return n;
    if (target == 1 && next_sum >= 1) return n;
    ll ab = abs(now_sum - target);

    if (target == -1) return -ab;
    return ab;

}

int main() {
    ll n;
    cin >> n;

    vector<ll> numbers(n);
    rep(i, n)cin >> numbers[i];

    auto func = [&](int target) {
        ll now_sum = 0;

        vector<ll> changed = vector<ll>(n);
        for (ll i = 0; i < n; i++) {
            ll t = to(target, now_sum, numbers[i]);
            changed[i] = t;
            now_sum += t;
            target = -target;
        }

        ll now = 0;
        for (ll i = 0; i < n; i++) {
            now += abs(numbers[i] - changed[i]);
        }
        return now;
    };
    // 最初をマイナス
    ll ans = min(func(1), func(-1));

    cout << ans << endl;

}

