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

    vector<P> v(n);
    for (P &p:v)cin >> p.first >> p.second;

    vector<vector<bool>> board(5005, vector<bool>(5005, false));
    for (P p : v) board[p.first][p.second] = true;

    auto has = [&](P p) -> bool {
        return board[p.first][p.second];
    };

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            P a = v[i];
            P b = v[j];

            ll up = b.first - a.first;
            ll right = b.second - a.second;

            {
                P c = P(b.first + right, b.second - up);
                P d = P(c.first - up, c.second - right);

                if (has(c) && has(d)) cmax(ans, up * up + right * right);
            }

            {
                P c = P(a.first - right, a.second + up);
                P d = P(c.first + up, c.second + right);

                if (has(c) && has(d)) cmax(ans, up * up + right * right);
            }

        }
    }

    cout << ans << endl;
}
