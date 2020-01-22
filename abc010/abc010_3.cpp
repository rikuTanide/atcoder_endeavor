#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
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
    int txa, tya, txb, tyb, t, v;
    cin >> txa >> tya >> txb >> tyb >> t >> v;

    int n;
    cin >> n;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        int cx = abs(txa - x);
        int cy = abs(tya - y);

        int dx = abs(x - txb);
        int dy = abs(y - tyb);

        int l1 = cx * cx + cy * cy;
        int l2 = dx * dx + dy * dy;

        double l1r = sqrt(l1);
        double l2r = sqrt(l2);

        double all = l1r + l2r;
        int mx = t * v ;

        if (mx >= all) {
            cout << "YES" << endl;
            return 0;
        }

    }
    cout << "NO" << endl;
}
