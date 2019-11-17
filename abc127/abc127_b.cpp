#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef tuple<string, int, int> T;

int main() {

    ll r, d, x2000;

    cin >> r >> d >> x2000;

    ll now = x2000;
    for (ll i = 0; i < 10; i++) {
        now = now * r - d;
        cout << now << endl;
    }

}

