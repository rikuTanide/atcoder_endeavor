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
    int h, w;
    cin >> h >> w;

    vector<string> s(h);

    rep(i, h) cin >> s[i];
    vector<vector<int>> cnt(h, vector<int>(w));

    rep(i, h) {
        vector<int> done(w);
        rep(j, w) {
            if (s[i][j] == '#') continue;
            if (done[j]) continue;
            int l = 0;
            while (j + l < w) {
                if (s[i][j + l] == '#')break;
                l++;
            }
            rep(k, l) {
                cnt[i][j + k] += l;
                done[j + k] = 1;
            }

        }
    }

    rep(j, w) {
        vector<int> done(h);
        rep(i, h) {
            if (s[i][j] == '#') continue;
            if (done[i]) continue;
            int l = 0;
            while (i + l < h) {
                if (s[i + l][j] == '#')break;
                l++;
            }
            rep(k, l) {
                cnt[i + k][j] += l;
                done[i + k] = 1;
            }
        }
    }

    int ans = 0;
    rep(i, h)rep(j, w) ans = max(ans, cnt[i][j] - 1);
    cout << ans << endl;

}

