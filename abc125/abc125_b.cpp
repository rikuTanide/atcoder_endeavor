#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;

//< ave , a(time), b(manzoku) >
typedef tuple<double, int, int> A;

int main() {
    int n;
    cin >> n;
    vector<int> vs(n);

    rep(i, n) {
        int v;
        cin >> v;
        vs[i] = v;
    }


    rep(i, n) {
        int c;
        cin >> c;
        vs[i] -= c;
    }

    sort(vs.rbegin(), vs.rend());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vs[i] < 0) {
            break;
        } else {
            ans += vs[i];
        }
    }

    cout << ans << endl;

}

