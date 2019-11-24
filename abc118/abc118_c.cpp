#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;

int gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int main() {
    int n;
    cin >> n;
    vector<ll> as(n);
    rep (i, n) {
        int a;
        cin >> a;
        as[i] = a;
    }


    for (int i = 0; i < n - 1; i++) {
        as[i + 1] = gcd(as[i], as[i + 1]);
    }


    cout << as[n - 1] << endl;


}

