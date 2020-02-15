#include <bits/stdc++.h>
#include <cmath>

//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;

//bool contain(set<P> &s, P a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

int main() {
    int x = 0, y = 0;
    string s;
    cin >> s;

    int t;
    cin >> t;

    int q = 0;
    for (char c : s) {
        if (c == 'L') x--;
        else if (c == 'R') x++;
        else if (c == 'U') y++;
        else if (c == 'D') y--;
        else if (c == '?') q++;
        else __throw_runtime_error("konai");
    }

    int md = abs(x) + abs(y);
    if (t == 1) {
        cout << md + q << endl;
    } else {
        if (q <= md) {
            cout << md - q << endl;
        } else {
            cout << (q - md) % 2 << endl;
        }
    }

}

