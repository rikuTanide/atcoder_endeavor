#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\01.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;

int main() {

    ll n, k;
    cin >> n >> k;

    priority_queue<ll> minus;
    priority_queue<ll, vector<ll>, greater<ll>> plus;
    priority_queue<ll> center;

    rep(i, n) {
        ll x;
        cin >> x;
        if (x < 0) {
            minus.push(x);
        } else if (x == 0) {
            center.push(x);
        } else {
            plus.push(x);
        }
    }


    ll plus_distance = 0;
    ll minus_distance = 0;
    ll ans = INF;
    for (ll i = 0; i < k; i++) {
        if (plus.empty()) {
            break;
        }
        ll plus_top = plus.top();
        center.push(plus_top);
        plus_distance = plus_top;
        plus.pop();
    }
    if (center.size() == k) {
        ans = plus_distance;
    }

    for (ll i = 0; i < k; i++) {
        if (minus.empty()) {
            break;
        }
        ll minus_top = minus.top();
        minus.pop();
        minus_distance = abs(minus_top);
        center.push(minus_top);

        if (center.size() > k) {
            center.pop();
            plus_distance = center.top();
        }

        if (center.size() == k) {
            if (plus_distance > 0 && minus_distance > 0) {
                ll now = min(plus_distance * 2 + minus_distance, minus_distance * 2 + plus_distance);
                ans = min(now, ans);
            } else {
                ll now = minus_distance;
                ans = min(ans, now);
            }
        }

    }

    cout << ans << endl;


}
