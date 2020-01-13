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
    string s;
    cin >> s;
    vector<int> weights(s.size(), 0);
    rep(i, s.size()) {
        char c = s[i];
        if (c == 'M')continue;
        if (c == '+') weights[i]++;
        if (c == '-') weights[i]--;
    }
    for (int i = s.size() - 2; i >= 0; i--) {
        weights[i] += weights[i + 1];
    }

    vector<int> move_only;
    rep(i, s.size()) {
        char c = s[i];
        if (c == 'M') {
            move_only.push_back(weights[i]);
        }
    }

    sort(move_only.begin(), move_only.end());

    int ans = 0;
    for (int i = 0; i < move_only.size() / 2; i++) {
        ans -= move_only[i];
    }
    for (int i = move_only.size() / 2; i < move_only.size(); i++) {
        ans += move_only[i];
    }
    cout << ans << endl;

}
