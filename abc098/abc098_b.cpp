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

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

int main() {
    int n;
    string s;

    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {

        set<char> l, r;

        for (int k = 0; k < s.size(); k++) {
            if (k < i) {
                l.insert(s[k]);
            } else {
                r.insert(s[k]);
            }
        }

        int now = 0;
        for (char c : l) {
            if (r.find(c) != r.end()) {
                now++;
            }
        }

        cmax(ans, now);

    }
    cout << ans << endl;
}