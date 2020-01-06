#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
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
    int t;
    cin >> s >> t;

    int unknown = 0;
    int x = 0;
    int y = 0;

    for (char c : s) {
        if (c == 'L') {
            x--;
        } else if (c == 'R') {
            x++;
        } else if (c == 'U') {
            y++;
        } else if (c == 'D') {
            y--;
        } else if (c == '?') {
            unknown++;
        } else {
            __throw_runtime_error("nai");
        }
    }

    int manhattan = abs(x) + abs(y);
    if (t == 1) {
        cout << manhattan + unknown << endl;
    } else {
        if (manhattan <= unknown) {
            cout << (unknown - manhattan) % 2 << endl;
        } else {
            cout << manhattan - unknown << endl;
        }
    }
}