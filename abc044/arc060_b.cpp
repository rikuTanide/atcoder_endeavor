#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;


ll f(ll b, ll n) {
    if (n < b) return n;
    return f(b, n / b) + n % b;
}


int main() {

    ll n, s;
    cin >> n >> s;

    if (s == n) {
        cout << n + 1 << endl;
        return 0;
    }

    ll sq = sqrt(n) + 1;
    for (ll i = 2; i <= sq; i++) {
        if (f(i, n) == s) {
            cout << i << endl;
            return 0;
        }
    };

    for (ll p = sq; p >= 1; p--) {
        ll b = (n - s) / p + 1;
        if (b <= 1) continue;
        if (f(b, n) == s) {
            cout << b << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}