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



int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = INF;
    {
        // cを1枚も買わない
        ll now = a * x + b * y;
        cmin(ans, now);
    }
    {
        // cを2xだけ買う
        ll c_cost = c * 2 * x;
        ll b_cost = 0;
        if (x < y) {
            b_cost = (y - x) * b;
        }
        ll now = c_cost + b_cost;
        cmin(ans, now);
    }
    {
        // cを2yだけ買う
        ll c_cost = c * 2 * y;
        ll a_cost = 0;
        if (x > y) {
            a_cost = (x - y) * a;
        }
        ll now = c_cost + a_cost;
        cmin(ans, now);
    }

    cout << ans << endl;
}