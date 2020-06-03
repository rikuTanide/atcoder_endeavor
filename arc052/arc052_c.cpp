#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
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

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
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

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<vector<ll>>> edges(2, vector<vector<ll>>(n));

    rep(_, m) {
        int c, a, b;
        cin >> c >> a >> b;

        edges[c][a].push_back(b);
        edges[c][b].push_back(a);
    }

    vector<ll> cost(n, INF);
    struct Element {
        ll node, cost, b_cnt;

        bool operator<(const Element &rhs) const {
            return b_cnt != rhs.b_cnt ? b_cnt < rhs.b_cnt : cost < rhs.cost;
        }

        bool operator>(const Element &rhs) const {
            return b_cnt != rhs.b_cnt ? b_cnt > rhs.b_cnt : cost > rhs.cost;
        }
    };

    priority_queue<Element, vector<Element>, greater<Element>> pq;

    cost[0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        Element t = pq.top();
        pq.pop();

        if (t.cost > cost[t.node]) {
            continue;
        }

        cost[t.node] = t.cost;

        for (ll next : edges[0][t.node]) {
            ll new_cost = t.cost + 1;
            if (new_cost < cost[next]) {
                pq.push({next, new_cost, t.b_cnt});
            }
        }

        for (ll next: edges[1][t.node]) {
            ll new_cost = t.cost + t.b_cnt + 1;
            if (new_cost < cost[next]) {
                pq.push({next, new_cost, t.b_cnt + 1});
            }
        }


    }


    for(ll l : cost) cout << l << endl;

}

