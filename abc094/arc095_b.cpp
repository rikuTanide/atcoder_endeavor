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
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

int main() {
//    ifstream myfile("C:\\Users\\riku\\Downloads\\even0.txt");
//
//    ofstream outfile("log.txt");

    ll n;
    cin >> n;
//    myfile >> n;
    vector<ll> as(n);
    rep(i, n) {
//        myfile >> as[i];
        cin >> as[i];
    }

    sort(as.begin(), as.end());
    ll mx = as[n - 1];


    ll diff_min = INF;
    ll comb_min;
    for (ll i = 0; i < n - 1; i++) {
        ll u = as[i];
        ll v = u;
        if ((u * 2) >= mx) {
            v = mx - u;
        }

        ll d = abs((v * 2) - mx);


        if (diff_min > d) {
            comb_min = u;
            diff_min = d;
        }
    }
    cout << mx << ' ' <<  comb_min << endl;

}