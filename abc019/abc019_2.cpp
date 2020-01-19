#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
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

typedef pair<char, ll> P;

int main() {
    string s;
    cin >> s;
    int l = 1;
    vector<P> sequence;
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == s[i]) {
            l++;
        } else {
            sequence.push_back(P(s[i - 1], l));
            l = 1;
        }
    }
    sequence.push_back(P(s.back(), l));

    for (P p : sequence) {
        cout << p.first << p.second;
    }
    cout << endl;

}

