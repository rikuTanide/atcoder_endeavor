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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(m);

    rep(i, m) {
        int k;
        cin >> k;
        vec[i].resize(k);
        rep(j, k) {
            cin >> vec[i][j];
            vec[i][j]--;
        }
    }

    vector<int> p(m);
    rep(i, m) {
        cin >> p[i];
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        bool ok = true;
        rep(j, m) {
            int c = 0;
            for (int id : vec[j]) {
                if ((i >> id) & 1) {
                    c++;
                }
            }
            c %= 2;
            if (c != p[j]) {
                ok = false;
            }
        }
        if (ok) {
            ans++;
        }
    }
    cout << ans << endl;
}

