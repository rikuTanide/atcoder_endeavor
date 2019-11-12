#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
const double INF = 1e10;
//const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

struct D {
    vector<double> l, r;

    D() : l(3, INF), r(3, -INF) {}

    void add(double x, int v) {
        ++v;
        mins(l[v], x);
        maxs(r[v], x);
    }

    double get(double t) {
        double nl = INF, nr = -INF;
        rep(i, 3) {
            mins(nl, l[i] + i * t);
            maxs(nr, r[i] + i * t);
        }
        return nr - nl;
    }

    vector<double> events() {
        vector<double> ts;
        rep(i, 3)
            rep(j, i) {
                {
                    double t = (l[j] - l[i]) / (i - j);
                    if (t > 0) {
                        ts.push_back(t);
                    }
                }
                {
                    double t = (r[j] - r[i]) / (i - j);
                    if (t > 0) {
                        ts.push_back(t);
                    }
                }
            }
        return ts;
    }

};

int main() {
    int n;
    cin >> n;

    D xd, yd;

    rep(i, n) {
        int x, y;
        char d;
        cin >> x >> y >> d;
        if (d == 'L') xd.add(x, -1), yd.add(y, 0);
        if (d == 'R') xd.add(x, 1), yd.add(y, 0);
        if (d == 'U') xd.add(x, 0), yd.add(y, 1);
        if (d == 'D') xd.add(x, 0), yd.add(y, -1);
    }

    vector<double> ts;
    ts.push_back(0);
    ts.push_back(INF);

    {
        auto nts = xd.events();
        ts.insert(ts.end(), nts.begin(), nts.end());
    }
    {
        auto nts = yd.events();
        ts.insert(ts.end(), nts.begin(), nts.end());
    }
    sort(ts.begin(), ts.end());
    double ans = 1e18;
    for (double t: ts) {
        double now = xd.get(t) * yd.get(t);
        mins (ans, now);
    }

    printf("%.10f\n", ans);
}
