#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;


int main() {
    int n;
    cin >> n;

    int before_t = 0, before_x = 0, before_y = 0;

    rep(i, n) {
        int t, x, y;
        cin >> t >> x >> y;

        int distance = abs(x - before_x) + abs(y - before_y);
        int time = abs(t - before_t);
        if (distance > time) {
            cout << "No" << endl;
            return 0;
        }
        if ((time - distance) % 2 == 1) {
            cout << "No" << endl;
            return 0;
        }
        before_t = t;
        before_x = x;
        before_y = y;


    }


    cout << "Yes" << endl;
}