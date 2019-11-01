#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {

    int n;
    cin >> n;
    vector<int> ds(n);
    rep(i, n) {
        int d;
        cin >> d;
        ds[i] = d;
    }
    int dsum = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (x == y) {
                continue;
            }
            dsum += (ds[x] * ds[y]);
        }
    }

    cout << (dsum / 2) << endl;

}

