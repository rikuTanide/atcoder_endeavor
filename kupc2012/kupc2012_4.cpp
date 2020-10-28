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
    int n, m;
    cin >> n >> m;

    vector<int> ranges(n, 0);

    rep(_, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cmax(ranges[a], b);
    }

    rep(i, n - 1) {
        if (ranges[i] > ranges[i + 1]) ranges[i + 1] = ranges[i];
    }

    int now = 0;
    int ans = 0;
    while (now < n) {
        ans++;
        if (ranges[now] < now) {
            cout << "Impossible" << endl;
            ret();
        }
        now = ranges[now] + 1;
    }

    cout << ans << endl;


}
