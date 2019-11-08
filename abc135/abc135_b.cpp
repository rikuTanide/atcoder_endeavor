#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;

int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if (c != i + 1) {
            count++;
        }
    }

    if (count == 0 || count == 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}
