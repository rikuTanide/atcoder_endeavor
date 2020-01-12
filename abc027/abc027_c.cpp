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
//const ll INF = LONG_LONG_MAX;
const ll INF = 1e15;
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

bool check(ll k, ll n) {
    ll a = k * 2;
    ll b = 2 * k + 1;

    if (a > n && b > n) {
        return false;
    }
    if (!check(a, n) || !check(b, n)) {
        return true;
    }
    return false;
}

int main() {

    ll n;
    cin >> n;

    if (n == 1) {
        cout << "Aoki" << endl;
        return 0;
    }
    ll par = 1;
    ll line = 1;
    while (true) {
        par *= 4;
        line += par;
        if (line >= n) {
            cout << "Takahashi" << endl;
            return 0;
        }
        line += par;
        if (line >= n) {
            cout << "Aoki" << endl;
            return 0;
        }
    }

}
