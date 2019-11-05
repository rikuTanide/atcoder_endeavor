#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;

const ll INF = 1001001001;


int main() {

    string s;
    cin >> s;

    int n = s.size();
    vector<int> ans(n);

    rep(r1, 2) {
        {
            int count = 0;
            rep(i, n) {
                if (s[i] == 'R') count++;
                else {
                    ans[i] += count / 2;
                    ans[i - 1] += (count + 1) / 2;
                    count = 0;
                }
            }
        }

        reverse(ans.begin(), ans.end());
        reverse(s.begin(), s.end());
        rep(i, n) {
            if (s[i] == 'L')s[i] = 'R';
            else s[i] = 'L';
        }

    }

    rep(i, n) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
