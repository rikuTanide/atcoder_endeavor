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

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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
    int from, to, year;
};

struct People {
    int index, town, year;
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

int main() {
    int n, m;
    cin >> n >> m;

    vector<Road> roads(m);
    rep(i, m) cin >> roads[i].from >> roads[i].to >> roads[i].year;
    rep(i, m) roads[i].from--;
    rep(i, m) roads[i].to--;

    int q;
    cin >> q;
    vector<People> people(q);
    rep(i, q) people[i].index = i;
    rep(i, q) cin >> people[i].town >> people[i].year;
    rep(i, q) people[i].town--;

    sort(roads.rbegin(), roads.rend(), [&](Road r, Road s) { return r.year < s.year; });
    sort(people.rbegin(), people.rend(), [&](People p, People q) { return p.year < q.year; });

    queue<People> p;
    for (People pe : people) p.push(pe);
    queue<Road> r;
    for (Road road : roads) r.push(road);

    UnionFind uf(n);
    vector<int> ans(q);
    while (!p.empty()) {
        People pe = p.front();
        p.pop();

        while (!r.empty() && r.front().year > pe.year) {
            Road road = r.front();
            r.pop();
            uf.connect(road.from, road.to);
        }
        ans[pe.index] = uf.size(pe.town);
    }
    for (int i : ans) cout << i << endl;
}
