#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
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
    map<char, int> sc;
    map<char, int> tc;
    string s, t;
    cin >> s >> t;
    for (char c : s) sc[c]++;
    for (char c : t) tc[c]++;
    set<char> atcoder = {'a', 't', 'c', 'o', 'd', 'e', 'r'};

    int sn = 0;
    int tn = 0;
    for (int c = 'a'; c <= 'z'; c++) {
        if (sc[c] == tc[c]) continue;
        if (!contain(atcoder, c)) {
            cout << "You will lose" << endl;
            return 0;
        }
        if (sc[c] < tc[c]) {
            sn += tc[c] - sc[c];
        } else {
            tn += sc[c] - tc[c];
        }
    }
    if (tc['@'] >= tn && sc['@'] >= sn) {
        cout << "You can win" << endl;
    } else {
        cout << "You will lose" << endl;
    }
}
