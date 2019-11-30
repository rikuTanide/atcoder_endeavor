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
//ifstream myfile("C:\\Users\\riku\\Downloads\\01.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;

ll pow2(ll a, ll b) {
    if (b == -1 ) {
        return 0;
    }
    if (b == 0) {
        return 1;
    }
    ll res = a;
    for (ll i = 1; i < b; i++) {
        res *= a;
    }
    return res;
}

ll calcR(ll l) {
    for (int i = 20;; i--) {
        if (pow2(2, i) <= l) {
            return i;
        }
    }
}

int main() {
    ll l;
    cin >> l;

    ll r = calcR(l);

    vector<vector<ll>> vers;
    for (int i = 0; i < r; i++) {
        vector<ll> ver0 = {i, i + 1, 0};
        vector<ll> ver1 = {i, i + 1, pow2(2, i)};
        vers.push_back(ver0);
        vers.push_back(ver1);
    }

    for (int t = r; t >= 0; t--) {
        ll a = l - pow2(2, t);
        if (a >= pow2(2, r)) {
            vector<ll> ver = {t, r, a};
            vers.push_back(ver);
            l -= pow2(2, t);
        }
    }

    cout << r + 1 << ' ' << vers.size() << endl;

    rep(i, vers.size()) {
        vector<ll> ver = vers[i];
        printf("%lld %lld %lld\n", ver[0] + 1, ver[1] + 1, ver[2]);
    }


}
