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
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;

vector<vector<ll>> sum;

void buildSumTable(ll n, ll m, vector<ll> &ls, vector<ll> &rs) {
    sum = vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0));
    for (ll i = 0; i < m; i++) {
        sum[ls[i]][rs[i]]++;
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            sum[i][j] += sum[i - 1][j];
            sum[i][j] += sum[i][j - 1];
            sum[i][j] -= sum[i - 1][j - 1];
        }
    }
}

ll getSumTable(ll l, ll r) {
    ll ans = sum[r][r] - sum[r][l - 1] - sum[l - 1][r] + sum[l - 1][l - 1];
    return ans;
}

int main() {
    ll n, m, q;

    cin >> n >> m >> q;

    vector<ll> ls;
    vector<ll> rs;

    rep(i, m) {
        ll l, r;
        cin >> l >> r;
        ls.push_back(l);
        rs.push_back(r);
    }

    vector<ll> qls;
    vector<ll> qrs;
    rep(i, q) {
        ll l, r;
        cin >> l >> r;
        qls.push_back(l);
        qrs.push_back(r);
    }

    buildSumTable(n, m, ls, rs);

    for (ll i = 0; i < q; i++) {
        ll ans = getSumTable(qls[i], qrs[i]);
        cout << ans << endl;
    }


}