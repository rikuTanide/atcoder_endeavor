#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

bool contain(set<ll> &s, int a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

void print(vector<ll> &v) {
    for (ll l : v) cout << l << ' ';
    cout << endl;
}

const int ma = 1e7;


struct Doubling {
    const int LOG;
    vector<vector<int> > table;

    Doubling(int sz, int64_t lim_t) : LOG(64 - __builtin_clzll(lim_t)) {
        table.assign(LOG, vector<int>(sz, -1));
    }

    void set_next(int k, int x) {
        table[0][k] = x;
    }

    void build() {
        for (int k = 0; k + 1 < LOG; k++) {
            for (int i = 0; i < table[k].size(); i++) {
                if (table[k][i] == -1) table[k + 1][i] = -1;
                else table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    int query(int k, int64_t t) {
        for (int i = LOG - 1; i >= 0; i--) {
            if ((t >> i) & 1) k = table[i][k];
        }
        return k;
    }
};

void solve(vector<int> &v) {
    int n = v.size();
    vector<ll> tmp;
    set<ll> used;
    rep(b, n) {
        ll l = v[b];
        if (find(tmp.begin(), tmp.end(), l) == tmp.end()) {
            tmp.push_back(l);
            used.insert(l);
        } else {
            while (contain(used, l)) {
                used.erase(used.find(tmp.back()));
                tmp.pop_back();
            }
        }
    }
    print(tmp);
}

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    vector<vector<int>> index(ma);
    rep(i, n) index[v[i]].push_back(i);
    rep(i, n) index[v[i]].push_back(i + n);

    Doubling doubling(n, 1e14);

    {
        int now = 0;
        int start = 0;
        do {
            int now_i = v[now];
            auto it = upper_bound(index[now_i].begin(), index[now_i].end(), now);
            int next = (*it) + 1;
            if (next >= n) {
//                printf("%d %d\n", start, next % n);
                doubling.set_next(start, next % n);
                start = next % n;
            }
            now = next % n;
        } while (now != 0);
    }

    doubling.build();

    int start = doubling.query(0, k - 1);
//    cout << start << endl;
    vector<int> tmp;
    for (int i = start; i < n; i++) tmp.push_back(v[i]);
    solve(tmp);

}
