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

vector<int> amida_simulator(vector<int> &horizontal, int width) {
    vector<int> currents(width);
    vector<int> current_indexes(width);
    rep(i, width) currents[i] = i;
    rep(i, width) current_indexes[i] = i;

    for (int h : horizontal) {
        int h1 = currents[h];
        int h2 = currents[h + 1];

        swap(current_indexes[h1], current_indexes[h2]);
        currents[h] = h2;
        currents[h + 1] = h1;

    }
    return current_indexes;
}

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

int main() {
    int n, m;
    ll d;
    cin >> n >> m >> d;

    vector<int> horizontal(m);
    rep(i, m) cin >> horizontal[i], horizontal[i]--;

    vector<int> nexts = amida_simulator(horizontal, n);

    Doubling doubling(m, 1e10);
    rep(i, m) doubling.set_next(i, nexts[i]);
    doubling.build();

    rep(i, n) cout << doubling.query(i, d) + 1 << endl;


}
