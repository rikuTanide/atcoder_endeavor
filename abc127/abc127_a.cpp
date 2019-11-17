#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef tuple<string, int, int> T;

int main() {

    int a, b;
    cin >> a >> b;

    if (a >= 13) {
        cout << b << endl;
        return 0;
    }
    if (a > 5) {
        cout << (b / 2) << endl;
        return 0;
    }

    cout << 0 << endl;

}

