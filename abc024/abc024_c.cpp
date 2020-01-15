#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct Open {
    int open;
    int close;
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

};

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

int main() {

    ll n, d, k;
    cin >> n >> d >> k;
    vector<P> ranges(d);
    rep(i, d) {
        cin >> ranges[i].first;
        cin >> ranges[i].second;

        ranges[i].first--;
        ranges[i].second--;
    }

    vector<P> targets(k);
    rep(i, k) {
        cin >> targets[i].first;
        cin >> targets[i].second;
        targets[i].first--;
        targets[i].second--;
    }

    Conv conv;
    {
        set<ll> points;
        rep(i, d) {
            points.insert(ranges[i].first);
            points.insert(ranges[i].second);
        }
        rep(i, k) {
            points.insert(targets[i].first);
            points.insert(targets[i].second);
        }
        for (ll p : points) {
            conv.set(p);
        }
    }

    vector<P> conv_ranges(d);
    rep(i, d) {
        conv_ranges[i].first = conv.convert(ranges[i].first);
        conv_ranges[i].second = conv.convert(ranges[i].second);
    }

    rep(i, k) {
        UnionFind uf(conv.next());
        P target = targets[i];
        int start = conv.convert(target.first);
        int goal = conv.convert(target.second);

        rep(j, d) {
            P cr = conv_ranges[j];

            bool b = [&] {
                for (ll l = cr.first; l <= cr.second; l++) {
                    if (uf.root(start) == uf.root(l)) {
                        return true;
                    }
                }
                return false;
            }();

            if (b) {
                for (ll l = cr.first; l < cr.second; l++) {
                    uf.connect(l, l + 1);
                }
            }
            if (uf.root(start) == uf.root(goal)) {
                cout << j + 1 << endl;
                break;
            }
        }
    }

}
