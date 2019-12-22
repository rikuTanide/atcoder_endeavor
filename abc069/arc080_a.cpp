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

    ll b4 = 0;
    ll b2 = 0;
    ll k = 0;
    rep(i, n) {
        ll a;
        cin >> a;
        if (a % 4 == 0) {
            b4++;
        } else if (a % 2 == 0) {
            b2++;
        } else {
            k++;
        }
    }

    ll b4_r = b4 * 2;

    if (b4_r < k) {
        cout << "No" << endl;
        return 0;
    }

    b4_r -= k;

    if (b2 == 1 && b4_r == 0) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;


}