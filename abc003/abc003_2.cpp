#include <bits/stdc++.h>
#include <cmath>

//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

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

bool is_atcoder(char c) {
    switch (c) {
        case 'a':
        case 't':
        case 'c':
        case 'o':
        case 'd':
        case 'e':
        case 'r':
            return true;
        default:
            return false;
    }
}

signed main() {
    string s, t;
    cin >> s >> t;

    for (int i = 0; i < s.size(); i++) {
        char sc = s[i], tc = t[i];

        if (sc == tc) continue;
        if (sc == '@' && is_atcoder(tc)) continue;
        if (tc == '@' && is_atcoder(sc)) continue;
        cout << "You will lose" << endl;
        return 0;
    }

    cout << "You can win" << endl;
}