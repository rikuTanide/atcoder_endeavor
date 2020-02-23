#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
const ll INF = 1e15;
//const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;
#define ret() return 0;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

class Conv {
    ll cursor = 0;
    map<ll, ll> to_short; // <original, small >
    map<ll, ll> to_long; // <small, original>


public:
    void set(ll original) {
        if (to_short.find(original) != to_short.end()) {
            return;
        }
        to_long[cursor] = original;
        to_short[original] = cursor;
        cursor++;
    }

    ll revert(ll after) {
        assert(to_long.find(after) != to_long.end());
        return to_long[after];
    }

    ll convert(ll original) {
        assert(to_short.find(original) != to_short.end());
        return to_short[original];
    }

    ll next() {
        return cursor;
    }

};


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

ll calc(ll start, ll goal, Conv &conv, ll d, vector<P> &moving_area) {
    if (start == goal) {
        return 0;
    }

    UnionFind uf(conv.next());

    for (int i = 0; i < d; i++) {
        bool b = [&] {
            for (ll m = moving_area[i].first; m <= moving_area[i].second; m++) {
                if (uf.is_union(start, m)) return true;
            }
            return false;
        }();

        if (b) {
            for (ll m = moving_area[i].first; m <= moving_area[i].second; m++) {
                uf.connect(start, m);
            }
        }
        if (uf.is_union(start, goal)) {
            return i + 1;
        }
    }
    __throw_runtime_error("nai");
}

int main() {
    ll n, d, k;
    cin >> n >> d >> k;

    vector<P> moving_area(d);
    rep(i, d) cin >> moving_area[i].first >> moving_area[i].second;

    vector<P> ethnic_move(k);
    rep(i, k) cin >> ethnic_move[i].first >> ethnic_move[i].second;

    Conv conv;
    {
        set<ll> use_points;
        for (P p : moving_area) {
            use_points.insert(p.first);
            use_points.insert(p.second);
        }
        for (P p : ethnic_move) {
            use_points.insert(p.first);
            use_points.insert(p.second);
        }
        for (ll l : use_points) {
            conv.set(l);
        }
    }

    rep(i, d) {
        moving_area[i].first = conv.convert(moving_area[i].first);
        moving_area[i].second = conv.convert(moving_area[i].second);
    }
    rep(i, k) {
        ethnic_move[i].first = conv.convert(ethnic_move[i].first);
        ethnic_move[i].second = conv.convert(ethnic_move[i].second);
    }

    for (P p : ethnic_move) {
        ll start = p.first, goal = p.second;
        ll i = calc(start, goal, conv, d, moving_area);

        cout << i << endl;
    }

}