#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

vector<int> bfs(int n, vector<vector<int>> &g, int start) {

    vector<int> ans(n, INT_MAX);
    ans[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int from = q.front();
        q.pop();

        int next_cost = ans[from] + 1;
        for (int to : g[from]) {
            if (ans[to] > next_cost) {
                ans[to] = next_cost;
                q.push(to);
            }
        }

    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<P> v(n - 1);
    for (P &p : v) cin >> p.first >> p.second, p.first--, p.second--;

    vector<vector<int>> g(n);
    for (P p : v) g[p.first].push_back(p.second);
    for (P p : v) g[p.second].push_back(p.first);

    vector<int> v1 = bfs(n, g, 0);

    int ma = distance(v1.begin(), max_element(v1.begin(), v1.end()));
    vector<int> v2 = bfs(n, g, ma);

    int r = *max_element(v2.begin(), v2.end());
    bool ans = r % 3 == 1;
    cout << (ans ? "Second" : "First") << endl;

}
