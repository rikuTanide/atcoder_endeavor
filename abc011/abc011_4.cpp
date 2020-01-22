#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
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

int main() {
    ll n, d;
    cin >> n >> d;
    ll x, y;
    cin >> x >> y;

    if (x % d != 0) {
        cout << 0 << endl;
        return 0;
    }

    if (y % d != 0) {
        cout << 0 << endl;
        return 0;
    }

    x /= d;
    y /= d;


    vector<double> logfact(1001, 0);
    for (int i = 2; i <= 1000; ++i) {
        logfact[i] = logfact[i - 1] + log2(i);
    }

    // https://atcoder.jp/contests/abc011/submissions/9638050
    double ans = 0;
    for (ll right = 0; right <= n; right++) {
        ll left = right - x;
        ll vertical = n - right - left;
        ll down = (vertical - y) / 2;
        ll up = vertical - down;
        if (left < 0 || left > n)continue;
        if (right < 0 || right > n)continue;
        if (up < 0 || up > n)continue;
        if (down < 0 || down > n)continue;
        if (up + down + left + right != n) continue;
        assert(up - down == y);
        assert(right - left == x);

        double now = pow(2.0, (logfact[n] - logfact[up] - logfact[down] - logfact[left] - logfact[right] - 2.0 * n));
        ans += now;
    }
    printf("%.20f\n", ans);
}
