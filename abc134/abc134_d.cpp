#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;
static const ll MOD = 1000000007;


int main() {
    int n;

    cin >> n;

    vector<int> a(n + 1);
    rep(i, n)cin >> a[i + 1];
    vector<int> b(n + 1);
    for (int i = n; i >= 1; --i) {
        int sum = 0;
        for (int j = i + i; j <= n; j += i) {
            sum ^= b[j];
        }
        b[i] = sum ^ a[i];
    }
    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (b[i])ans.push_back(i);
    }

    cout << ans.size() << endl;
    rep(i, ans.size()) {
        printf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
    }

}

