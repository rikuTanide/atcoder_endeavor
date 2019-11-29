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

int gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int main() {
    ll n, x;
    cin >> n >> x;


    vector<ll> xs(n);
    rep(i, n) {
        cin >> xs[i];
    }

    sort(xs.begin(), xs.end());
    rep(i, n) {
        xs[i] = abs(xs[i] - x);
    }

    ll ans = xs.back();

    for (ll i = 0; i < n - 1; i++) {
        ll now = gcd(xs[i], xs[i + 1]);
        ans = min(ans, now);
    }
    cout << ans << endl;

}
