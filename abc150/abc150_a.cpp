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
const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;
map<ll, map<ll, ll>> cache;

ll gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    if (cache.find(x) != cache.end() && cache[x].find(y) != cache[x].end()) {
        return cache[x][y];
    }
    if (y == 0) {
        return x;
    }
    ll k = gcd(y, x % y);
    cache[x][y] = k;
    return k;
}

ll lcd(ll x, ll y) {
    return x * y / gcd(x, y);
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> numbers(n);
    rep(i, n)cin >> numbers[i];
    rep(i, n) {
        if (numbers[i] % 2 == 1) __throw_runtime_error("kiss");
    }
    ll l = 1;
    rep(i, n) {
        l = lcd(l, numbers[i]);
    }

    ll start = l / 2;

    ll nm = m - start;
    if (nm <= 0) {
        cout << 0 << endl;
        return 0;
    }

    cout << nm / l + 1 << endl;

}