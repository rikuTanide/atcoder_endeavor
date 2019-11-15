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

typedef tuple<string, int, int> T;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> dq(n);
    rep(i, n) {
        cin >> dq[i];
    }
    int ans = 0;
    for (int l = 0; l < k; l++) {
        for (int r = 0; r < k - l; r++) {
            if (l + r > n) break;
            int d = k - l - r;
            int now = 0;
            vector<int> s;
            for (int i = 0; i < l; i++) {
                now += dq[i];
                s.push_back(dq[i]);
            }
            for (int i = n - r; i < n; i++) {
                now += dq[i];
                s.push_back(dq[i]);
            }
            sort(s.begin(), s.end());
            for (int i = 0; i < d; i++) {
                if (i >= s.size()) break;
                if (s[i] >= 0) break;
                now -= s[i];
            }
            ans = max(ans, now);
        }
    }

    cout << ans << endl;
}

