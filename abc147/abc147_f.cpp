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

int main() {
    ll n, x, d;
    cin >> n >> x >> d;

    if (d == 0) {
        if (x == 0) {
            cout << 1 << endl;
        } else {
            cout << n + 1 << endl;
        }
        return 0;
    }

    map<int, vector<P>> mp;
    rep(i, n + 1) {
        ll s = x * i;
        ll l = i * (i - 1) / 2;
        ll r = l + i * (n - i);
        s += l * d;
        r -= l;
        mp[(s + (d << 30)) % d].emplace_back(s, r);
    }
    ll ans = 0;
    for (auto p : mp) {
        auto a = p.second;
        int m = a.size();
        rep(i, m) a[i].first = (a[i].first - p.first) / d;
        vector<P> ev;
        rep(i, m) {
            ev.emplace_back(a[i].first, 1);
            ev.emplace_back(a[i].first + a[i].second + 1, -1);
        }
        sort(ev.begin(), ev.end());
        ll count = 0, pre = -INF;
        for (auto e : ev) {
            ll len = e.first - pre;
            if (count) ans += len;
            count += e.second;
            pre = e.first;
        }
    }
    cout << ans << endl;
}
