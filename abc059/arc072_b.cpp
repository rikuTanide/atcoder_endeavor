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

bool solve(int y, int x, bool turn) {
    if (y < 2 && x < 2) return !turn;

    for (int i = 1; 2 * i <= y; i++) {
        bool ok = solve(y - (2 * i), x + i, !turn);
        if (ok == turn) return turn;
    }

    for (int i = 1; 2 * i <= x; i++) {
        bool ok = solve(y + 1, x - (2 * i), !turn);
        if (ok == turn) return turn;
    }

    return !turn;
}

int main() {
    int a, b;
    cin >> a >> b;
    bool ok = solve(a, b, true);
    string ans = ok ? "Alice" : "Brown";
    cout << ans << endl;
    ret();
    rep(i, 10) {
        rep(j, 10) {
            printf("%d %d %s\n", i, j, solve(i, j, true) ? "Alice" : "Brown");
        }
    }
}
