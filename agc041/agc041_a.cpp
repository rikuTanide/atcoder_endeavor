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
const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
//const int mod = 1000000007;
const ll mod = INF / 1000;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    if (a < b) {
        swap(a, b);
    }

    if ((a - b)% 2 == 0) {
        cout << (a - b) / 2 << endl;
    } else {
        ll ans = 0;
        {
            ll now = 0;
            // 右経由
            ll right = n - a;
            now = right;
            b += right;
            now += (a - b + 1) / 2;
            ans = now;
        }
        {
            ll now = 0;
            // 左経由
            ll left = b - 1;
            now = left;
            a -= left;
            now += (a + 1) / 2;

            cmin(ans, now);
        }
        cout << ans << endl;
    }


}
