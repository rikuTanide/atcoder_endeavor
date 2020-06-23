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

vector<int> create_candidates(int v) {
    vector<int> u;
    u.push_back(v);
    while (v > 0) {
        v = (v + 1) / 2 - 1;
        u.push_back(v);
    }
    return u;
}

void from_cache(ll u, ll l, vector<vector<ll>> &cache) {

    ll ans = cache[u][l];
    printf("%lld\n", ans);


}

void use_cache(ll u, ll l, vector<vector<ll>> &cache, int fe, vector<Item> &items) {
    auto index = create_candidates(u);

    int fm = [&] {
        int ans = 0;
        for (int i : index) if (i <= fe) cmax(ans, i);
        return ans;
    }();

    vector<int> overs;
    for (int i : index) if (i > fe) overs.push_back(i);

    ll ans = 0;

    int n = overs.size();
    rep(i, 1 << n) {
        ll w = 0, v = 0;
        rep(j, n) {
            if (!((i >> j) & 1)) continue;
            w += items[overs[j]].w;
            v += items[overs[j]].v;
        }
        if (w > l) continue;
        ll sub = l - w;
        cmax(ans, v + cache[fm][sub]);
    }

    printf("%lld\n", ans);

}

vector<vector<ll>> knapsack(vector<Item> &items, int fe) {
    vector<vector<ll>> dp(fe + 1, vector<ll>(1e5 + 1, -1));
    dp[0][0] = 0;
    auto add = [&](int i, ll j, ll v) {
        if (i > fe) return;
        if (j > 1e5) return;
        if (dp[i][j] == -1) dp[i][j] = v;
        else
            cmax(dp[i][j], v);
    };

    auto p = [](int i) {
        if (i == 0) return -1;
        return (i + 1) / 2 - 1;
    };

    auto get = [&](int i, ll j) -> ll {
        if (i == -1) {
            if (j == 0) return 0;
            return -1;
        }
        return dp[i][j];
    };

    rep(i, fe + 1) {
        Item item = items[i];
        rep(j, 1e5 + 1) {

            ll from = get(p(i), j);
            if (from == -1) continue;
            add(i, ll(j) + item.w, from + item.v);
            add(i, ll(j), from);
        }
    }

    rep(i, fe + 1) {
        rep(j, 1e5 + 1) {
            if (j == 0) continue;
            cmax(dp[i][j], dp[i][j - 1]);
        }
    }

    return dp;
}

int main() {

//    ifstream cin("C:\\Users\\riku\\Downloads\\in15.txt");
    int n;
    cin >> n;

    vector<Item> items(n);
    rep(i, n) {
        cin >> items[i].v >> items[i].w;
    }


//    int f = 1;
    int f = 8;
    int fe = (1 << (f + 1)) - 2;

//    cout << fe << endl;

//    vector<vector<P>> cache(fe + 1);
//
//    for (int i = 0; i <= fe && i < n; i++) {
//        auto index = create_candidates(i);
//        cache[i] = create_table(index, items);
//    }
//

    vector<vector<ll>> cache = knapsack(items, min(fe, n - 1));


    int q;
    cin >> q;
    rep(_, q) {
        int u, l;
        cin >> u >> l;
        u--;

        if (u <= fe) {
            from_cache(u, l, cache);
        } else {
            use_cache(u, l, cache, fe, items);
        }
    }

    cout << endl;
}
