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

    int nm = n + m - 1;

    vector<P> v(nm);
    rep(i, nm) cin >> v[i].first >> v[i].second;
    rep(i, nm) v[i].first--, v[i].second--;

    vector<int> parent_count(n, 0); // 親が何人いますか？
    for (P p : v) parent_count[p.second]++;

    int root = distance(parent_count.begin(), find(parent_count.begin(), parent_count.end(), 0));

    vector<vector<int>> edges(n);
    for (P p : v) edges[p.first].push_back(p.second);

    queue<int> q;
    q.push(root);

    vector<int> parents(n, -1);

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        for (int next : edges[t]) {
            parent_count[next]--;
            if (parent_count[next] == 0) {
                parents[next] = t;
                q.push(next);
            }
        }
    }

    for (int p : parents) cout << p + 1 << endl;

}
