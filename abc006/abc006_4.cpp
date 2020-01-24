#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
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

int check(vector<int> &numbers, int n) {
    vector<int> dp(n, 1);
    for (int j = 1; j < n; j++) {
        for (int k = 0; k < j; k++) {
            if (numbers[k] < numbers[j]) {
                int next = dp[k] + 1;
                cmax(dp[j], next);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {

    int n;
    cin >> n;
    assert(n <= 1000);
    vector<int> numbers(n);
    rep(i, n) cin >> numbers[i];

    int ans = 0;
    int now = check(numbers, n);
    cmax(ans, now);
    cout << n - ans << endl;


}
