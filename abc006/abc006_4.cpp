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

int check(vector<int> &numbers, int i, int n) {
    vector<int> selected;
    for (int j = 0; j < n; j++) {
        if ((i >> j) & 1) selected.push_back(numbers[j]);
    }
    int mx = selected.size() - 1;
    for (int j = 0; j < mx; j++) {
        if (selected[j] > selected[j + 1]) return -1;
    }
    return selected.size();
}

int main() {

    int n;
    cin >> n;
    assert(n <= 16);
    vector<int> numbers(n);
    rep(i, n) cin >> numbers[i];

    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int now = check(numbers, i, n);
        cmax(ans, now);
    }
    cout << n - ans << endl;


}
