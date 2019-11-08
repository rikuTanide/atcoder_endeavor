#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;

int main() {
    int a, b;
    cin >> a >> b;
    int c = a + b;
    if (c % 2 == 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << (c / 2) << endl;

}
