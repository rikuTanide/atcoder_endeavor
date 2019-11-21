#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
//const int INF = INT_MAX  ;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;

ll f(ll n) {
    ll pc = (n + 1) / 2;
    ll add = pc % 2;
    if ((n + 1) % 2 == 0) {
        return add;
    } else {
        return n ^ add;
    }
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll fa = f(a - 1);
    ll fb = f(b);
    cout << (fa ^ fb) << endl;
}

