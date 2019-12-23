#include <bits/stdc++.h>
#include <cmath>

#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

struct Distance {
    ll from, to, length;
};

class MinDistance {
    vector<P> points;

public:
    MinDistance(int n) {
        points.resize(n);
    }

    void set(int i, ll position) {
        points[i] = {position, i};
    }

    void order() {
        sort(points.begin(), points.end());
    }

    Distance getDistanceRight(int i) {
        ll length = points[i + 1].first - points[i].first;
        ll from = points[i].second;
        ll to = points[i + 1].second;
        return Distance{from, to, length};
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

};


int main() {

    int n;
    cin >> n;
    MinDistance xMin(n);
    MinDistance yMin(n);

    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        xMin.set(i, x);
        yMin.set(i, y);
    }
    xMin.order();
    yMin.order();

    vector<Distance> roads;

    for (int i = 0; i < n - 1; i++) {
        roads.push_back(xMin.getDistanceRight(i));
        roads.push_back(yMin.getDistanceRight(i));
    }

    sort(roads.begin(), roads.end(), [](Distance &d, Distance e) {
        return d.length < e.length;
    });

    UnionFind uf(n);
    ll ans = 0;
    for (Distance &r : roads) {
        if (uf.root(r.from) == uf.root(r.to)) continue;
        uf.connect(r.from, r.to);
        ans += r.length;
    }

    cout << ans << endl;
}