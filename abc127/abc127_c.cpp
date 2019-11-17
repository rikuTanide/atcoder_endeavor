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
    int n, m;
    cin >> n >> m;

    int lm = 1, rm = n;

    rep (i, m) {
        int l, r;
        cin >> l >> r;

        lm = max(lm, l);
        rm = min(rm, r);
    }

    if(lm > rm) {
        cout << 0 << endl;
        return 0;
    }

    cout << rm - lm + 1 << endl;

}

