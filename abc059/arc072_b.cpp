#include <bits/stdc++.h>
#include <cmath>

#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;


bool recursive(ll x, ll y, bool turn, ll depth) {

    bool win = false;

    for (ll k = 2; k <= x; k += 2) {
        bool b = !recursive(x - k, y + (k / 2), !turn, depth + 1);
        if (b) win = true;
    }
    for (ll k = 2; k <= y; k += 2) {
        bool b = !recursive(x + (k / 2), y - k, !turn, depth + 1);
        if (b) win = true;
    }

    return win;
}


int main() {

    ll x, y;
    cin >> x >> y;

//    for (ll x = 0; x < 10; x++) {
//        for (ll y = 0; y < 10; y++) {
//            bool b;
//    if (abs(x - y) <= 1) {
//        b = false;
//    } else {
//        b = true;
//    }
//
//            cout << ' ' << b ;
//
//        }
//        cout << endl;
//    }

//    bool b = recursive(x, y, true, 0);
//    cout << (b ? "Alice" : "Brown") << endl;

    if (abs(x - y) <= 1) {
        cout << "Brown" << endl;
    } else {
        cout << "Alice" << endl;
    }

}

