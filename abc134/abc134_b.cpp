#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;
static const ll MOD = 1000000007;


int main() {
    int n, d;
    cin >> n >> d;

    int range = 2 * d + 1;
    cout << (n + range - 1) / range << endl;
}

