#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

int main() {

    int n;
    cin >> n;
    map<string, int> strs;

    ll ans = 0;
    rep(i, n) {
        string str;
        cin >> str;
        sort(str.begin(), str.end());

        if (strs.find(str) == strs.end()) {
            strs[str] = 1;
        } else {
            strs[str] ++;
        }
    }

    for (const auto&[key, value] : strs) {
        ans += value * (value - 1) / 2;
    }

    cout << ans << endl;
}
