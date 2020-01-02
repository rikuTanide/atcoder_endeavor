#include <bits/stdc++.h>
#include <cmath>

using namespace std;
//typedef long long ll;
typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;


int main() {

    int min_x = 0;
    int max_x;
    int min_y = 0;
    int max_y;

    cin >> max_x >> max_y;

    int n;
    cin >> n;
    rep(i, n) {
        int x, y, a;
        cin >> x >> y >> a;

        if (a == 1) {
            cmax(min_x, x);
        } else if (a == 2) {
            cmin(max_x, x);
        } else if (a == 3) {
            cmax(min_y, y);
        } else if (a == 4) {
            cmin(max_y, y);
        }
    }

    int w = max_x - min_x;
    cmax(w, 0);
    int h = max_y - min_y;
    cmax(h, 0);
    cout << w * h << endl;

}
