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
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

int main() {
    int n, y;
    cin >> n >> y;
    for (int m = 0; m <= n; m++) {
        for (int g = 0; m + g <= n; g++) {
            int s = n - m - g;
            if (m * 10000 + g * 5000 + s * 1000 == y) {
                printf("%d %d %d\n", m, g, s);
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;
}