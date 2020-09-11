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

bool is_enable(int n, vector<int> e, vector<int> o) {

    if (!(e.size() == (n + 1) / 2)) return false;
    if (!(o.size() == n / 2)) return false;

    sort(e.begin(), e.end());
    sort(o.begin(), o.end());
    vector<int> tmp;
    rep(i, e.size()) {
        tmp.push_back(e[i]);
        if (o.size() > i) tmp.push_back(o[i]);
    }

    rep(i, tmp.size() - 1) {
        if (!(tmp[i] <= tmp[i + 1])) return false;
    }
    return true;

}

int calc(vector<P> pe, vector<P> po) {
    sort(pe.begin(), pe.end());
    sort(po.begin(), po.end());

    vector<P> tmp;
    rep(i, pe.size()) {
        tmp.push_back(pe[i]);
        if (po.size() > i) tmp.push_back(po[i]);
    }

    int ans = 0;
    rep(i, tmp.size())ans += max<int>(tmp[i].second - i, 0);
    return ans;
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    int ans = INT_MAX;
    rep(i, 1 << n) {

        vector<int> e, o;
        vector<P> pe, po;
        rep(j, n) {

            if (j % 2 == 0) {
                if ((i >> j) & 1) {
                    o.push_back(b[j]);
                    po.push_back({b[j], j});
                } else {
                    e.push_back(a[j]);
                    pe.push_back({a[j], j});
                }
            } else {
                if ((i >> j) & 1) {
                    e.push_back(b[j]);
                    pe.push_back({b[j], j});

                } else {
                    o.push_back(a[j]);
                    po.push_back({a[j], j});
                }
            }
        }

        bool ok = is_enable(n, e, o);
        if (!ok) continue;
        int cost = calc(pe, po);
        cmin(ans, cost);
    }
    ans = ans == INT_MAX ? -1 : ans;
    cout << ans << endl;
}
