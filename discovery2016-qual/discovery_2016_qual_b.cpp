#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

typedef pair<ll, ll> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Item {
    ll value, weight;
};

std::istream &operator>>(std::istream &in, Item &o) {
    cin >> o.value >> o.weight;
    return in;
}


ll half(int n, vector<Item> &items, ll w) {
    vector<Item> v1, v2;
    rep(i, n)(i % 2 == 0 ? v1 : v2).push_back(items[i]);


    struct Tmp {
        vector<ll> weights, values;
    };
    auto f = [&](vector<Item> &items) {
        int n = items.size();
        map<ll, ll> knapsack;
        rep(i, 1 << n) {
            ll value = 0;
            ll weight = 0;
            rep(j, n) {
                if ((i >> j) & 1) {
                    value += items[j].value;
                    weight += items[j].weight;
                }
            }
            if (weight <= w) knapsack[weight] = value;
        }

        vector<ll> weights, values;

        for (auto &e : knapsack) {
            if (e.first == 0) {
                weights.push_back(0);
                values.push_back(0);
            } else {
                if (e.second <= values.back()) continue;
                weights.push_back(e.first);
                values.push_back(e.second);
            }
        }
        return Tmp{weights, values};
    };

    Tmp t1 = f(v1), t2 = f(v2);

    ll ans = 0;

    rep(i, t1.weights.size()) {
        ll weight = t1.weights[i];
        ll value = t1.values[i];

        auto it = upper_bound(t2.weights.begin(), t2.weights.end(), w - weight);
        it--;
        int index = distance(t2.weights.begin(), it);
        ll value2 = t2.values[index];

        ll now = value + value2;
        cmax(ans, now);
    }
    return ans;

}

ll weight_dp(int n, vector<Item> &items, int w) {
    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, -1));
    dp[0][0] = 0;

    auto set = [&](int i, int weight, ll value) {
        if (weight > w) return;
        cmax(dp[i][weight], value);
    };

    rep(i, n) {
        Item item = items[i];
        rep(j, w + 1) {
            if (dp[i][j] == -1) continue;
            ll next_weight = j + item.weight;
            ll next_value = dp[i][j] + item.value;
            set(i + 1, next_weight, next_value);
            set(i + 1, j, dp[i][j]);
        }
    }
    return *max_element(dp[n].begin(), dp[n].end());
}

ll value_dp(int n, vector<Item> &items, int v, ll w) {
    vector<vector<ll>> dp(n + 1, vector<ll>(v + 1, INF));
    dp[0][0] = 0;

    auto set = [&](int i, int value, ll weight) {
        cmin(dp[i][value], weight);
    };

    rep(i, n) {
        Item item = items[i];
        rep(j, v + 1) {
            if (dp[i][j] == INF) continue;
            ll next_value = j + item.value;
            ll next_weight = dp[i][j] + item.weight;

            set(i + 1, next_value, next_weight);
            set(i + 1, j, dp[i][j]);
        }
    }

    int value = 0;
    rep(i, v + 1) {
        if (dp[n][i] > w) continue;
        value = i;
    }
    return value;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> enjoys;

    {
        vector<int> enjoy_tmp(n);
        rep(i, n) cin >> enjoy_tmp[i], enjoy_tmp[i]--;
        int ma = *max_element(enjoy_tmp.begin(), enjoy_tmp.end());
        enjoys.resize(ma + 1);
        rep(i, n) {
            enjoys[enjoy_tmp[i]].push_back(i);
        }

    }

    int now = 0;
    int cycle = 0;
    rep(i, enjoys.size()) {
        if (enjoys[i].empty()) continue;
        if (enjoys[i].front() >= now) {
            now = enjoys[i].back();
        } else {
            auto it = lower_bound(enjoys[i].begin(), enjoys[i].end(), now);
            it--;
            now = *it;
            cycle++;
        }
    }
    if (now != 0) cycle++;
    cout << cycle << endl;

}
