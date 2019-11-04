#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

int main() {

    int k, x;
    cin >> k >> x;

    for (int s = x - k + 1; s < min(x + k, 1000000); s++) {
        cout << s << endl;

    }

}
