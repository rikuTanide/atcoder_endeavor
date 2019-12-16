#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;
typedef pair<int, int> P;

int wa(ll n) {
    ll ans = 0;
    while (n > 0) {
        ans += (n % 10);
        n /= 10;
    }
    return ans;
}

int main() {

    ll n;
    cin >> n;

    vector<vector<bool >> calendar(10, vector<bool>(n));// calendar[時間帯][お店]
    rep(i, n) {
        rep(t, 10) {
            int c;
            cin >> c;
            calendar[t][i] = c == 1;
        }
    }
    vector<vector<ll >> profit(11, vector<ll>(n));// calendar[マッチ数][お店]
    rep(i, n) {
        rep(t, 11) {
            ll p;
            cin >> p;
            profit[t][i] = p;
        }
    }

    ll ans = MINF;

    for (int i = 1; i < 1 << 10; i++) {
        ll sum = 0;
        for (ll s = 0; s < n; s++) {
            ll match = 0;
            for (ll t = 0; t < 10; t++) {
                if (((i >> t) & 1) == 1) {
                    if (calendar[t][s]) {
                        match++;
                    }
                }
            }
            ll now = profit[match][s];
            sum += now;
        }
        cmax(ans, sum);

    }
    cout << ans << endl;
}