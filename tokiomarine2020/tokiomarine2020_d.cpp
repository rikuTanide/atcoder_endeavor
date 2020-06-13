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
    ll v, w;
};


std::istream &operator>>(std::istream &in, Item &o) {
    cin >> o.v >> o.w;
    return in;
}

// 全列挙
// 半全列挙
// map

vector<int> create_candidates(int v) {
    vector<int> u;
    u.push_back(v);
    while (v > 0) {
        v = (v + 1) / 2 - 1;
        u.push_back(v);
    }
    return u;
}


ll knapsack(int n, vector<Item> &items, ll w) {
    vector<map<ll, ll>> dp(n + 1);

    auto set = [&](int i, ll weight, ll value) {
        if (weight > w) return;
        if (dp[i].find(weight) == dp[i].end()) dp[i][weight] = value;
        else
            cmax(dp[i][weight], value);
    };
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        Item item = items[i];
        for (auto &e : dp[i]) {
            set(i + 1, e.first, e.second);
            set(i + 1, e.first + item.w, e.second + item.v);
        }
    }

    ll ans = 0;
    for (auto e:  dp.back()) {
        cmax(ans, e.second);
    }
    return ans;
}


int main() {
//
//    auto v = create_candidates(pow(2, 18) - 2);
//    for (int i : v) cout << i << ' ';

    int n;
    cin >> n;
    vector<Item> items(n);
    rep(i, n) cin >> items[i];


    int q;
    cin >> q;

    rep(_, q) {
        int v, l;
        cin >> v >> l;

        vector<int> candidates = create_candidates(v - 1);
        int qn = candidates.size();
        assert(qn <= 18);
        vector<Item> use_items(qn);
        rep(i, qn) use_items[i] = items[candidates[i]];
        ll ans = knapsack(qn, use_items, l);
        cout << ans << endl;
    }
}
