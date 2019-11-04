#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

int main() {

    int n;
    cin >> n;
    vector<string> strs(n);

    rep(i, n) {
        cin >> strs[i];
        sort(strs[i].begin(), strs[i].end());
    }

    int ans = 0;
    for (int x = 0; x < n; x++) {
        for (int y = x + 1; y < n; y++) {
            if (strs[x] == strs[y]) {
                ans++;
            }
        }
    }


    cout << ans << endl;
}
