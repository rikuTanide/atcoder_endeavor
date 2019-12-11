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
    ll n;
    cin >> n;

    vector<ll> plans(n + 2, 0);
    rep(i, n) {
        ll a;
        cin >> a;

        plans[i + 1] = a;
    }


    vector<ll> normal_costs(n + 1, 0);
    rep(i, n + 1) {
        ll from = plans[i];
        ll to = plans[i + 1];
        ll cost = abs(from - to);
        normal_costs[i] = cost;
    }
    ll sum = accumulate(normal_costs.begin(), normal_costs.end(), 0ll);

    vector<ll> via_costs(n, 0);
    rep(i, n) {
        via_costs[i] = normal_costs[i] + normal_costs[i + 1];
    }

    vector<ll> direct_costs(n, 0);
    rep(i, n) {
        ll from = plans[i];
        ll to = plans[i + 2];
        ll cost = abs(from - to);
        direct_costs[i] = cost;
    }

    rep(i, n) {
        ll before = via_costs[i];
        ll after  = direct_costs[i];
        ll diff = before - after;

        cout << sum - diff << endl;
    }

}