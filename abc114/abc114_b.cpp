#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e10;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;


int main() {

    string s;
    cin >> s;
    int ans = INF;
    for (int i = 0; i < s.size() - 2; i++) {
        string sub = s.substr(i, 3);
        int d = atoi(sub.c_str());
        int diff = abs(753 - d);
        ans = min(ans, diff);
    }

    cout << ans << endl;
}

