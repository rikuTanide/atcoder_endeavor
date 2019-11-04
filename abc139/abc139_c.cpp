#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;

int main() {

    int n;
    cin >> n;
    int max_len = 0;
    int current_len = -1;
    ll prev = INF;

    rep(i, n) {
        ll h;
        cin >> h;
        if (h > prev) {
            current_len = 0;
        } else {
            current_len++;
            max_len = max(max_len, current_len);
        }
        prev = h;
    }

    cout << max_len << endl;

}
