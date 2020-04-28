#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Road {
    int from, to;
    ll cost;
};

std::istream &operator>>(std::istream &in, Road &o) {
    cin >> o.from >> o.to >> o.cost;
    o.from--;
    o.to--;
    return in;
}

class UnionFind {
public:
    // 親の番号を格納する。親だった場合-size
    vector<int> parents;

    UnionFind(int n) {
        parents = vector<int>(n, -1);
    }

    // aがどのグループに属しているか
    int root(int a) {
        if (parents[a] < 0) {
            return a;
        }
        return parents[a] = root(parents[a]);
    }

    int size(int a) {
        return -parents[root(a)];
    }

    // aとbをくっつける
    bool connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra == rb) {
            return false;
        }
        // 大きいほうにA
        if (size(ra) < size(rb)) {
            swap(ra, rb);
        }
        parents[ra] += parents[rb];
        parents[rb] = ra;
        return true;
    }

    bool is_union(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        return ra == rb;
    }
};

bool check(vector<int> &trade_offices, UnionFind &uf, int n) {
    rep(i, n) {
        bool b = [&] {
            for (int t : trade_offices) {
                if (uf.is_union(t, i)) return true;
            }
            return false;
        }();
        if (!b) return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    assert(n <= 8);
    assert(m <= 10);

    vector<ll> trade_office_costs(n);
    rep(i, n) cin >> trade_office_costs[i];

    vector<Road> roads(m);
    rep(i, m) cin >> roads[i];

    ll ans = INF;

    rep(i, 1 << n) {
        vector<int> trade_offices;
        ll trade_office_cost = 0;
        rep(j, n) if ((i >> j) & 1) {
                trade_offices.push_back(j);
                trade_office_cost += trade_office_costs[j];
            }
        rep(k, 1 << m) {
            UnionFind uf(n);
            ll cost = trade_office_cost;
            rep(l, m) if ((k >> l) & 1) {
                    Road road = roads[l];
                    cost += road.cost;
                    uf.connect(road.from, road.to);
                }

            bool b = check(trade_offices, uf, n);
            if (!b) continue;
            if (cost == 347) {
                cout << endl;
            }
            cmin(ans, cost);

        }
    }
    cout << ans << endl;
}
