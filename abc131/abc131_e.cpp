#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
const ll INF = 1001001001;

const int mod = 1000000007;

int main() {

    int n, k;
    cin >> n >> k;
    int mx = (n - 1) * (n - 2) / 2;

    if (mx < k) {
        cout << -1 << endl;
        return 0;
    }


    int add = mx - k;
    cout << n - 1 + add << endl;

    vector<P> ans;
    rep(i, n - 1) {
        cout << i + 1 << ' ' << n << endl;
    }

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << i << ' ' << j << endl;
            add--;
            if (add == 0) {
                return 0;
            }
        }
    }
}