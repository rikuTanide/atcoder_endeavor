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

    Edge(int src, int dst, Weight weight) :
            src(src), dst(dst), weight(weight) {}
};

bool operator<(const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
           e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;
#define RESIDUE(s, t) (capacity[s][t]-flow[s][t])

Weight maximumFlow(const Graph &g, int s, int t) {
    int n = g.size();
    Matrix flow(n, Array(n)), capacity(n, Array(n));
    REP(u, n) FOR(e, g[u]) capacity[e->src][e->dst] += e->weight;

    Weight total = 0;
    while (1) {
        queue<int> Q;
        Q.push(s);
        vector<int> prev(n, -1);
        prev[s] = s;
        while (!Q.empty() && prev[t] < 0) {
            int u = Q.front();
            Q.pop();
            FOR(e, g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
                    prev[e->dst] = u;
                    Q.push(e->dst);
                }
        }
        if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
        Weight inc = INT_MAX / 10;
        for (int j = t; prev[j] != j; j = prev[j])
            inc = min(inc, RESIDUE(prev[j], j));
        for (int j = t; prev[j] != j; j = prev[j])
            flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
        total += inc;
    }
}


int main() {
    int n, m;
    cin >> n >> m;


    Graph edges(n);
    rep(_, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        edges[a].push_back(Edge(a, b, 1));
        edges[b].push_back(Edge(b, a, 1));
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
            int min_cut = maximumFlow(edges, v4[0], v4[1]);
            if (min_cut == 2) {
                cout << "Yes" << endl;
                ret();
            }
        }

    }


    cout << "No" << endl;

}