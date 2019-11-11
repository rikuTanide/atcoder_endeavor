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
    int n, l;
    cin >> n >> l;

    // 全部マイナス
    if ((l + n) <= 0) {
        int a1 = l;
        n = n - 1;
        //一番おいしいものを除く
        cout << n * (2 * a1 + (n - 1)) / 2 << endl;

        // またぐ
    } else if ((l <= 0) && (l + n) >= 0) {
        cout << n * (2 * l + (n - 1)) / 2 << endl;
        // 全部プラス
    } else {
        // 一番まずいものを除く

        int a1 = l + 1;
        n = n - 1;
        cout << n * (2 * a1 + (n - 1)) / 2 << endl;

    }

}