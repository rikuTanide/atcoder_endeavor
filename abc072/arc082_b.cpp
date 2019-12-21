#include <bits/stdc++.h>
#include <cmath>


#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);
    rep(i, n) {
        cin >> nums[i];
    }

    int ans = 0;
    bool active = false;
    for (int i = 0; i < n - 2; i++) {
        if (nums[i] == (i + 1) && (!active)) {
            active = true;
            ans++;
        } else {
            active = false;
        }
    }

    if (!active && nums[n - 1] == (n)) {
        ans++;
    }

    cout << ans << endl;
}