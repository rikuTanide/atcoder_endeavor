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

void merge(ll n, ll w, vector<ll> &values, vector<ll> &weights) {
    ll a = n / 2;

    map<ll, ll> a_set;
    for (int i = 0; i < (1 << a); i++) {
        ll v_sum = 0;
        ll w_sum = 0;
        for (int j = 0; j < a; j++) {
            if ((i >> j) & 1) {
                v_sum += values[j];
                w_sum += weights[j];
            }
        }
        if (w_sum > w) continue;
        a_set[w_sum] = max(a_set[w_sum], v_sum);
    }

    ll b = n - a;

    map<ll, ll> b_set;
    for (int i = 0; i < (1 << b); i++) {
        ll v_sum = 0;
        ll w_sum = 0;
        for (int j = 0; j < b; j++) {
            if ((i >> j) & 1) {
                v_sum += values[a + j];
                w_sum += weights[a + j];
            }
        }
        if (w_sum > w) continue;
        b_set[w_sum] = max(b_set[w_sum], v_sum);
    }
    ll ans = 0;

    for (auto ae : a_set) {
        for (auto be : b_set) {
            if (ae.first + be.first > w) continue;
            ll now = ae.second + be.second;
            cmax(ans, now);
        }
    }

    cout << ans << endl;
}

void weightDp(ll n, ll w, vector<ll> &values, vector<ll> &weights) {
    ll nvm = accumulate(values.begin(), values.end(), 0ll);
//    {
//        vector<P> tmp(n);
//        rep(i, n) {
//            tmp[i].first = values[i];
//            tmp[i].second = weights[i];
//        }
//        sort(tmp.rbegin(), tmp.rend());
//        rep(i, n) {
//            values[i] = tmp[i].first;
//            weights[i] = tmp[i].second;
//        }
//    }


    vector<ll> dp(nvm + 1, INF);
    dp[0] = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = nvm; j >= 0; j--) {
            if (j > values[i]) {
                dp[j] = min(dp[j], dp[j - values[i]] + weights[i]);
            } else {
                dp[j] = min(dp[j], weights[i]);
            }
        }
    }

    ll ans = 0;
    rep(i,nvm) {
        if(dp[i]<= w) ans = i;
        else break;
    }

    cout << ans << endl;
}

int main() {
    int n, w;
    cin >> n >> w;

    vector<ll> values(n);
    vector<ll> weights(n);
    rep(i, n) {
        cin >> values[i];
        cin >> weights[i];
    }

    if (n <= 30) {
        merge(n, w, values, weights);
        return 0;
    }

    if (*max_element(values.begin(), values.end()) <= 1000) {
        weightDp(n, w, values, weights);
        return 0;
    }

    Knapsack knapsack(n, w, values, weights);
    ll ans = knapsack.calculate();

    cout << ans << endl;


}
