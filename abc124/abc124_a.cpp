#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
//const int INF = INT_MAX  ;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;

//< ave , a(time), b(manzoku) >
typedef tuple<double, int, int> A;

int gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int main() {
    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 2 * a << endl;
        return 0;
    } else {
        if (b > a) {
            swap(a, b);
        }
        cout << a + (a - 1) << endl;
    }

}

