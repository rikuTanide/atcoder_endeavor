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
    int n;
    cin >> n;
    vector<ll> original(n);

    rep(i, n)cin >> original[i];
    deque<ll> q;

    for (int i = 0; i < n; i++) {
        ll o = original[i];
        if (i % 2 == 0) {
            q.push_front(o);
        } else {
            q.push_back(o);
        }
    }

    vector<ll> ans(n);
    copy(q.begin(), q.end(), ans.begin());

    if (n % 2 == 0) reverse(ans.begin(), ans.end());

    for (ll a : ans) {
        cout << a << ' ';
    }
    cout << endl;

}