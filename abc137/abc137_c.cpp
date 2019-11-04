#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

int main() {

    int n;
    cin >> n;
    set<string> strs;

    int ans = 0;
    rep(i, n) {
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        ans += strs.count(str);
        strs.insert(str);

    }



    cout << ans << endl;
}
