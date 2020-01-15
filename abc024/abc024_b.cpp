#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct Open {
    int open;
    int close;
};

int main() {

    int n, t;
    cin >> n >> t;
    vector<int> consumers(n);
    rep(i, n) cin >> consumers[i];

    vector<Open> opens(n);
    rep(i, n) {
        int c = consumers[i];
        opens[i].open = c;
        opens[i].close = c + t;
    }

    rep(i, n - 1) {
        if (opens[i].close > opens[i + 1].open) {
            opens[i].close = opens[i + 1].open;
        }
    }

    int ans = 0;
    rep(i, n) {
        ans += (opens[i].close - opens[i].open);
    }
    cout << ans << endl;

}
