#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

int main() {
    ll n;
    cin >> n;


    vector<ll> numbers(n);
    rep(i, n) {
        cin >> numbers[i];
    }
    ll ans = 0;
    ll l = 0;
    ll r = 0;
    ll before_r = 0;
    for (;;) {
        r = [&] {
            ll now_plus = 0;
            ll now_xor = 0;

            for (ll j = l; j < n; j++) {
                now_plus += numbers[j];
                now_xor ^= numbers[j];
                if (now_plus != now_xor) {
                    return j - 1;
                } else {
                    ans++;
                }
            }
            return n - 1;
        }();


        ll now = (r - l) * (r - l + 1) / 2;


        ll before_l = l - 1;
        ll duplicated = (before_r - before_l) * (before_r - before_l + 1) / 2;
        if (l != 0)now -= duplicated;
        ans += now;

        if (r == n - 1) {
            break;
        }

        l++;
        before_r = r;

    }

    cout << ans << endl;
}
/*
 *
 */