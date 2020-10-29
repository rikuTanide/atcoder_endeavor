#include <bits/stdc++.h>
//#include "atcoder/all"
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
    cin >> n;
    vector<int> v(10);
    rep(i, 10) cin >> v[i];

    vector<vector<char>> u(n, vector<char>(7));
    rep(y, n) {
        rep(x, 7) cin >> u[y][x];
    }

    vector<int> t(7);
    rep(x, 7) {
        int comb = 0;
        int ma = 0;
        rep(y, n) {
            if (u[y][x] == 'X') comb++;
            else comb = 0;
            cmax(ma, comb);
        }
        t[x] = ma;
    }

    sort(t.rbegin(), t.rend());
    sort(v.rbegin(), v.rend());
    bool ok = [&]() -> bool {
        rep(i, 7) {
            if (t[i] > v[i]) return false;
        }
        return true;
    }();

    cout << (ok ? "YES" : "NO") << endl;
}