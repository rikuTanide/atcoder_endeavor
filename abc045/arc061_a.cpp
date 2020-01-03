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
const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX;
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

    string s;
    cin >> s;

    vector<string> terms;

    for (int i = 0; i < (1 << (s.size() - 1)); i++) {
        string t = "";
        bitset<10> b(i);
        for (int j = 0; j < s.size(); j++) {
            t = t + s[j];
            if (b[j]) {
                terms.push_back(t);
                t = "";
            }
        }
        terms.push_back(t);
    }

    ll ans = 0;
    for (string str : terms) {
        ans += atoll(str.c_str());
    }

    cout << ans << endl;

}
