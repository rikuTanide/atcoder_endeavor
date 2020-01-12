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


int main() {
    int n;
    cin >> n;
    vector<int> islands(n);
    rep(i, n)cin >> islands[i];

    int sum = accumulate(islands.begin(), islands.end(), 0);
    if (sum % n != 0) {
        cout << -1 << endl;
        return 0;
    }

    int par = sum / n;
    int l = 0;
    int ans = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
        l += islands[i];
        c ++;
        if (l == par * c) {
            l = 0;
            c = 0;
        } else {
            ans++;
        }
    }
    cout << ans << endl;

}
