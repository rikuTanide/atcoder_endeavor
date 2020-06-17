#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

#define REP(i, n) for(int i=0;i<(int)n;++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef int Weight;

struct Edge {
    int src, dst;
    Weight weight;
    int id;

    Edge(int src, int dst, Weight weight, int id) :
            src(src), dst(dst), weight(weight), id(id) {}
};

bool operator<(const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
           e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

bool dfs(vector<vector<Edge>> &edges, int start, int goal, int prev, vector<bool> &used) {

    if (goal == start) return true;

    for (Edge e : edges[start]) {
        int next = e.dst;
        int id = e.id;
        if (next == prev) continue;
        if (used[id]) continue;
        bool ok = dfs(edges, next, goal, start, used);
        if (ok) {
            used[id] = true;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;


    Graph edges(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        edges[a].push_back(Edge(a, b, 1, i));
        edges[b].push_back(Edge(b, a, 1, i));
    }

    rep(i, n) {
        if (edges[i].size() % 2 == 1) {
            cout << "No" << endl;
            ret();
        }
    }

    rep(i, n) {
        if (edges[i].size() >= 6) {
            cout << "Yes" << endl;
            ret();
        }
    }

    {
        int count = 0;
        rep(i, n) {
            if (edges[i].size() >= 4) {
                count++;
            }
        }
        if (count >= 3) {
            cout << "Yes" << endl;
            ret();
        }
    }

    {
        vector<int> v4;
        rep(i, n) {
            if (edges[i].size() >= 4) {
                v4.push_back(i);
            }
        }

        if (v4.size() == 2) {
            vector<bool> used(m, false);
            bool ok1 = dfs(edges, v4[0], v4[1], -1, used);
            bool ok2 = dfs(edges, v4[0], v4[1], -1, used);
            bool ok3 = dfs(edges, v4[0], v4[1], -1, used);

            if (ok1 && ok2 && !(ok3)) {
                cout << "Yes" << endl;
                ret();
            }

        }

    }


    cout << "No" << endl;

}