#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

struct Edge {
    int to;
    ll cost;
    int terminal;
    ll cost_to_terminal;
};

struct State {
    int i;
    ll cost;
};

bool operator < (State a, State b) { return a.cost > b.cost; }


int main() {
    int n, m, src, dst;
    cin >> n >> m >> src >> dst;

    vector<vector<Edge>> g(n);

    rep(i, m) {
        int l;
        cin >> l;
        vector<int> s(l);
        rep(j, l) cin >> s[j];
        vector<ll> w(l - 1);
        rep(j, l - 1) cin >> w[j];

        ll total = accumulate(w.begin(), w.end(), 0ll);
        ll acc = 0;
        rep(j, l - 1) {
            g[s[j]].push_back(Edge{s[j + 1], w[j], s.back(), total - acc});
            acc += w[j];
            g[s[j + 1]].push_back(Edge{s[j], w[j], s.front(), acc});
        }
    }



    vector<ll> dist(n, -1);
    {
        priority_queue<State> q;
        q.push(State{dst, 0});
        while (!q.empty()) {
            State s = q.top();
            q.pop();
            if (dist[s.i] != -1) continue;
            dist[s.i] = s.cost;
            for (Edge e : g[s.i])
                if (dist[e.to] == -1) {
                    q.push(State{e.to, s.cost + e.cost});
                }
        }
    }

    ll low = -1, high = INF;
    while (low + 1 < high) {
        ll mid = (low + high) / 2;
        vector<ll> sdist(n, -1);
        priority_queue<State> q;
        q.push(State{src, 0});
        while (!q.empty()) {
            State s = q.top();
            q.pop();

            if (sdist[s.i] != -1) continue;
            sdist[s.i] = s.cost;

            if (s.i == dst) break;
            for (Edge e : g[s.i])
                if (sdist[e.to] - 1) {
                    if (s.cost + e.cost_to_terminal + dist[e.terminal] <= mid) {
                        q.push(State{e.to, s.cost + e.cost});
                    }
                }
        }
        if (sdist[dst] == -1) low = mid;
        else high = mid;
    }
    cout << high << endl;

}