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
// std::cout << std::bitset<8>(9);

ll pow2(ll a, ll b) {
    ll res = a;
    for (ll i = 1; i < b; i++) {
        res *= a;
    }
    return res;
}

int main() {

    ll n;
    cin >> n;
    vector<ll> koho;

    koho.push_back(1);
    for (int i = 1; pow2(9, i) <= n; i++) {
        koho.push_back(pow2(9, i));
    }
    for (int i = 1; pow2(6, i) <= n; i++) {
        koho.push_back(pow2(6, i));
    }

    sort(koho.begin(), koho.end());
    ll ans = 0;
    while (n > 0) {

        if(n == 12) {
            ans += 2;
            break;
        }
        if(n == 13) {
            ans += 3;
            break;
        }
        if(n == 14) {
            ans += 4;
            break;
        }

        ll k = *(upper_bound(koho.begin(), koho.end(), n) - 1);
        n -= k;
        ans++;
    }
    cout << ans << endl;

}
