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
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n)cin >> a[i];

    vector<int> b = a;
    sort(b.rbegin(), b.rend());

    int first = b[0];
    int second = b[1];

    for (auto i : a) {
        if (i == first) {
            cout << second << endl;
        } else {
            cout << first << endl;
        }
    }


}

