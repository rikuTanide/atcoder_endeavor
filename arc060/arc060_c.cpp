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


int solve(vector<ll> &hotels, ll l) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;

    if (!(a < b)) swap(a, b);

    vector<vector<ll>> dp(b - a + 1, vector<ll>(b - a + 1, -1));
    dp[0][0] = 0;

    auto set = [&](int i, int j, ll v) {
        if (v > l) return;
        if (dp[i][j] == -1) dp[i][j] = v;
        else {
            cmin(dp[i][j], v);
        }
    };

    rep(i, b - a) {
        ll dis = hotels[a + i + 1] - hotels[a + i];
        rep(j, b - a) {
            if (dp[i][j] == -1) continue;
            // 泊まる
            set(i + 1, j + 1, dis);
            // 今日行く
            set(i + 1, j, dp[i][j] + dis);
        }
    }

    rep(i, b - a + 1) {
        if (dp.back()[i] != -1) {
            return i;
        }
    }
    __throw_runtime_error("nai");
}


ll binsearch_max(int l, int r, function<bool(int)> f) {
    assert(l <= r);
    r++;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (f(m)) l = m;
        else r = m;
    }
    return l;
}

struct DoublingTable {
    vector<vector<int>> table;

    DoublingTable() = default;

    DoublingTable(vector<int> const &next, int size = -1) {
        int n = next.size();
        {
            auto it = minmax_element(next.begin(), next.end());
            assert(0 <= *(it.first) && *(it.second) <= n);
        }
        if (size == -1) {
            size = max<int>(1, ceil(log2(n)));
        }
        table.resize(size);
        table[0] = next;

        rep(k, size - 1) {
            table[k + 1].resize(n, n);
            rep(i, n) if (table[k][i] != n) {
                    table[k + 1][i] = table[k][table[k][i]];
                }
        }

    }

};

int main() {
    int n;
    cin >> n;

    vector<ll> hotels(n);
    rep(i, n) cin >> hotels[i];

    ll l, q;
    cin >> l >> q;


    vector<int> next(n);
    rep(i, n) {
        auto f = [&](int j) {
            return hotels[j] - hotels[i] <= l;
        };
        next[i] = binsearch_max(i, n - 1, f);
    }

    DoublingTable doubling(next);

    rep(_, q) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        int res = 0;
        if (a > b)swap(a, b);

        for (int k = doubling.table.size() - 1; k >= 0; k--) {
            if (doubling.table[k][a] < b) {
                a = doubling.table[k][a];
                res += (1 << k);
            }
        }

        while (a < b) {
            a = next[a];
            res += 1;
        }

        cout << res << endl;
    }


}