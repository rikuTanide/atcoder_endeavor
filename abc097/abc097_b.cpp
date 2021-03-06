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
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
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

    int x;
    cin >> x;

    vector<ll> kohos;
    kohos.push_back(1);
    for (int a = 2; a < x; a++) {
        for (int b = 2; b < x; b++) {
            ll p = pow2(a, b);
            if (p > x) {
                break;
            }
            kohos.push_back(p);

        }
    }

    ll ans = 0;
    for (int i = 0; i < kohos.size(); i++) {
        cmax(ans, kohos[i]);
    }
    cout << ans << endl;
}