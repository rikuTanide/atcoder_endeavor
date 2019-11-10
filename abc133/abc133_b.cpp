#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;

const int mod = 1000000007;

int main() {

    set<ll> p;
    for (int i = 0; i < 100; i++) {
        p.insert(i * i);
    }

    int n, d;
    cin >> n >> d;

    vector<vector<int>> s = vector<vector<int>>(n, vector<int>(d, 0));

    rep(i, n) {
        rep(j, d) {
            cin >> s[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int sum = 0;
            for (int sd = 0; sd < d; sd++) {
                int z = s[i][sd] - s[j][sd];
                sum += z * z;
            }
            if (p.find(sum) != p.end()) {
                ans++;
            }
        }
    }

    cout << ans << endl;

}

