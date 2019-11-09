#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;
static const ll MOD = 1000000007;
const int n = 13;
ll dp[100005][n];

int main() {

    int k, x, y;
    cin >> k >> x >> y;

    bool mx = false, my = false, xys = false;

    if (x < 0) {
        x = -x;
        mx = true;
    }
    if (y < 0) {
        y = -y;
        my = true;
    }

    if (x < y) {
        swap(x, y);
        xys = true;
    }

    vector<vector<int>> ans;
    [&] {
        if ((x + y) % 2 == 1 && k % 2 == 0) {
            cout << -1 << endl;
            exit(0);
        }

        if (x + y == k) {
            ans.push_back({x, y});
            return;;
        }

        int n = (x + y + k - 1) / k;
        if (n <= 1) n = 2;

        if ((x + y) % 2 != n * k % 2) n++;

        if (n == 3 && x < k) {
            int over_right = (k + x - y) / 2;
            ans = {
                    {x,              -k + x},
                    {x + over_right, y - (k - over_right)},
                    {x,              y},
            };
            return;
        }

        int over = (k * n - (x + y)) / 2;
        for (int i = 0; i < n; i++) {
            int dist = (i + 1) * k;
            if (dist <= y + over) {
                ans.push_back({0, dist});
            } else if (dist <= y + over + x) {
                ans.push_back({dist - y - over, y + over});
            } else {
                ans.push_back({x, y + ((n - (i + 1)) * k)});
            }
        }
    }();

    if (xys) {
        for (int i = 0; i < ans.size(); i++) {
            swap(ans[i][0], ans[i][1]);
        }
    }

    if (mx) {
        for (int i = 0; i < ans.size(); i++) {
            ans[i][0] = -ans[i][0];
        }
    }

    if (my) {
        for (int i = 0; i < ans.size(); i++) {
            ans[i][1] = -ans[i][1];
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << ' ' << ans[i][1] << endl;
    }

}

