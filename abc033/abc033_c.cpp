#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
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

bool findZero(vector<char> &cs) {
    for (char c : cs) {
        if (c == '0') {
            return true;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    vector<vector<char>> terms(1);

    for (char c :  s) {
        if (c == '+') {
            terms.push_back(vector<char>(0));
        } else {
            terms.back().push_back(c);
        }
    }

    ll ans = 0;
    for (vector<char> &cs : terms) {
        if (!findZero(cs)) {
            ans++;
        }
    }

    cout << ans << endl;
}