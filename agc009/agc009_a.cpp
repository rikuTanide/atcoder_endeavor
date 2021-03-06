#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef long long ll;
typedef long long ll;
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
const double PI = 3.14159265358979323846;

typedef pair<ll, ll> P;

void print_line(vector<vector<int>> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        for (int y = 0; y < ans[i].size(); y++) {
            cout << ans[i][y];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<ll> as(n), bs(n);
    rep(i, n) cin >> as[i] >> bs[i];

    ll sum = 0;

    for (int i = n - 1; i >= 0; i--) {
        ll asi = as[i] + sum;
        ll next = (asi + bs[i] - 1) / bs[i] * bs[i] - asi;
        sum += next;
    }
    cout << sum << endl;

}