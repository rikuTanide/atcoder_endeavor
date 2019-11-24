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
    vector<ll> as(n);
    rep (i, n) {
        int a;
        cin >> a;
        as[i] = a;
    }
    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());

    ll weak = as[0];
    for (int i = 0; i < as.size() - 1; i++) {
        ll m2 = as[i + 1];
        ll diff = m2 % weak;
        if (diff == 0) {
             diff = weak;
        }
        if(diff < weak) {
            weak = diff;
        }
    }

    cout << weak << endl;


}

