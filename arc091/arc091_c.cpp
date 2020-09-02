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

int main() {
    int n;
    ll a, b;
    cin >> n >> a >> b;

    ll ma = a * b;
    ll mi = a + b - 1;

    bool mab = ma >= n;
    bool mib = mi <= n;

    if (!(mab && mib)) {
        cout << -1 << endl;
        ret();
    }

    vector<vector<int>> ans(a);

    queue<int> q;
    rep(i, n) q.push(i + 1);

    rep(i, a) {
        for (int j = 0; j < b && q.size() > (a - i - 1); j++) {
            ans[i].push_back(q.front());
            q.pop();
        }
    }

    rep(i, a) reverse(ans[i].begin(), ans[i].end());

    rep(i, a) {
        rep(j, ans[i].size()) cout << ans[i][j] << ' ';
    }
    cout << endl;

}
