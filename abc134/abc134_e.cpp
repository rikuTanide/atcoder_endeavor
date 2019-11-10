#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;
static const ll MOD = 1000000007;


int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n)cin >> a[i];

    deque<int> d;
    rep(i, n) {
        int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (p == 0) {
            d.push_front(a[i]);
        } else {
            d[p - 1] = a[i];
        }
    }

    int ans = d.size();
    cout << ans << endl;

}

