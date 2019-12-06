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
    for (int i = 1; i < 10; i++) {
        koho.push_back(pow2(9, i));
    }
    for (int i = 1; i < 10; i++) {
        koho.push_back(pow2(6, i));
    }

    sort(koho.begin(), koho.end());


    vector<ll> dp(n + 1, INF);
    dp[0] = 0;

    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j < koho.size(); j++) {
            if (dp.size() <= (i + koho[j])) break;
            dp[i + koho[j]] = min(dp[i + koho[j]], dp[i] + 1);
        }
    }

    cout << dp[n] << endl;

}