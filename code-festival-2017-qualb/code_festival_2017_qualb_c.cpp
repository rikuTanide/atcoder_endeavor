#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

bool is_t(int n, vector<vector<int>> &edges, vector<int> &oe, int from, int prev, int depth) {
    int noe = depth % 2;
    if (oe[from] == -1) {
        oe[from] = noe;
        for (int to : edges[from]) {
            if (to == prev) continue;
            bool b = is_t(n, edges, oe, to, from, depth + 1);
            if (!b) return false;
        }
        return true;
    } else {
        return oe[from] == noe;
    }
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> oe(n, -1);
    bool ok = is_t(n, edges, oe, 0, -1, 0);

    if (ok) {
        ll b = count(oe.begin(), oe.end(), 0);
        ll w = count(oe.begin(), oe.end(), 1);
        cout << b * w - m << endl;
    } else {
        cout << n * (n - 1) / 2 - m << endl;
    }

}


