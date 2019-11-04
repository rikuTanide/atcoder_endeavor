#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

int main() {

    int a, b;
    cin >> a >> b;

    cout << max(a + b, a - b, a * b) << endl;
}
