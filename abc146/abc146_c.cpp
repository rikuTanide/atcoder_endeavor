#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

int d(ll n) {
    return log10(n) + 1;
}

bool check(ll n, ll a, ll b, ll x) {
    ll price = n * a + b * d(n);
    return price <= x;
}

int main() {

    ll a, b, x;
    cin >> a >> b >> x;

    if (!check(1, a, b, x)) {
        cout << 0 << endl;
        return 0;
    }
    if (check(1000000000, a, b, x)) {
        cout << 1000000000 << endl;
        return 0;
    }

    ll ceil = 1000000000;
    ll floor = 1;

    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        bool ok = check(mid, a, b, x);
        if (ok) {
            floor = mid;
        }else {
            ceil = mid;
        }
    }

    cout << floor << endl;
}