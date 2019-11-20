#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
//const int INF = INT_MAX  ;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;

typedef pair<int, char> PC;

int main() {
//    vector<int> f(5);
    int has = 10;
    int ans = 0;
    rep(i, 5) {
        int c;
        cin >> c;

        if (c % 10 != 0) {
            has = min(c % 10, has);
        }

        int d = ((c + 9) / 10) * 10;
        ans += d;
    }

    cout << ans - 10 + has << endl;

}

