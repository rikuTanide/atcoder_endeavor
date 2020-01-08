#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
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


class Knapsack {
    vector<vector<ll>> knapsack;
    vector<ll> values;
    vector<ll> weights;
    ll n;
    ll w;
public:
    Knapsack(ll n, ll w, vector<ll> values, vector<ll> weights) : n(n), w(w), values(values), weights(weights) {
        knapsack.resize(n, vector<ll>(w + 1, 0));
    }

    ll get(ll i, ll j, ll def) {
        if (i == -1) return def;
        return knapsack[i][j];
    }

    ll getBefore(ll i, ll j) {
        return get(i - 1, j, 0);
    }

    ll getChange(ll i, ll j) {
        ll i_value = values[i];
        ll i_weight = weights[i];
        if (j < i_weight) return 0;
        return get(i - 1, j - i_weight, 0) + i_value;
    }

    ll calculate() {
        rep(i, n) for (ll j = 0; j <= w; j++) {
                ll before = getBefore(i, j);
                ll change = getChange(i, j);

                knapsack[i][j] = max(max(before, change), 0ll);
            }
        return knapsack[n - 1][w];
    }
};

int main() {
    int n, w;
    cin >> n >> w;

    vector<ll> values(n);
    vector<ll> weights(n);
    rep(i, n) {
        cin >> values[i];
        cin >> weights[i];
    }

    Knapsack knapsack(n, w, values, weights);
    ll ans = knapsack.calculate();

    cout << ans << endl;


}
