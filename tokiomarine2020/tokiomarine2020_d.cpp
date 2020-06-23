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

map<ll, ll> create_table(vector<Item> &use_items) {
    map<ll, ll> m;
    int n = use_items.size();
    rep(i, 1 << n) {
        ll w = 0, v = 0;
        rep(j, n) {
            if (!((i >> j) & 1)) continue;
            w += use_items[j].w;
            v += use_items[j].v;
        }
        cmax(m[w], v);
    }

    map<ll, ll> ans;
    ans[0] = 0;
    for (auto &e: m) {
        if (e.first == 0) continue;
        auto it = ans.end();
        it--;
        if (it->second >= e.second) continue;
        ans[e.first] = e.second;
    }

    return ans;
}

void direct(ll u, ll l, vector<Item> &items) {
    auto index = create_candidates(u);
    vector<Item> use_items;
    for (int j : index) use_items.push_back(items[j]);

    int n = use_items.size();

    ll ans = 0;
    rep(i, 1 << n) {
        ll w = 0, v = 0;
        rep(j, n) {
            if (!((i >> j) & 1)) continue;
            w += use_items[j].w;
            v += use_items[j].v;
        }
        if (w > l) continue;
        cmax(ans, v);
    }
    cout << ans << endl;
}


void from_cache(ll u, ll l, map<ll, map<ll, ll>> &cache, int fs, int fe, vector<Item> &items) {
    auto index = create_candidates(u);

    int fm = [&] {
        for (int i : index) if (fs <= i && i <= fe) return i;
        __throw_runtime_error("nai");
    }();

    auto it = cache[fm].upper_bound(l);
    it--;
    ll ans = it->second;
    cout << ans << endl;

}

void use_cache(ll u, ll l, map<ll, map<ll, ll>> &cache, int fs, int fe, vector<Item> &items) {
    auto index = create_candidates(u);

    int fm = [&] {
        for (int i : index) if (fs <= i && i <= fe) return i;
        __throw_runtime_error("nai");
    }();

    vector<Item> overs;
    for (int i : index) if (i > fe) overs.push_back(items[i]);

    auto table1 = create_table(overs);
    auto table2 = cache[fm];

    ll ans = 0;
    for (auto e1 : table1) {
        if (e1.first > l) continue;
        ll sub = l - e1.first;
        auto it = table2.upper_bound(sub);
        it--;
        assert(it->first + e1.first <= l);
        ll now = e1.second + it->second;
        cmax(ans, now);
    }
    cout << ans << endl;

}

int main() {

    int f = 8;
    int fs = (1 << f) - 1;
    int fe = (1 << (f + 1)) - 2;

    map<ll, map<ll, ll>> cache;

    int n;
    cin >> n;
    vector<Item> items(n);
    rep(i, n) cin >> items[i];

    for (int i = fs; i <= fe && i < n; i++) {
        auto index = create_candidates(i);
        vector<Item> use_items;
        for (int j : index) use_items.push_back(items[j]);
        cache[i] = create_table(use_items);
    }

    int q;
    cin >> q;
    rep(_, q) {
        int u, l;
        cin >> u >> l;
        u--;

        if (u < fs) {
            direct(u, l, items);
        } else if (fs <= u && u <= fe) {
            from_cache(u, l, cache, fs, fe, items);
        } else {
            use_cache(u, l, cache, fs, fe, items);
        }
    }

    cout << endl;
}
