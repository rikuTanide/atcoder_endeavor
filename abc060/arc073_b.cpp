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

class Knapsack {
    vector<map<ll, ll>> knapsack;
    vector<ll> values;
    vector<ll> weights;
    set<ll> weight_candidates;
    ll n;
public:
    Knapsack(ll n, vector<ll> values, vector<ll> weights, set<ll> weight_candidates)
            : n(n), values(values), weights(weights), weight_candidates(weight_candidates) {
        knapsack.resize(n, map<ll, ll>());
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
        rep(i, n) for (ll j : weight_candidates) {
                ll before = getBefore(i, j);
                ll change = getChange(i, j);

                knapsack[i][j] = max(max(before, change), 0ll);
            }
        ll ans = 0;
        for (auto e : knapsack[n - 1]) {
            cmax(ans, e.second);
        }
        return ans;
    }

};

int main() {

    ll n, w;
    cin >> n >> w;

    vector<ll> weights(n);
    vector<ll> values(n);
    rep(i, n) {
        ll wi, vi;
        cin >> wi >> vi;
        weights[i] = wi;
        values[i] = vi;
    }

    set<ll> weight_candidates;
    for (ll s = weights[0], e = s + 3, i = 0; i <= 100; i++, s = s + weights.front(), e += weights.front() + 3) {
        for (ll k = s; k <= e; k++) {
            if (k > w) continue;
            weight_candidates.insert(k);
        }
    }


    Knapsack k(n, values, weights, weight_candidates);
    cout << k.calculate() << endl;


}

