#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1e9 + 7;


int main() {
    int n;
    cin >> n;
    vector<P> p(n);
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        p[i] = P(x, y);
    }

    vector<double> d(n, 0);
    rep(i, n) {
        auto a = p[i];
        rep(j, n) {
            if (i == n) continue;
            auto b = p[j];
            int l = a.first - b.first;
            int r = a.second - b.second;
            double distance = sqrt(l * l + r * r);
            d[i] += distance;
        }
        d[i] /= n;
    }
    double ans = accumulate(d.begin(), d.end(), 0.0);
    printf("%.10f\n", ans);


}

