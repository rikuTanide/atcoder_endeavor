#include <bits/stdc++.h>
#include <cmath>

using namespace std;
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

ll mDiv2(ll n) {
    if (n < 0 && (n % -2 == -1)) {
        return (n / -2) + 1;
    } else {
        return n / -2;
    }
}

ll mMod2(ll n) {
    return abs(n % -2);
}

int main() {

    ll n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    string ans = "";

    while (n != 0) {
        ll m = mMod2(n);
        n = mDiv2(n);
        ans = ((m == 0) ? '0' : '1') + ans;
    }

    cout << ans << endl;


}
