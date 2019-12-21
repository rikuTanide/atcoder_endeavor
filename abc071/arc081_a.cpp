#include <bits/stdc++.h>
#include <cmath>


#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

int main() {
    ll n;
    cin >> n;

    map<ll, ll> counter;
    rep(i, n) {
        ll a;
        cin >> a;
        counter[a]++;
    }
    vector<ll> ls(2);
    rep(i, 2) {
        ll mx = 0;
        for (pair<ll, ll> e : counter) {
            if (e.second < 2) {
                continue;
            }
            cmax(mx, e.first);
        }
        if (mx == 0) {
            cout << 0 << endl;
            return 0;
        }
        ls[i] = mx;
        counter[mx] -= 2;
    }

    cout << ls[0] * ls[1] << endl;
}