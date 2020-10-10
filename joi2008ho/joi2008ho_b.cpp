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
    string s, t;
    cin >> s >> t;
    int ss = s.size();
    int ts = t.size();
    vector<int> prev(ts, 0);


    auto get = [&](int j) -> int {
        if (j < 0) return 0;
        return prev[j];
    };

    int ans = 0;
    rep(i, ss) {

        vector<int> next(ts, 0);

        rep(j, ts) {
            if (s[i] == t[j]) {
                next[j] = get(j - 1) + 1;
            }
        }

        prev = next;
        int ma = *max_element(prev.begin(), prev.end());
        cmax(ans, ma);
    }
    cout << ans << endl;
}