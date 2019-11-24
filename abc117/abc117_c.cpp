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
    int n, m;
    cin >> n >> m;

    vector<int> ls(m);
    rep(i, m) {
        int l;
        cin >> l;
        ls[i] = l;
    }
    sort(ls.begin(), ls.end());


    vector<int> distances(m - 1);
    for (int i = 0; i < m - 1; i++) {
        int distance = ls[i + 1] - ls[i];
        distances[i] = distance;
    }

    sort(distances.rbegin(), distances.rend());

    ll ans = accumulate(distances.begin(), distances.end(), 0);

    for (int i = 0; i < n - 1; i++) {
        if (i >= m - 1) break;
        ans -= distances[i];
    }

    cout << ans << endl;

}

