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


int main() {
    int n, m;

    cin >> n >> m;

    vector<int> as(m,0);

    rep(i, n) {
        int k ;
        cin >> k;
        rep(j, k) {
            int a;
            cin >> a;
            a --;
            as[a]++;
        }
    }

    int ans = 0;
    for (int k : as) {
        if (k == n) {
            ans++;
        }
    }
    cout << ans << endl;

}

