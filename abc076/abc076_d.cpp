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

int main() {
    int n;
    cin >> n;

    vector<int> speeds = [&] {
        vector<int> _times(n), _speeds(n);
        rep(i, n) cin >> _times[i];
        rep(i, n) cin >> _speeds[i];

        vector<int> speeds;
        rep(i, n) {
            rep(j, _times[i]) {
                speeds.push_back(_speeds[i]);
            }
        }

        vector<int> speeds2;
        rep(i, speeds.size()) {
            if (i == 0) {
                speeds2.push_back(0);
                speeds2.push_back(speeds[i]);
            } else {
                int p = speeds[i - 1];
                int c = speeds[i];
                speeds2.push_back(min(p, c));
                speeds2.push_back(c);
            }
        }
        speeds2.push_back(0);
        return speeds2;
    }();

    vector<double> dp(speeds.size());
    rep(i, speeds.size()) dp[i] = speeds[i];
    rep(i, speeds.size()) if (i != 0) cmin(dp[i], dp[i - 1] + 0.5);
    rep(i, speeds.size()) if (i != 0) {
            int j = speeds.size() - i - 1;
            cmin(dp[j], dp[j + 1] + 0.5);
        }

    double sum = 0;
    rep(i, speeds.size()) {
        if (i == 0) continue;
        double a = dp[i - 1], b = dp[i];
        double now = (a + b) / 2 * 0.5;
        sum += now;
    }
    printf("%.20f\n", sum);
}

