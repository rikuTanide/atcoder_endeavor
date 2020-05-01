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

int main() {
    int n;
    ll w;
    cin >> n >> w;

    vector<Item> items(n);
    rep(i, n) cin >> items[i];

    if (n <= 30) {
        ll ans = half(n, items, w);
        cout << ans << endl;
        ret();
    }

}
