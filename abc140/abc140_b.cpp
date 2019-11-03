#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;

int main() {
    int n;
    cin >> n;

    vector<int> fs(n);
    rep(i, n) {
        int f;
        cin >> f;
        f--;
        fs[i] = f;
    }
    int ds = 0;
    rep(i, n) {
        int d;
        cin >> d;
        ds += d;
    }
    vector<int> adds(n - 1);
    rep(i, n - 1) {
        int add;
        cin >> add;
        adds[i] = add;
    }

    for (int i = 0; i < n - 1; i++) {
        if (fs[i] == (fs[i + 1] - 1)) {
            ds +=  adds[fs[i]];
        }
    }
    cout << ds << endl;
}
