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

struct Road {
    int year;
    int from;
    int to;
};

struct Citizen {
    int year;
    int city;
    int i;
};

int main() {

    int n, m;
    cin >> n >> m;

    vector<Road> roads(m);
    rep(i, m) {
        int a, b, y;
        cin >> a >> b >> y;
        a--;
        b--;
        Road r{y, a, b};
        roads[i] = r;
    }

    sort(roads.begin(), roads.end(), [](Road &r, Road &s) {
        return r.year > s.year;
    });

    int q;
    cin >> q;

    vector<Citizen> citizens(q);

    rep(i, q) {
        int v, y;
        cin >> v >> y;
        v--;

        citizens[i].year = y;
        citizens[i].i = i;
        citizens[i].city = v;
    }

    sort(citizens.begin(), citizens.end(), [](Citizen &c, Citizen &d) {
        return c.year > d.year;
    });

    queue<Road> road_queue;
    for (Road &road : roads) {
        road_queue.push(road);
    }

    vector<int> ans(q);

    UnionFind uf(n);
    for (Citizen &citizen : citizens) {
        while (!road_queue.empty() && road_queue.front().year > citizen.year) {
            Road road = road_queue.front();
            uf.connect(road.from, road.to);
            road_queue.pop();
        }
        ans[citizen.i] = uf.size(citizen.city);
    }

    for (int a : ans) {
        cout << a << endl;
    }
}