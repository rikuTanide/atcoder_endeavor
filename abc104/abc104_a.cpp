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
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;

int main() {
    int r;
    cin >> r;

    if (r < 1200) {
        cout << "ABC" << endl;
        return 0;
    }
    if (r < 2800) {
        cout << "ARC" << endl;
        return 0;
    }
    cout << "AGC" << endl;
}
