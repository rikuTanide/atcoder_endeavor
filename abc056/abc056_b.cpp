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
    int w, a, b;
    cin >> w >> a >> b;

    if (a <= b && b <= a + w) {
        cout << 0 << endl;
        return 0;
    }

    if (a <= b + w && b + w <= a + w) {
        cout << 0 << endl;
        return 0;
    }

    int ans1 = abs(b - a);
    int ans2 = abs(b - (a + w));
    int ans3 = abs(b + w - (a + w));
    int ans4 = abs(b + w - a);

    int ans = ans1;
    cmin(ans, ans2);
    cmin(ans, ans3);
    cmin(ans, ans4);

    cout << ans << endl;

}
