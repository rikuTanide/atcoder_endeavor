#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Item {
    ll value, weight;
};

map<ll, ll> calc_pair(vector<Item> &items) {
    vector<P> tmp;
    int n = items.size();
    rep(i, 1 << n) {
        ll value = 0, weight = 0;
        rep(j, n) {
            if ((i >> j) & 1) {
                value += items[j].value;
                weight += items[j].weight;
            }
            tmp.push_back({weight, value});
        }
    }

    sort(tmp.begin(), tmp.end());

    vector<P> tmp2;
    for (P p :tmp) {
        if (tmp2.empty()) {
            tmp2.push_back(p);
            continue;
        }

        if (tmp2.back().second >= p.second) {
            continue;
        }

        tmp2.push_back(p);

    }

    map<ll, ll> ans;
    for (P p: tmp2) ans[-p.first] = p.second;
    return ans;

}

void solve30(int n, vector<Item> &items, ll w) {
    vector<Item> a, b;
    rep(i, n)
        if (i % 2 == 0) a.push_back(items[i]);
        else b.push_back(items[i]);

    map<ll, ll> pa = calc_pair(a);
    map<ll, ll> pb = calc_pair(b);

    ll ans = 0;
    for (auto ea : pa) {
        ll a_value = ea.second;
        ll a_weight = ea.first * -1;

        if (a_weight > w) continue;

        auto it = pb.lower_bound(-(w - a_weight));
        if (it == pb.end()) continue;
        ll b_weight = -(*it).first;
        ll b_value = (*it).second;

        assert(a_weight >= 0);
        assert(b_weight >= 0);

        assert(a_weight + b_weight <= w);

        ll value = a_value + b_value;
        cmax(ans, value);
    }
    cout << ans << endl;

}

void knapsack_weight(vector<Item> &items, ll w) {
    int n = items.size();
    {
        ll weight_sum = accumulate(items.begin(), items.end(), 0ll, [&](ll l, Item item) {
            return l + item.weight;
        });

        ll value_sum = accumulate(items.begin(), items.end(), 0ll, [&](ll l, Item item) {
            return l + item.value;
        });

        if (weight_sum <= w) {
            cout << value_sum << endl;
            return;
        }
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, -1));
    dp[0][0] = 0;

    auto set = [&](int i, int weight, ll value) {
        if (weight > w) return;
        cmax(dp[i][weight], value);
    };

    auto get = [&](int i, int weight) {
        return dp[i][weight];
    };

    rep(i, n) {
        Item item = items[i];
        rep(now_weigth, w + 1) {
            ll now_value = get(i, now_weigth);
            if (now_value == -1) continue;
            set(i + 1, now_weigth, now_value);
            set(i + 1, now_weigth + item.weight, now_value + item.value);
        }
    }
    ll ans = 0;
    rep(i, w + 1) {
        cmax(ans, get(n, i));
    }
    cout << ans << endl;

}

int main() {
    int n;
    ll w;
    cin >> n >> w;

    vector<Item> items(n);
    for (Item &item: items) cin >> item.value >> item.weight;

    ll max_value = (*max_element(items.begin(), items.end(), [](Item i1, Item i2) {
        return i1.value < i2.value;
    })).value;

    ll max_weight = (*max_element(items.begin(), items.end(), [](Item i1, Item i2) {
        return i1.weight < i2.weight;
    })).weight;

    if (max_weight <= 1000) {
        knapsack_weight(items, w);
        ret();
    }


    if (n <= 30) {
        solve30(n, items, w);
        ret();
    }

    __throw_runtime_error("mada");

}
