#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
//const int INF = INT_MAX  ;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;

vector<P> bridges;
vector<ll> ans;


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

int main() {
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        bridges.emplace_back(a, b);
    }
    // 1番目から順に崩落するということは、
    // m番目から順に建築されるのと同義
    reverse(bridges.begin(), bridges.end());

    // 最初にすべての島は独立している
    for (int i = 0; i < n; i++) {
        set<int> group;
        group.insert(i);
    }
    ans.push_back((ll)n * ((ll)n - 1) / 2);

    UnionFind uf(n);

    for (int i = 0; i < m; i++) {
        auto bridge = bridges[i];

        int first = uf.root(bridge.first);
        int firstSize = uf.size(first);
        int second = uf.root(bridge.second);
        int secondSize = uf.size(second);

        bool b = uf.connect(first, second);
        if (!b) {
            ll end = *(ans.end() - 1);
            ans.push_back(end);
            continue;
        }

        ll end = *(ans.end() - 1);
        ll diff  = firstSize * secondSize;
        ans.push_back(end - diff);
    }
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    for (auto a : ans) {
        cout << a << endl;
    }

}

