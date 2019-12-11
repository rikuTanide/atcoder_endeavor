#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;


int main() {
    int n;
    cin >> n;
    vector<P> reds(n);
    vector<P> blues(n);

    rep(i, n) {
        int a, b;
        cin >> a >> b;
        P p(a, b);
        reds[i] = p;
    }

    rep(i, n) {
        int a, b;
        cin >> a >> b;
        P p(a, b);
        blues[i] = p;
    }

    sort(blues.begin(), blues.end());

    sort(reds.begin(), reds.end(), [](P i, P j) {
        return i.second > j.second;
    });
    set<int> red_used;
    int ans = 0;
    for (P blue : blues) {
        for (int i = 0; i < n; i++) {
            P red = reds[i];
            if (blue.first <= red.first || blue.second <= red.second) continue;
            if (red_used.find(i) != red_used.end()) continue;
            red_used.insert(i);
            ans++;
            break;
        }
    }

    cout << ans << endl;
}