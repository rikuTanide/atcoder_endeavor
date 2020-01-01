#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;

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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    for (int i = 0; i < ty - sy; i++) {
        cout << 'U';
    }
    for (int i = 0; i < tx - sx; i++) {
        cout << 'R';
    }

    for (int i = 0; i < ty - sy; i++) {
        cout << 'D';
    }
    for (int i = 0; i < tx - sx; i++) {
        cout << 'L';
    }

    cout << 'L';
    for (int i = 0; i < ty - sy + 1; i++) {
        cout << 'U';
    }
    for (int i = 0; i < tx - sx + 1; i++) {
        cout << 'R';
    }
    cout << 'D';

    cout << 'R';
    for (int i = 0; i < ty - sy + 1; i++) {
        cout << 'D';
    }
    for (int i = 0; i < tx - sx + 1; i++) {
        cout << 'L';
    }
    cout << 'U' << endl;
}