#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;

const int mod = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> ds(n);
    rep(i, n) {
        cin >> ds[i];
    }

    sort(ds.begin(), ds.end());

    int bu = ds[n / 2 - 1];
    int bo = ds[n / 2];

    cout << bo - bu << endl;
}