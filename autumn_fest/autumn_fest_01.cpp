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

template<class T>
std::istream &operator>>(std::istream &in, set<T> &o) {
    T a;
    in >> a;
    o.insert(a);
    return in;
}

template<class T>
std::istream &operator>>(std::istream &in, queue<T> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> problem_count(n);
    rep(i, n) cin >> problem_count[i];

    vector<vector<ll>> points(n);
    rep(i, n) {
        int pc = problem_count[i];
        points[i].resize(pc);
        rep(j, pc) cin >> points[i][j];
        reverse(points[i].begin(), points[i].end());
    }
    vector<vector<ll>> times(n);
    rep(i, n) {
        int pc = problem_count[i];
        times[i].resize(pc);
        rep(j, pc) cin >> times[i][j];
        reverse(times[i].begin(), times[i].end());
    }

    vector<ll> scores(n, 0);

    while (true) {
        int target = [&]() -> int {
            ll mi = INF;
            rep(i, n) {
                if (points[i].empty()) continue;
                cmin(mi, points[i].back());
            }

            if (mi == INF) return -1;
            rep(i, n) {
                if (points[i].empty()) continue;
                if (mi == points[i].back()) {
                    return i;
                }
            }
            throw_with_nested("");
        }();
        if (target == -1) break;
        if (times[target].back() > t) break;
        t -= times[target].back();
        scores[target] = points[target].back();
        points[target].pop_back();
        times[target].pop_back();
    }
    ll ans = accumulate(scores.begin(), scores.end(), 0ll);

    cout << ans << endl;
}
