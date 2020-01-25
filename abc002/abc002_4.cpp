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

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

bool check(int i, int n, vector<vector<bool>> &friends) {
    vector<int> candidates;
    for (int j = 0; j < n; j++) {
        if ((i >> j) & 1) candidates.push_back(j);
    }
    for (int j = 0; j < candidates.size(); j++) {
        for (int k = j + 1; k < candidates.size(); k++) {
            int l = candidates[j];
            int r = candidates[k];
            if (!friends[l][r]) return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> friends(n, vector<bool>(n, false));
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        friends[x][y] = true;
        friends[y][x] = true;
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (check(i, n, friends)) {
            int now = __builtin_popcount(i);
            cmax(ans, now);
        }
    }
    cout << ans << endl;
}
