#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> ls(n);
    rep(i, n) {
        int l;
        cin >> l;
        ls[i] = l;
    }
    sort(ls.begin(), ls.end());
    int sum = accumulate(ls.begin(), ls.end() - 1, 0);
    cout << (sum > ls[n - 1] ? "Yes" : "No") << endl;
}

