#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
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
/*
    for (int h = 1; h < 100; h++) {
        int now = 0;
        vector<int> current = {h};
        while (!current.empty()) {
            vector<int> next;
            for (int k : current) {
                now++;
                if (k == 1) continue;
                next.push_back(k / 2);
                next.push_back(k / 2);
            }
            current = next;
            next = {};
        }
        cout << now << endl;
    }
*/

//    for (int h = 1; h < 100; h++) {

    ll h;
    cin >> h;

    ll current = 1;
    ll i = 0;
    while (current <= h) {
        i++;
        current *= 2;
    }

    cout << (1ll << i) - 1 << endl;
//    }
}
