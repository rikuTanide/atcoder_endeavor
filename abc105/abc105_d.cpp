#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
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
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> as(n);
    rep(i, n) {
        cin >> as[i];
    }

    vector<ll> sum(n + 1);
    sum[0] = 0;
    for (ll i = 0; i < n; i++) {
        sum[i + 1] = (sum[i] + as[i]) % m;
    }

    map<ll, ll> used;

    ll ans = 0;
    for(ll i = 0 ; i < sum.size() ; i ++) {
        ans +=  used[sum[i]];
        used[sum[i]] ++;
    }

    cout << ans << endl;


}
