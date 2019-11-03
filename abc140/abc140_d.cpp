#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;

int main() {

    int n, k;
    cin >> n >> k;

    string s;

    cin >> s;

    int ini = 0;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            ini++;
        }
    }

    int ans = min(ini + 2 * k, n - 1);


    cout << ans << endl;

}
