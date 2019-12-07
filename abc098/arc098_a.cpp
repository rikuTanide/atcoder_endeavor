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
    vector<char> muki_list(n);

    rep(i, n) {
        char c;
        cin >> c;
        muki_list[i] = c;
    }

    vector<ll> rui_nishi(n + 1);
    vector<ll> rui_higashi(n + 1);
    rui_higashi[0] = 0;
    for (ll i = 0; i < n; i++) {
        rui_higashi[i + 1] = rui_higashi[i];
        if (muki_list[i] == 'W') {
            rui_higashi[i + 1]++;
        }
    }

    rui_nishi[n] = 0;
    for (ll i = n - 1; i >= 0; i--) {
        rui_nishi[i] = rui_nishi[i + 1];
        if (muki_list[i] == 'E') {
            rui_nishi[i]++;
        }
    }

    ll ans = INF;
    for (int i = 0; i < n; i++) {
        ll now = rui_higashi[i] +rui_nishi [i + 1];
        cmin(ans, now);
    }

    cout << ans << endl;

}