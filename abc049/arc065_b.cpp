#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;


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
    int n, k, l;
    cin >> n >> k >> l;

    UnionFind trains(n);
    UnionFind roads(n);

    rep(i, k) {
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        roads.connect(p, q);
    }

    rep(i, l) {
        int r, s;
        cin >> r >> s;
        r--;
        s--;
        trains.connect(r, s);
    }

    map<int, set<int>> road_groups;
    map<int, set<int>> train_groups;

    for (int i = 0; i < n; i++) {
        int root = roads.root(i);
        road_groups[root].insert(i);
    }
    for (int i = 0; i < n; i++) {
        int root = trains.root(i);
        train_groups[root].insert(i);
    }

    for (int i = 0; i < n; i++) {
        int r_root = roads.root(i);
        int t_root = trains.root(i);

        set<int> road_group = road_groups[r_root];
        set<int> train_group = train_groups[t_root];

        vector<int> match;
        set_intersection(road_group.begin(),
                         road_group.end(),
                         train_group.begin(),
                         train_group.end(),
                         inserter(match, match.end())
        );
        cout << match.size() << endl;
    }

}
