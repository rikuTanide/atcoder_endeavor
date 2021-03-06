#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e10;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;


int main() {
    int n;
    double t, a;
    cin >> n >> t >> a;

    pair<double, int> ans(INF, 0);

    rep(i, n) {
        double h;
        cin >> h;

        double x = t - (h * 0.006);

        double diff = abs(a - x);
        pair<double, int> now(diff, i + 1);
        ans = min(ans, now);
    }

    cout << ans.second << endl;

}

