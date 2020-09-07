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

void solve(vector<int> &v, vector<vector<int>> &ans, int k) {

    if (v.size() < 2) return;

    vector<int> a, b;
    int n = v.size();
    rep(i, n) {
        if (i % 2 == 0) a.push_back(v[i]);
        else b.push_back(v[i]);
    }

    for (int x : a) {
        for (int y : b) {
            ans[x][y] = k;
            ans[y][x] = k;
        }
    }

    solve(a, ans, k + 1);
    solve(b, ans, k + 1);

}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> ans(n, vector<int>(n, -1));
    vector<int> v;
    rep(i, n) v.push_back(i);

    solve(v, ans, 0);

    rep(i, n) {
        rep(j, n) {
            if (i >= j) continue;
            cout << ans[i][j] + 1 << ' ';
        }
        cout << endl;
    }

}
