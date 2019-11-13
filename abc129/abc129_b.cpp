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

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    rep(i, n) {
        cin >> a[i];
    }
    int rsum = accumulate(a.begin(), a.end(), 0);
    int lsum = 0;
    int d = rsum;
    for (int i = 0; i < n; i++) {
        rsum -= a[i];
        lsum += a[i];
        int nd = abs(rsum - lsum);
        d = min(d, nd);
    }

    cout << d << endl;


}

