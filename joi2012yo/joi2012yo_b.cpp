#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

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
    cin >> n;

    vector<int> win_point(n, 0);

    rep(_, n * (n - 1) / 2) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        a--;
        b--;

        if (c > d) {
            win_point[a] += 3;
        } else if (c < d) {
            win_point[b] += 3;
        } else {
            win_point[a]++;
            win_point[b]++;
        }
    }

    map<int, vector<int>> m;
    rep(i, n) m[-win_point[i]].push_back(i);

    vector<int> ans(n);

    int now = 1;
    for (auto &e: m) {
        for (int i : e.second) ans[i] = now;
        now += e.second.size();
    }

    rep(i, n) cout << ans[i] << endl;

}
