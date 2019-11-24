#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;


int main() {

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> ls(n);
    rep(i, n) {
        int k;
        cin >> k;
        ls[i] = k;
    }

    int ans = INF;

    for (int i = 0; i < (1 << (2 * n)); i++) {

        int ac = 0;
        int bc = 0;
        int cc = 0;

        int as = 0;
        int bs = 0;
        int cs = 0;

        string s = "";

        for (int k = 0; k < n; k++) {
            int kb = (i >> (2 * k)) & 3;
            if (kb == 0) {
                ac++;
                as += ls[k];
                s += "a ";
            } else if (kb == 1) {
                bc++;
                bs += ls[k];
                s += "b ";

            } else if (kb == 2) {
                cc++;
                cs += ls[k];
                s += "c ";

            } else {
                s += "d ";
            }
        }

        if (ac == 0 || bc == 0 || cc == 0) continue;

        int now = (ac - 1) * 10;
        now += (bc - 1) * 10;
        now += (cc - 1) * 10;

        now += abs(a - as);
        now += abs(b - bs);
        now += abs(c - cs);

        ans = min(ans, now);

    }

    cout << ans << endl;


}

