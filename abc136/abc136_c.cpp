#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;

const ll INF = 1001001001;


int main() {

    int n;
    cin >> n;
    vector<int> hs;

    rep(i, n) {
        int h;
        cin >> h;
        hs.push_back(h);
    }

    int pre = -999;
    rep(i, n) {
        if (pre <= hs[i] - 1) {
            pre = hs[i] - 1;
        } else if (pre <= hs[i]) {
            pre = hs[i];
        } else {
            puts("No");
            return 0;
        }
    }
    puts("Yes");


}
