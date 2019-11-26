#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;

vector<ll> sou_count(52, 1);
vector<ll> pate_count(52, 1);


ll rec(ll n, ll x) {
    if (x == 1) {
        return 0;
    }
    if (1 < x && x <= 1 + sou_count[n - 1]) {
        return rec(n - 1, x - 1);
    }
    if (x == 2 + sou_count[n - 1]) {
        return pate_count[n - 1] + 1 + rec(n - 1, x - 2 - sou_count[n - 1]);
    }
    if (2 + sou_count[n - 1] < x && x <= 2 + 2 * sou_count[n - 1]) {
        return pate_count[n - 1] + 1 + rec(n - 1, x - 2 - sou_count[n - 1]);
    }
    return 2 * pate_count[n - 1] + 1;
}


int main() {


    for (int i = 0; i < 51; i++) {
        ll pc = (1ll << (i + 2)) - 1;
        ll sum = (1ll << (i + 3)) - 3;

        sou_count[i + 1] = sum;
        pate_count[i + 1] = pc;
    }

    ll n, x;
    cin >> n >> x;

    ll ans = rec(n,x);

    cout << ans << endl;

}

