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

ll f(ll i) {
    if (i % 2 == 0) {
        return i / 2;
    } else {
        return 3 * i + 1;
    }

}

int main() {
    ll s;
    cin >> s;

    set<ll> u;
    u.insert(s);
    ll before = s;
    ll count = 1;
    while (true) {
        count++;
        before = f(before);
        auto it = u.find(before);
        if (it == u.end()) {
            u.insert(before);
        } else {
            cout << count << endl;
            return 0;
        }
    }

}